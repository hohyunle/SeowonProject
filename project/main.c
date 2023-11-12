// 기본 라이브러리
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "./lib/fs.h"

// 매크로 변수
#define FILE_PATH "./db/ledger.json"

int main(void) {
    const char *filename = "./db/ledger.json";
    const char *data = "Hello";
    
    // 파일에 문자열 데이터 저장
    // bool result = saveFile(FILE_PATH, data);
    // printf("saveStringToFile 함수 결과: %d\n", result);

    // 파일에서 문자열 데이터 읽어오기
    
    char *loadedData = loadFile(FILE_PATH);
    if (loadedData != NULL) {
        printf("loadFile 함수 결과: %s\n", loadedData);
        free(loadedData);
    }

    
    return 0;
}

// -ljson-c