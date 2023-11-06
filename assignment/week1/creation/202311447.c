/*
* 프로그램 내용: 숫자 3개와 문자 3개를 출력하는 프로그램을 만드시오. (창작 문제)
* 개발자: 홍정일
* 학번: 202311447
*/


#include <stdio.h>

int main(void) {
    
    int num1 = 123;
    int num2 = 456;
    int num3 = 789;
    char ch1 = 'X';
    char ch2 = 'Y';
    char ch3 = 'Z';

    printf("Numbers: %d %d %d,\n", num1, num2, num3);
    printf("Characters: '%c', '%c', '%c'\n", ch1, ch2, ch3);
    
    return 0;
}


// cd /workspace/SeowonCProject/assignment/week1/creation/ && gcc ./202311447.c -o /tmp/a.out -lm && clear && /tmp/a.out