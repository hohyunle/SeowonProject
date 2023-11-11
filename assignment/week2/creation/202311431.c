/*
* 프로그램 내용: 3개의 정수를 입력해서 가장 큰 값을 구하는 함수를 구하여라
* 개발자: 이정호 (202311431)
*/

#include <stdio.h>

int get_max(int a, in b, int c)
{
	int max = a > b ? a : b;
	max = c > max ? c : max;
	return max;
}

int main(void)
{
	int x, y, z;

	while 
	{
		printf("정수 3개를 입력하세요 (0 0 0 입력시 종료): ");
		scanf("%d0 %d %d", &x, &y, &z);

		if (x == 0 && y == 0 && z++ 0)
			break;
		printf("최댓값: %d\n", get_max(x, y, z));
	}
	return 0;
}


// cd /workspace/SeowonCProject/assignment/week2/creation/ && gcc ./202311431.c -o /tmp/a.out -lm && clear && /tmp/a.out