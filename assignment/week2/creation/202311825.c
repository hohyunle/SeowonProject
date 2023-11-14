/*
* 프로그램 내용: 정수를 두 개 입력받고 두 수를 더하여 리턴하는 함수를 작성하시오 (창작 문제)
* 개발자: 장서진 (202311825)
*/

#include<stdio.h> 

// 함수 선언

int add(int a, int b); 

int main(void)
{
    // 변수 선언
    int a, b;

    // 정수 입력받기
    printf("두 정수를 입력하세요.\n");
    scanf("%d %d", &a, &b);
    
    // 두 정수의 합을 출력
    printf("두 수의 합은: %d\n", add(a, b));
    return 0;
} 

// 두 정수를 더하는 함수
int add(int a, int b)
{
    int sum = a + b;
    return sum;
}

// cd /workspace/SeowonCProject/assignment/week2/creation/ && gcc ./202311825.c -o /tmp/a.out -lm && clear && /tmp/a.out