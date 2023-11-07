/*
* 프로그램 내용: 두 정수를 입력받고 합을 출력하는 프로그램 (창작 문제)
* 개발자: 김지성 (202110343)
*/

#include <stdio.h>

int main() {
    int num1, num2, sum;

    printf("첫번째 정수를 입력하세요 : ");
    scanf("%d", &num1);

    printf("두번째 정수를 입력하세요 : ");
    scanf("%d",&num2);

    sum = num1 + num2;

    printf("두 정수의 합은 %d입니다.\n", sum);

    return 0;
}

// cd /workspace/SeowonCProject/assignment/week1/creation/ && gcc ./202110343.c -o /tmp/a.out -lm && clear && /tmp/a.out