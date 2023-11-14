// 기본 라이브러리
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "./lib/json.h"
#include "./lib/fs.h"
#define FILE_PATH "./db/ledger.json"

int main(void) {
    char *loadedData = loadFile(FILE_PATH);
    if (loadedData == NULL) return 0;
        // printf("loadFile 함수 결과: %s\n", loadedData);
        // free(loadedData);
    
    // const char* jsonStr = "{\"incomeList\":{\"tag1\":{\"1\":{\"Date\":\"2023.11.09\",\"Price\":\"1000\",\"Origin\":\"편의점\"}},\"tag2\":{\"2\":{\"Date\":\"2023.11.09\",\"Price\":\"1000\",\"Origin\":\"편의점\"}},\"tag3\":{\"3\":{\"Date\":\"2023.11.09\",\"Price\":\"1000\",\"Origin\":\"편의점\"},\"4\":{\"Date\":\"2023.11.09\",\"Price\":\"1000\",\"Origin\":\"편의점\"}}},\"spendList\":{\"tag1\":{\"5\":{\"Date\":\"2023.11.09\",\"Price\":\"1000\",\"수입처\":\"편의점\"}},\"tag2\":{\"6\":{\"Date\":\"2023.11.09\",\"Price\":\"1000\",\"Origin\":\"편의점\"}},\"tag3\":{\"7\":{\"Date\":\"2023.11.09\",\"Price\":\"1000\",\"Origin\":\"편의점\"},\"8\":{\"Date\":\"2023.11.09\",\"Price\":\"1000\",\"Origin\":\"편의점\"}}}}}";

    const char* newData = "{\"Date\":\"2023.11.09\",\"Price\":\"1000\",\"Origin\":\"편의점\"}";

    char* result = addDataList(loadedData, "incomeList", "tag2", 10675, newData);

    printf("변경된 JSON 데이터: %s\n", result);

    free(result);

    return 0;
}


// cd /workspace/SeowonCProject/project/ && gcc ./test.c -o /tmp/a.out -lm -ljson-c && clear && /tmp/a.out