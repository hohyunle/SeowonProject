#ifndef JSON_H
#define JSON_H

// 기본 라이브러리
#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "../lib/fs.h"

// 매크로 변수
#define SPEND_LIMIT_FILE_PATH "./db/spendLimit.txt"
#define RECENT_LISTID_FILE_PATH "./db/uniqueNum.txt"

// 수입 내역 추가 (RETURN 수정된 데이터)
char* addIncomeList(char* jsonData, char* listId, char* HistoryData) {
    struct json_object* root;           // 전체 리스트 내역
    struct json_object* typeList;       // 수입 | 지출내역
    struct json_object* listInfo;       // 내역 세부 데이터
    
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
    return result;
}

// 지출 내역 추가 (RETURN 수정된 데이터)
char* addSpendList(char* jsonData, char* listId, char* HistoryData) {
    struct json_object* root;           // 전체 리스트 내역
    struct json_object* typeList;       // 수입 | 지출내역
    struct json_object* listInfo;       // 내역 세부 데이터
    
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
    return result;
}

// 지출 내역 추가 (RETURN 지출한도금액 - 총지출액)
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

// 지출 내역 알림 (RETURN 지출한도금액 - 총지출액)
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

// 지출 내역 추가 (RETURN 수정된 데이터)
char* setSpendPromise(char* jsonData, char* listId, char* HistoryData) {
    struct json_object* root;           // 전체 리스트 내역
    struct json_object* typeList;       // 수입 | 지출내역
    struct json_object* listInfo;       // 내역 세부 데이터
    
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
    return result;
}

char* findDate(char* jsonData, char* date) {
        struct json_object *root = json_tokener_parse(jsonData);

    // "지출목록" 객체 가져오기
    struct json_object *spendList;
    if (json_object_object_get_ex(root, "지출목록", &spendList)) {
        printf("2023-11에 해당하는 데이터:\n");

        // 각 내역의 "날짜" 항목을 확인하여 필터링
        json_object_object_foreach(spendList, key, value) {
            struct json_object *dateObj;
            if (json_object_object_get_ex(value, "날짜", &dateObj)) {
                const char *date = json_object_get_string(dateObj);

                // 날짜가 2023-11로 시작하는 경우에만 출력
                if (strstr(date, targetMonth) == date) {
                    printf("Key: %s\n", key);
                    printf("날짜: %s\n", date);
                    
                    // 기타 필요한 정보 출력
                    // 예를 들면 "금액", "지출처" 등
                    
                    printf("\n");
                }
            }
        }
    } else {
        printf("지출목록을 찾을 수 없습니다.\n");
    }

    json_object_put(root);
}


#endif // JSON_H