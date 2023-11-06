/*
* 프로그램 내용: 1주차 팀별과제 2번
* 개발자: 김예은
* 학번: 202010319
* 문제: 한 자리수의 10진수를 입력 받아, 2진수로 변환하여 출력하는 프로그램을 작성하세요.
*/

#include <stdio.h>

int main(void) {
    int decimal;
    int binary[32];  // 32비트 이하의 정수를 다루기 위한 배열
    int i = 0;

    printf("10진수를 입력하세요: ");
    scanf("%d", &decimal); // 사용자로부터 10진수 입력 받음

    if (decimal == 0) {
        printf("이진수: 0\n"); // 입력이 0인 경우에는 2진수가 0이므로 바로 출력
        return 0;
    }

    while (decimal > 0) {
        binary[i] = decimal % 2; // 2로 나눈 나머지를 이진수 배열에 저장
        decimal /= 2; // 2로 나눈 몫을 새로운 10진수로 설정
        i++; // 배열 인덱스 증가
    }

    printf("이진수: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]); // 배열에 저장된 2진수 비트를 역순으로 출력
    }
    printf("\n");
    return 0;
}



// cd /workspace/SeowonCProject/assignment/week1/problem/ && gcc ./2.c -o /tmp/a.out -lm && clear && /tmp/a.out