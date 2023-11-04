/*
* 프로그램 내용: 1주차 팀별과제 1번
* 개발자: 연승현
* 학번: 202311420 
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    int binary, decimal = 0, digit, i = 0;

    printf("6자리의 2진수 정수를 입력하세요: ");
    scanf("%d", &binary);

    // 입력된 2진수를 10진수로 변환
    while (binary > 0) {
        digit = binary % 10;
        decimal += digit * pow(2, i);
        binary /= 10;
        i++;
    }

    printf("10진수로 변환된 값: %d\n", decimal);

    return 0;
}

// cd /workspace/SeowonCProject/assignment/week1/problem/ && gcc ./1.c -o /tmp/a.out -lm && /tmp/a.out