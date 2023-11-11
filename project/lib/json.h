#include <stdio.h>
#include <json-c/json.h>

// 내역 고유번호로 검색해 결과 리턴
json_object* searchEntryByUniqueId(const char *jsonData, const char *action, int uniqueId) {
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

    // "수입리스트" 객체 가져오기
    json_object *incomeList;
    if (!json_object_object_get_ex(root, "수입리스트", &incomeList) || !json_object_is_type(incomeList, json_type_object)) {
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
