/*
* 프로그램 내용: 10진수 정수를 키보드로부터 입력 받아, 16진수로 변환하여 출력하는 프로그램을 작성하세요. (창작 문제)
* 개발자: 연승현
* 학번: 202311420
*/

#include <stdio.h>

int main() {
    int dword;

    printf("10진수 정수를 입력하세요: ");
    scanf("%d", &dword);

    printf("16진수로 변환된 값: %06X\n", dword);
    return 0;
}


// cd /workspace/SeowonCProject/assignment/week1/creation/ && gcc ./202311420.c -o /tmp/a.out -lm && clear && /tmp/a.out