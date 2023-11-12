/*
* 프로그램 내용: 숫자 3개와 문자 3개를 출력하는 프로그램을 만드시오. (창작 문제)
* 개발자: 홍정일 (202311447)
*/
#include <stdio.h>

int sum(int x, int y);
int main(void)
{
   int x, y;

   printf("x, y값을 입력하세요 : ");
   scanf_s("%d %d", &x, &y);

   
   printf("%d + %d = %d", x, y, sum(x, y));
}

int sum(int x, int y)
{
   int sum_result;

   sum_result = x + y;
   return sum_result;
}

// cd /workspace/SeowonCProject/assignment/week2/creation/ && gcc ./202311447.c -o /tmp/a.out -lm && clear && /tmp/a.out
