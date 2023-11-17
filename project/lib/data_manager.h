#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

// 기본 라이브러리
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "../lib/fs.h"

// 매크로 변수
#define SPEND_LIMIT_FILE_PATH "./db/spendLimit.txt"
#define RECENT_LISTID_FILE_PATH "./db/uniqueNum.txt"

// 함수 목록
int updatelistId(char* listId); 									// 내역 고유번호를 업데이트 및 출력합니다.
char* addIncomeList(char* jsonData, char* HistoryData);				// 수입 내역을 추가합니다.
char* addSpendList(char* jsonData, char* HistoryData);				// 지출 내역을 추가합니다.
int setSpendLimit(char* jsonData, char* spendPrice);				// 지출 한도를 설정합니다.
int getSpendLimit(char* jsonData);									// 지출 내역 현황을 출력합니다.
char* setSpendPromise(char* jsonData, char* HistoryData);			// 지출 예약 내역을 추가합니다.
char* findDate(char* jsonData, char* actList, char* targetDate);	// 수입 및 지출 내역을 날짜로 검색합니다.
char* findTag(char* jsonData, char* actList, char* targetTag);		// 수입 및 지출 내역을 카테고리로 검색합니다.
    

// 내역 고유번호 업데이트 및 출력 (RETURN 새로운 내역 고유번호)
int updatelistId(char* listId) {
    char PushlistId[9999];							// 저장할 내역 고유번호
    int NewlistId = (int)(atoi(listId) + 1);		// 새로운 내역 고유번호
    sprintf(PushlistId, "%d", NewlistId);			// 문자열 변경
    
    saveFile(RECENT_LISTID_FILE_PATH, PushlistId);	// 내역 고유번호 파일 저장
    return NewlistId;
}

// 수입 내역 추가 (RETURN 수정된 데이터)
char* addIncomeList(char* jsonData, char* HistoryData) {
    struct json_object* root;           				// 전체 리스트 내역
    struct json_object* typeList;       				// 수입 | 지출내역
    struct json_object* listInfo;       				// 내역 세부 데이터
    char* listId = loadFile(RECENT_LISTID_FILE_PATH);	// 내역 고유번호
    
    // 기존 JSON 데이터 파싱
    root = json_tokener_parse(jsonData);

    // 새로운 내역 데이터 파싱
    listInfo = json_tokener_parse(HistoryData);

    // "수입목록" 객체 가져오기
    json_object_object_get_ex(root, "수입목록", &typeList);

    // "수입목록" 객체에 새로운 데이터 추가
    json_object_object_add(typeList, listId, listInfo);
    
    // 수정된 JSON 데이터 저장
    char *result = strdup(json_object_to_json_string(root));
    
    // 메모리 누수 방지
    json_object_put(root);
    updatelistId(listId);
    return result;
}

// 지출 내역 추가 (RETURN 수정된 데이터)
char* addSpendList(char* jsonData, char* HistoryData) {
    struct json_object* root;           				// 전체 리스트 내역
    struct json_object* typeList;       				// 수입 | 지출내역
    struct json_object* listInfo;       				// 내역 세부 데이터
    char* listId = loadFile(RECENT_LISTID_FILE_PATH);	// 내역 고유번호
    
    // 기존 JSON 데이터 파싱
    root = json_tokener_parse(jsonData);

    // 새로운 내역 데이터 파싱
    listInfo = json_tokener_parse(HistoryData);

    // "지출목록" 객체 가져오기
    json_object_object_get_ex(root, "지출목록", &typeList);

    // "지출목록" 객체에 새로운 데이터 추가
    json_object_object_add(typeList, listId, listInfo);
    
    // 수정된 JSON 데이터 저장
    char *result = strdup(json_object_to_json_string(root));
    
    // 메모리 누수 방지
    json_object_put(root);
    updatelistId(listId);
    return result;
}

// 지출 한도 설정 (RETURN 지출한도금액 - 총지출액)
int setSpendLimit(char* jsonData, char* spendPrice) {
    struct json_object* root;           // 전체 리스트 내역
    struct json_object* typeList;       // 수입 | 지출내역
    int totalPrice = 0;                 // 총지출액
    
    // 지출 한도 저장
    saveFile(SPEND_LIMIT_FILE_PATH, spendPrice);
    
    // 기존 JSON 데이터 파싱
    root = json_tokener_parse(jsonData);

    // "지출목록" 객체 가져오기
    json_object_object_get_ex(root, "지출목록", &typeList);
    if (typeList == NULL) {
        printf("Error: '지출목록'을 찾을 수 없습니다.\n");
        // 메모리 누수 방지
        json_object_put(root);
        return -1;  // 오류를 나타내는 값 반환
    }
    
    // 각 내역의 "금액" 항목을 모두 더하기
    json_object_object_foreach(typeList, key, value) {
        struct json_object *getPrice;
        if (json_object_object_get_ex(value, "금액", &getPrice)) {
            totalPrice += json_object_get_int(getPrice);
        }
    }
    
    int result = (int)(atoi(spendPrice) - totalPrice);
    // 메모리 누수 방지
    json_object_put(root);
    return result;
}

// 지출 내역 현황 출력 (RETURN 지출한도금액 - 총지출액)
int getSpendLimit(char* jsonData) {
    struct json_object* root;           // 전체 리스트 내역
    struct json_object* typeList;       // 수입 | 지출내역
    int totalPrice = 0;                 // 총지출액
    
    // 지출 한도 저장
    char* spendPrice = loadFile(SPEND_LIMIT_FILE_PATH);
    
    // 기존 JSON 데이터 파싱
    root = json_tokener_parse(jsonData);

    // "지출목록" 객체 가져오기
    json_object_object_get_ex(root, "지출목록", &typeList);
    if (typeList == NULL) {
        printf("Error: '지출목록'을 찾을 수 없습니다.\n");
        // 메모리 누수 방지
        json_object_put(root);
        return -1;  // 오류를 나타내는 값 반환
    }
    
    // 각 내역의 "금액" 항목을 모두 더하기
    json_object_object_foreach(typeList, key, value) {
        struct json_object *getPrice;
        if (json_object_object_get_ex(value, "금액", &getPrice)) {
            totalPrice += json_object_get_int(getPrice);
        }
    }
    
    int result = (int)(atoi(spendPrice) - totalPrice);
    // 메모리 누수 방지
    json_object_put(root);
    return result;
}

// 지출 예약 내역 추가 (RETURN 수정된 데이터)
char* setSpendPromise(char* jsonData, char* HistoryData) {
    struct json_object* root;           				// 전체 리스트 내역
    struct json_object* typeList;       				// 수입 | 지출내역
    struct json_object* listInfo;       				// 내역 세부 데이터
    char* listId = loadFile(RECENT_LISTID_FILE_PATH);	// 내역 고유번호
    
    // 기존 JSON 데이터 파싱
    root = json_tokener_parse(jsonData);

    // 새로운 내역 데이터 파싱
    listInfo = json_tokener_parse(HistoryData);

    // "지출예약목록" 객체 가져오기
    json_object_object_get_ex(root, "지출예약목록", &typeList);

    // "지출예약목록" 객체에 새로운 데이터 추가
    json_object_object_add(typeList, listId, listInfo);
    
    // 수정된 JSON 데이터 저장
    char *result = strdup(json_object_to_json_string(root));
    
    // 메모리 누수 방지
    json_object_put(root);
    updatelistId(listId);
    return result;
}

// 내역 날짜 검색
char* findDate(char* jsonData, char* actList, char* targetDate) {
    struct json_object* root = json_tokener_parse(jsonData);

    // "지출|수입 목록" 객체 가져오기
    struct json_object* typeList;
    if (json_object_object_get_ex(root, actList, &typeList)) {
        size_t resultLength = 1; // 결과 문자열 길이 (초기값 1)
        char* result = (char*)malloc(resultLength);
        result[0] = '\0'; // 문자열 초기화

        // 각 내역의 "날짜" 항목을 확인하여 필터링
        json_object_object_foreach(typeList, key, value) {
            struct json_object* dateObj;
            if (json_object_object_get_ex(value, "날짜", &dateObj)) {
                const char* date = json_object_get_string(dateObj);

                // 날짜가 targetDate로 시작하는 경우에만 문자열에 추가
                if (strncmp(date, targetDate, strlen(targetDate)) == 0) {
                    // 필요한 문자열 길이 계산
                    size_t keyLength = strlen(key);
                    size_t dateLength = strlen(date);
                    size_t infoLength = json_object_object_length(value) * 50; // 예상되는 정보 길이

                    // 동적으로 메모리 재할당하여 문자열 길이 늘리기
                    resultLength += keyLength + dateLength + infoLength;
                    result = (char*)realloc(result, resultLength);

                    // 문자열에 정보 추가
                    sprintf(result + strlen(result), "내역 고유번호: %s\n", key);

                    // 기타 필요한 정보 추가
                    json_object_object_foreach(value, innerKey, innerValue) {
                        // "날짜" 항목은 추가하지 않도록 처리
                        // if (strcmp(innerKey, "날짜") != 0) {
                        //     sprintf(result + strlen(result), "%s: %s\n", innerKey, json_object_get_string(innerValue));
                        // }
                        sprintf(result + strlen(result), "%s: %s\n", innerKey, json_object_get_string(innerValue));
                    }

                    strcat(result, "\n"); // 줄바꿈 추가
                }
            }
        }

        json_object_put(root);
        return result;
    } else {
        printf("지출목록을 찾을 수 없습니다.\n");
        json_object_put(root);
        return NULL;
    }
}

// 내역 카테고리 검색
char* findTag(char* jsonData, char* actList, char* targetTag) {
    struct json_object* root = json_tokener_parse(jsonData);

    // "지출|수입 목록" 객체 가져오기
    struct json_object* typeList;
    if (json_object_object_get_ex(root, actList, &typeList)) {
        size_t resultLength = 1; // 결과 문자열 길이 (초기값 1)
        char* result = (char*)malloc(resultLength);
        result[0] = '\0'; // 문자열 초기화

        // 각 내역의 "카테고리" 항목을 확인하여 필터링
        json_object_object_foreach(typeList, key, value) {
            struct json_object* tagObj;
            if (json_object_object_get_ex(value, "카테고리", &tagObj)) {
                const char* tag = json_object_get_string(tagObj);

                // 카테고리가 targetTag로 시작하는 경우에만 문자열에 추가
                if (strncmp(tag, targetTag, strlen(targetTag)) == 0) {
                    // 필요한 문자열 길이 계산
                    size_t keyLength = strlen(key);
                    size_t tagLength = strlen(tag);
                    size_t infoLength = json_object_object_length(value) * 50; // 예상되는 정보 길이

                    // 동적으로 메모리 재할당하여 문자열 길이 늘리기
                    resultLength += keyLength + tagLength + infoLength;
                    result = (char*)realloc(result, resultLength);

                    // 문자열에 정보 추가
                    sprintf(result + strlen(result), "내역 고유번호: %s\n", key);

                    // 기타 필요한 정보 추가
                    json_object_object_foreach(value, innerKey, innerValue) {
                        // "날짜" 항목은 추가하지 않도록 처리
                        // if (strcmp(innerKey, "날짜") != 0) {
                        //     sprintf(result + strlen(result), "%s: %s\n", innerKey, json_object_get_string(innerValue));
                        // }
                        sprintf(result + strlen(result), "%s: %s\n", innerKey, json_object_get_string(innerValue));
                    }
                    strcat(result, "\n"); // 줄바꿈 추가
                }
            }
        }
        json_object_put(root);
        return result;
    } else {
        printf("지출목록을 찾을 수 없습니다.\n");
        json_object_put(root);
        return NULL;
    }
}


#endif // DATA_MANAGER_H