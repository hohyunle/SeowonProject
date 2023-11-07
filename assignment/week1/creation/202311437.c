/*
* 프로그램 내용: 정수를 입력받아 팩토리얼 구하기 (창작 문제)
* 개발자: 이호현 (202311437)
*/

#include <stdio.h>

int main(void) 
{
	int num;
	int factorial = 1;

	printf("구할 숫자를 입력하시오 : ");
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
		factorial *= i;

	printf("팩토리얼 : %d", factorial);
    return 0;
}

// cd /workspace/SeowonCProject/assignment/week1/creation/ && gcc ./202311437.c -o /tmp/a.out -lm && clear && /tmp/a.out