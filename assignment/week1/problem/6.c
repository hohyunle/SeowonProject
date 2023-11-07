/*
* 프로그램 내용: 1주차 팀별과제 6번
* 개발자: 이호현 (202311437)
* 문제: 네 개의 문자를 각각 입력 받아, 하나의 정수 변수에 저장한 다음, 다시 저장된 변수에서 다시 문자를 추출하여 출력하는 프로그램을 작성하세요.
*/

#include <stdio.h>

int main(void)
{
    char char1, char2, char3, char4;
    int number;

    printf("첫 번째 정수를 입력하시오 : ");
    scanf("%c", &char1);
    printf("두 번째 정수를 입력하시오 : ");
    scanf(" %c", &char2);
    printf("세 번째 정수를 입력하시오 : ");
    scanf(" %c", &char3);
    printf("네 번째 정수를 입력하시오 : ");
    scanf(" %c", &char4);

    if (char1 >= '0' && char1 <= '9') {
        number = (char1 - '0');
    }
    if (char2 >= '0' && char2 <= '9') {
        number = number * 10 + (char2 - '0');
    }
    if (char3 >= '0' && char3 <= '9') {
        number = number * 10 + (char3 - '0');
    }
    if (char4 >= '0' && char4 <= '9') {
        number = number * 10 + (char4 - '0');
    }

    printf("%d\n", number);

    return 0;
}





// cd /workspace/SeowonCProject/assignment/week1/problem/ && gcc ./6.c -o /tmp/a.out -lm && clear && /tmp/a.out