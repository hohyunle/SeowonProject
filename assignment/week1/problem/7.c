/*
* 프로그램 내용: 1주차 팀별과제 7번
* 개발자: 홍정일 (202311447)
* 문제: 다음과 같이 출력하는 프로그램을 작성하세요.
   “ASCII code:, 'A', 'B', 'C',
    %d %c %s
*/

#include <stdio.h>

int main(void) {
    
    char characterA = 'A';
    char characterB = 'B';
    char characterC = 'C';

    printf("ASCII code: '%c' '%c' '%c' \n", characterA, characterB, characterC);
    printf("%%d %%c %%s\n");
    
    return 0;
}

// cd /workspace/SeowonCProject/assignment/week1/problem/ && gcc ./7.c -o /tmp/a.out -lm && clear && /tmp/a.out