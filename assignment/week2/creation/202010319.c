/*
* 프로그램 내용: 한 자리수의 10진수를 입력 받아, 8진수로 변환하여 출력하는 프로그램을 작성하세요. (창작 문제)
* 개발자: 김예은 (202010319)
*/

#include <stdio.h>

int main(void) {
    int decimal;
    int octal[32];  // 32비트 이하의 정수를 다루기 위한 배열
    int i = 0;

    printf("10진수를 입력하세요: ");
    scanf("%d", &decimal); // 사용자로부터 10진수 입력 받음

    if (decimal == 0) {
        printf("8진수: 0\n"); // 입력이 0인 경우에는 8진수가 0이므로 바로 출력
        return 0;
    }

    while (decimal > 0) {
        octal[i] = decimal % 8; // 8로 나눈 나머지를 8진수 배열에 저장
        decimal /= 8; // 8로 나눈 몫을 새로운 10진수로 설정
        i++; // 배열 인덱스 증가
    }

    printf("8진수: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]); // 배열에 저장된 8진수 자릿수를 역순으로 출력
    }
    printf("\n");

    return 0;
}


// cd /workspace/SeowonCProject/assignment/week1/creation/ && gcc ./202010319.c -o /tmp/a.out -lm && clear && /tmp/a.out