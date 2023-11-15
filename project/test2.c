#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <json-c/json.h>

char* filterDataByMonth(const char* jsonData, const char* targetMonth) {
    struct json_object* root = json_tokener_parse(jsonData);

    // "지출목록" 객체 가져오기
    struct json_object* spendList;
    if (json_object_object_get_ex(root, "지출목록", &spendList)) {
        size_t resultLength = 1; // 결과 문자열 길이 (초기값 1)
        char* result = (char*)malloc(resultLength);
        result[0] = '\0'; // 문자열 초기화

        // 각 내역의 "날짜" 항목을 확인하여 필터링
        json_object_object_foreach(spendList, key, value) {
            struct json_object* dateObj;
            if (json_object_object_get_ex(value, "날짜", &dateObj)) {
                const char* date = json_object_get_string(dateObj);

                // 날짜가 targetMonth로 시작하는 경우에만 문자열에 추가
                if (strncmp(date, targetMonth, strlen(targetMonth)) == 0) {
                    // 필요한 문자열 길이 계산
                    size_t keyLength = strlen(key);
                    size_t dateLength = strlen(date);
                    size_t infoLength = json_object_object_length(value) * 50; // 예상되는 정보 길이

                    // 동적으로 메모리 재할당하여 문자열 길이 늘리기
                    resultLength += keyLength + dateLength + infoLength;
                    result = (char*)realloc(result, resultLength);

                    // 문자열에 정보 추가
                    sprintf(result + strlen(result), "내역 고유번호: %s\n날짜: %s\n", key, date);

                    // 기타 필요한 정보 추가
                    json_object_object_foreach(value, innerKey, innerValue) {
                        // "날짜" 항목은 추가하지 않도록 처리
                        if (strcmp(innerKey, "날짜") != 0) {
                            sprintf(result + strlen(result), "%s: %s\n", innerKey, json_object_get_string(innerValue));
                        }
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



int main() {
    const char *jsonData = "{\"지출목록\":{\"3\":{\"날짜\":\"2023-11-09\",\"금액\":\"1000\",\"지출처\":\"편의점\",\"메모\":\"\",\"카테고리\":\"tag1\"},\"4\":{\"날짜\":\"2023-12-09\",\"금액\":\"5000\",\"지출처\":\"편의점\",\"메모\":\"\",\"카테고리\":\"tag2\"}}}";

    char *result = filterDataByMonth(jsonData, "2023-11");

    if (result != NULL) {
        printf("%s", result);

        // 사용이 끝났으면 메모리 해제
        free(result);
    }

    return 0;
}




// cd /workspace/SeowonCProject/project/ && gcc ./test2.c -o /tmp/a.out -lm -ljson-c && clear && /tmp/a.out