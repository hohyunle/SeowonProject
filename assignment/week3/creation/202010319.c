/*
* 프로그램 내용: 로또 번호 맞히기 시뮬레이션 프로그램 (창작 문제)
* 개발자: 김예은 (202010319)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOTTO_SIZE 6  // 로또 번호 개수

void generateLottoNumbers(int lottoNumbers[]);
int compareNumbers(int userNumbers[], int lottoNumbers[]);

int main() {
    printf("로또번호 맞히기 프로그램\n");

    srand((unsigned)time(NULL));

    int lottoNumbers[LOTTO_SIZE];
    generateLottoNumbers(lottoNumbers);

    int tryCount = 0;
    int userNumbers[LOTTO_SIZE];

    while (1) {
        tryCount++;
        printf("%d번째 시도\n", tryCount);

        printf("숫자 입력 : ");
        for (int i = 0; i < LOTTO_SIZE; i++) {
            scanf("%d", &userNumbers[i]);
        }

        // 입력한 숫자가 0이면 종료
        if (userNumbers[0] == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        // 입력한 숫자와 생성된 로또 번호 비교
        int matchedCount = compareNumbers(userNumbers, lottoNumbers);

        // 결과 출력
        printf("결과 : %d개 중 %d개가 일치합니다.\n", LOTTO_SIZE, matchedCount);

        // 모두 일치하면 당첨 메시지 출력
        if (matchedCount == LOTTO_SIZE) {
            printf("축하합니다. 1등 당첨입니다.\n");
            break;
        }
    }

    return 0;
}

// 1부터 45까지의 숫자 중 6개를 생성
void generateLottoNumbers(int lottoNumbers[]) {
    for (int i = 0; i < LOTTO_SIZE; i++) {
        lottoNumbers[i] = rand() % 45 + 1;  // 1부터 45까지의 난수 생성
    }
}

// 사용자가 입력한 숫자와 로또 번호를 비교하여 일치하는 개수를 반환
int compareNumbers(int userNumbers[], int lottoNumbers[]) {
    int matchedCount = 0;
    for (int i = 0; i < LOTTO_SIZE; i++) {
        for (int j = 0; j < LOTTO_SIZE; j++) {
            if (userNumbers[i] == lottoNumbers[j]) {
                matchedCount++;
                break;
            }
        }
    }
    return matchedCount;
}


// cd /workspace/SeowonCProject/assignment/week3/creation/ && gcc ./202010319.c -o /tmp/a.out -lm && clear && /tmp/a.out