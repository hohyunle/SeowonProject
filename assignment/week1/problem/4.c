/*
* 프로그램 내용: 1주차 팀별과제 4번
* 개발자: 이정호 (203311431)
* 문제: x의 값(실수)을 입력 받아, 다음 다항식의 값을 계산하는 프로그램을 작성하세요.
   3x3 - 7x2 + x + 7
*/

#include <stdio.h>

int main(void) {
    float x;
    printf("x의 값을 입력하세요: ");
    scanf("%f", &x);

    float result = 3 * 3 - 7 * 2 + x + 7;
    printf("다항식의 값은: %.2f\n", result);

    return 0;
}


// cd /workspace/SeowonCProject/assignment/week1/problem/ && gcc ./4.c -o /tmp/a.out -lm && clear && /tmp/a.out