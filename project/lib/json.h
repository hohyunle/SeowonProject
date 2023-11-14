#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>


// JSON 데이터를 합치는 함수
char* addIncomeList(char* jsonData, char* actionList, char* listId, char* HistoryData) {
    struct json_object* root;           // 전체 리스트 내역
    struct json_object* typeList;       // 수입 | 지출내역
    struct json_object* listInfo;       // 내역 세부내용
    char *result;
    
    // char listId[9999];                 // 고유번호 문자열 전환
    // snprintf(listId, sizeof(listId), "%d", uniqueId);
    
    // 기존 JSON 데이터 파싱
    root = json_tokener_parse(jsonData);

    // 새로운 내역 데이터 파싱
    listInfo = json_tokener_parse(HistoryData);

    // "수입목록" 객체 가져오기
    json_object_object_get_ex(root, actionList, &typeList);

    // "수입목록" 객체에 새로운 데이터 추가
    json_object_object_add(typeList, listId, listInfo);

    // 합쳐진 JSON 데이터 반환
    // const char* mergedJsonData = json_object_to_json_string_ext(root, JSON_C_TO_STRING_PLAIN);
    // char *result = strdup(mergedJsonData);
    
    result = strdup(json_object_to_json_string(root));
    // 메모리 정리
    // json_object_put(root);
    // free(root);
    return result;
}

// 가계부 리스트 내역 추가
char* addDataList(const char* jsonData, const char *actionList, const char *tagtype, int uniqueId, const char* HistoryData) {
    struct json_object* root;
    struct json_object* typeList;
    struct json_object* tag;
    struct json_object* newHistory;
    
    char* result;
    char *listId = NULL;
    sprintf(listId, "%d", uniqueId);
    
    // JSON 문자열을 파싱하여 JSON 객체 생성
    root = json_tokener_parse(jsonData);

    // actionList 객체 획득
    json_object_object_get_ex(root, actionList, &typeList);

    // tagtype 객체 획득
    json_object_object_get_ex(typeList, tagtype, &tag);

    // 새로운 데이터를 JSON 형식으로 변환하여 newHistory 객체 생성
    newHistory = json_tokener_parse(HistoryData);

    // tagtype 객체에 새로운 데이터 추가
    json_object_object_add(tag, listId, newHistory);

    // JSON 객체를 문자열로 변환하여 결과 반환
    result = strdup(json_object_to_json_string(root));

    // JSON 객체 및 할당된 메모리 해제
    json_object_put(root);
    free(newHistory);
    return result;
}
