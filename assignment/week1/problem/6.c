/*
* 프로그램 내용: 1주차 팀별과제 6번
* 개발자: 이호현 (202311437)
* 문제: 네 개의 문자를 각각 입력 받아, 하나의 정수 변수에 저장한 다음, 다시 저장된 변수에서 다시 문자를 추출하여 출력하는 프로그램을 작성하세요.
*/

#include <stdio.h>

int main(void)
{
    char a, b, c, d;						// 입력받을 4개의 변수를 저장하는 변수
    int num = 0;							// 하나로 저장할 정수 변수

    printf("문자 입력(띄어쓰기로 구분) >> ");	
    scanf("%c %c %c %c", &a, &b, &c, &d);	// 문자 4개 입력받기

    // num 변수를 8비트(1바이트)씩 왼쪽으로 저장한 후, a 변수와 비트 OR 연산을 수행하여 num에 결합 (`b`, `c`, `d` 포함)
    num = (num << 8) | a;
    num = (num << 8) | b;
    num = (num << 8) | c;
    num = (num << 8) | d;

    printf("입력한 문자 >> %c%c%c%c\n", (num>>24), (num>>16), (num>>8), num);

    return 0;
}






// cd /workspace/SeowonCProject/assignment/week1/problem/ && gcc ./6.c -o /tmp/a.out -lm && clear && /tmp/a.out