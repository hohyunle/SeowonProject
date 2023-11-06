/*
* 프로그램 내용: 1주차 팀별과제 6번
* 개발자: 이호현
* 학번: 202311437
* 문제: 네 개의 문자를 각각 입력 받아, 하나의 정수 변수에 저장한 다음, 다시 저장된 변수에서 다시 문자를 추출하여 출력하는 프로그램을 작성하세요.
*/

#include <stdio.h>

int main(void)
{
    int ascode[4];
    int i;
    for (i = 0; i < 4; i++) {
        printf("%d번째 정수를 입력하시오 : ", i + 1);
        scanf("%d", &ascode[i]);
    }
    for (i = 0; i < 4; i++)
        printf("%d", ascode[i]);

    return 0;
}





// cd /workspace/SeowonCProject/assignment/week1/problem/ && gcc ./6.c -o /tmp/a.out -lm && clear && /tmp/a.out