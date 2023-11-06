/*
* 프로그램 내용: 1주차 팀별과제 1번
* 개발자: 연승현
* 학번: 202311420 
* 문제: 6자리수의 2진수 정수를 키보드로부터 입력 받아, 10진수로 변환하여 출력하는 프로그램을 작성하세요. 
*/

#include <stdio.h>

int main() {
    int binary;
    int dword = 0;
    int power = 1;

    printf("6자리의 2진수 정수를 입력하세요: ");
    scanf("%d", &binary);

    // 2진수를 10진수로 변환
    while (binary > 0) {
        int remainder = binary % 10;
        dword += remainder * power;
        power *= 2;
        binary /= 10;
    }

    printf("10진수로 변환된 값: %d\n", dword);
    return 0;
}






// cd /workspace/SeowonCProject/assignment/week1/problem/ && gcc ./1.c -o /tmp/a.out -lm && clear && /tmp/a.out