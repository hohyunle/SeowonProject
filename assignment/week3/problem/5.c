/*
* 프로그램 내용: 3주차 팀별과제 5번
* 개발자: 김예은(202010319)
* 문제: 이 게임은 투수와 타자 두 명이 한 조가 되어 번갈아가며 서로의 숫자를 알아내는 게임으로 이 게임에서 투수는 1부터 9 사이의 중복되지 않는 임의의 숫자 3개를 미리 정해 놓고, 타자 는 투수가 만들어 놓은 3개의 숫자와 정확한 순서를 알아맞힐 때까지 계속한다. 이때 투수 는 자신이 만들어 놓은 숫자 3개와 타자가 제시한 3개의 숫자를 비교하여 타자에게 strike 과 ball의 숫자를 알려줘야 한다. 여기서 strike의 수는 타자가 해당 위치의 숫자를 정확히 맞힌 개수를 나타내고, ball의 수는 타자가 제시한 숫자 중에서 맞은 숫자가 있으나 위치가 다른 개수를 나타낸다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("숫자야구게임 프로그램\n");

    // 랜덤 시드 설정
    srand((unsigned)time(NULL));

    // 투수의 숫자 3개 생성
    int pitcher[3];
    for (int i = 0; i < 3; ++i) {
        pitcher[i] = rand() % 10;  // 0부터 9까지의 랜덤 숫자
    }

    int tryCount = 0;

    while (1) {
        tryCount++;
        printf("%d번째 시도\n", tryCount);

        // 타자(사용자)의 숫자 3개 입력
        int batter[3];
        printf("숫자 입력 : ");
        scanf("%d %d %d", &batter[0], &batter[1], &batter[2]);

        // 입력한 숫자가 0이면 종료
        if (batter[0] == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        // 결과 계산
        int strike = 0, ball = 0;
        for (int i = 0; i < 3; ++i) {
            if (batter[i] == pitcher[i]) {
                strike++;
            }
            else {
                for (int j = 0; j < 3; ++j) {
                    if (i != j && batter[i] == pitcher[j]) {
                        ball++;
                        break;
                    }
                }
            }
        }

        // 결과 출력
        printf("결과 : %d strike, %d ball\n", strike, ball);

        // 정답을 맞추면 종료
        if (strike == 3) {
            printf("축하합니다! 정답을 맞추셨습니다.\n");
            break;
        }
    }
    return 0;
}





// cd /workspace/SeowonCProject/assignment/week3/problem/ && gcc ./5.c -o /tmp/a.out -lm && clear && /tmp/a.out