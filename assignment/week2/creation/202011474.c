/*
* 프로그램 내용: 가위바위보 게임  (창작 문제)
* 개발자: 정희태 (202011474)
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	srand(time(NULL));
	int my,com;
	printf("가위:1 바위:2 보:3 중에서 하나를 고르시오");
	scanf("%d", &my);
	
	com = (rand() % 3 + 1);
	if (my == com)
		printf("비겼습니다");

	else if (my == 1 && com == 2 || my == 2 && com == 3 || my == 3 && com == 1)

		printf("컴퓨터가 이겼습니다");
	else
		printf("당신이 이겼습니다");
	
}



// cd /workspace/SeowonCProject/assignment/week2/creation/ && gcc ./202011474.c -o /tmp/a.out -lm && clear && /tmp/a.out