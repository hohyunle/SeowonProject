#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>


// 가계부 리스트 내역 추가
char* addDataList(const char* jsonData, const char *actionList, const char *tagtype, int uniqueId, const char* HistoryData) {
    struct json_object* root;           // jsonData
    struct json_object* typeList;       // actionList
    struct json_object* tag;            // tagtype
    struct json_object* newHistory;     // HistoryData
    
    char* result;                       // 수정된 Json
    char listId[99999];                 // 고유번호 문자열 전환
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
    json_object_put(newHistory);
    free(newHistory);
    return result;
}

