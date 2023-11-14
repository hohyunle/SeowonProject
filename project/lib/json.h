#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>



// 가계부 리스트 내역 추가
char* addIncomeList(const char* jsonData, char* actionList, int uniqueId, const char* HistoryData) {
    struct json_object* root;           // 전체 리스트 내역
    struct json_object* typeList;       // 수입 | 지출내역
    struct json_object* listInfo;       // 내역 세부내용
    
    // char* result;                    // 수정 및 리턴할 Json
    char listId[99999];                 // 고유번호 문자열 전환
    sprintf(listId, "%d", uniqueId);
    
    // JSON 문자열을 파싱하여 JSON 객체 생성
    root = json_tokener_parse(jsonData);

    // 수입 | 지출내역 객체 획득
    json_object_object_get_ex(root, actionList, &typeList);

    // 새로운 데이터를 JSON 형식으로 변환하여 listInfo 객체 생성
    listInfo = json_tokener_parse(HistoryData);

    // typeList 객체에 새로운 데이터 추가
    json_object_object_add(typeList, listId, listInfo);

    // JSON 객체를 문자열로 변환하여 결과 반환
    char *result = strdup(json_object_to_json_string(root));

    // JSON 객체 및 할당된 메모리 해제
    json_object_put(root);
    json_object_put(listInfo);
    free(listInfo);
    free(typeList);
    return result;
}

