/*
* 프로그램 내용: 두 수의 합을 계산하는 함수 (창작 문제)
* 개발자: 김지성 (202110343)
*/

#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int num1 = 5;
    int num2 = 3;

    int result = add(num1, num2);
    printf("두 수의 합: %d\n", result);

    return 0;
}

// cd /workspace/SeowonCProject/assignment/week2/creation/ && gcc ./202110343.c -o /tmp/a.out -lm && clear && /tmp/a.out