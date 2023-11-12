#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>


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


// 내역 고유번호로 검색해 결과 리턴
json_object* searchByUniqueId(const char *jsonData, const char *actionList, int uniqueId) {
    // 고유번호 미지정 시 오류 리턴
    if (uniqueId == NULL) {
        printf("JSON 데이터를 파싱할 수 없습니다.\n");
        return NULL;
    }

    char *listId = NULL;
    sprintf(listId, "%d", uniqueId);
        
    // JSON 데이터 파싱
    json_object *root = json_tokener_parse(jsonData);
    if (root == NULL) {
        printf("JSON 데이터를 파싱할 수 없습니다.\n");
        return NULL;
    }

    // action (incomeList | spendList) 객체 가져오기
    json_object *incomeList;
    if (!json_object_object_get_ex(root, actionList, &incomeList) || !json_object_is_type(incomeList, json_type_object)) {
        printf("수입리스트 객체를 찾을 수 없습니다.\n");
        json_object_put(root);
        return NULL;
    }

    // 내역 고유번호에 해당하는 객체 검색
    json_object *resultObj = NULL;
    json_object_object_foreach(incomeList, key, value) {
        json_object *tagObj = value;
        json_object_object_foreach(tagObj, entryId, entryObj) {
            if (strcmp(entryId, listId) == 0) {
                resultObj = entryObj;
                break;
            }
        }
        if (resultObj != NULL) {
            break;
        }
    }

    // 결과 반환
    if (resultObj != NULL) {
        json_object_get(resultObj); // 결과 객체의 참조 횟수 증가
    } else {
        printf("내역 고유번호에 해당하는 객체를 찾을 수 없습니다.\n");
    }

    // 메모리 해제
    json_object_put(root);
    return resultObj;
}
