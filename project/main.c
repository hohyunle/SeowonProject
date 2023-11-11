#include <stdio.h>
#include <stdbool.h>
#include <json-c/json.h>
#include <string.h>
#include "./lib/fs.h"

int main(void) {
    const char *filename = "./db/ledger.json";
    const char *data = "Hello, World!";

    // 파일에 문자열 데이터 저장
    // int result = saveStringToFile(filename, data);
    // printf("saveStringToFile 함수 결과: %d\n", result);

    // 파일에서 문자열 데이터 읽어오기
    char *loadedData = loadData(filename);
    if (loadedData != NULL) {
        printf("loadStringFromFile 함수 결과: %s\n", loadedData);
        free(loadedData);
    }

    return 0;
}