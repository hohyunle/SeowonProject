/*
* 프로그램 내용: 1주차 팀별과제 5번
* 개발자: 장서진
* 학번: 202311825
* 문제: 섭씨온도를 입력 받아 화씨온도로 변환하여 출력하고, 화씨온도를 입력 받아 섭씨온도로 변환하여 출력하는 프로그램을 작성하세요.
*/

#include <stdio.h>

int main(void) {
    int choice;
    double nconv, conv;

    printf("1. 섭씨에서 화씨로\n");
    printf("2. 화씨에서 섭씨로\n");
    printf("1 또는 2 중에 선택하십시오: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("섭씨 온도를 입력하세요: ");
        scanf("%lf", &nconv);
        conv = (nconv * 9/5) + 32;
        printf("변환된 화씨 온도: %.2lf\n", conv);
    } else if (choice == 2) {
        printf("화씨 온도를 입력하세요: ");
        scanf("%lf", &nconv);
        conv = (nconv - 32) * 5/9;
        printf("변환된 섭씨 온도: %.2lf\n", conv);
    } else {
        printf("잘못된 입력입니다. 1 또는 2 중에 선택하십시오\n");
    }
    return 0;
}
               

// cd /workspace/SeowonCProject/assignment/week1/problem/ && gcc ./5.c -o /tmp/a.out -lm && clear && /tmp/a.out