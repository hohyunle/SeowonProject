#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>

char* addDataToJson(char* jsonString) {
    // Parse the input JSON string
    json_object* root = json_tokener_parse(jsonString);

    // Check if parsing was successful
    if (is_error(root)) {
        fprintf(stderr, "Error parsing JSON\n");
        return jsonString;
    }

    // Get the "수입목록" array
    json_object* incomeList = NULL;
    if (!json_object_object_get_ex(root, "수입목록", &incomeList)) {
        // "수입목록" 객체가 없으면 새로 생성
        incomeList = json_object_new_object();
        json_object_object_add(root, "수입목록", incomeList);
    }

    // Create a new entry
    json_object* newEntry = json_object_new_object();
    json_object_object_add(newEntry, "날짜", json_object_new_string("2023-11-09"));
    json_object_object_add(newEntry, "금액", json_object_new_string("5000"));
    json_object_object_add(newEntry, "수입처", json_object_new_string("용돈"));
    json_object_object_add(newEntry, "메모", json_object_new_string("1"));
    json_object_object_add(newEntry, "카테고리", json_object_new_string("tag2"));

    // Generate a unique key for the new entry (e.g., "3")
    int uniqueId = json_object_array_length(incomeList) + 1;
    char key[16];
    snprintf(key, sizeof(key), "%d", uniqueId);

    // Add the new entry to the "수입목록" array
    json_object_object_add(incomeList, key, newEntry);

    // Get the modified JSON string
    const char* modifiedJsonString = json_object_to_json_string_ext(root, JSON_C_TO_STRING_SPACED | JSON_C_TO_STRING_PRETTY);

    // Free the JSON object
    json_object_put(root);

    return modifiedJsonString;
}

int main() {
    char* originalJson = "{\"수입목록\":{\"1\":{\"Date\":\"2023-11-09\",\"금액\":\"2000000\",\"수입처\":\"월급\",\"메모\":\"\",\"카테고리\":\"tag1\"},\"2\":{\"날짜\":\"2023-11-09\",\"금액\":\"5000\",\"수입처\":\"용돈\",\"메모\":\"\",\"카테고리\":\"tag2\"}}}";

    char* modifiedJson = addDataToJson(originalJson);

    printf("Modified JSON: %s\n", modifiedJson);

    return 0;
}





// cd /workspace/SeowonCProject/project/ && gcc ./test2.c -o /tmp/a.out -lm -ljson-c && clear && /tmp/a.out