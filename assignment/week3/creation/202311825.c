/*
* 프로그램 내용: 5개의 정수를 입력받고 역순으로 출력하는 프로그램을 작성하시오 (창작 문제)
* 개발자: 장서진 (202311825)
*/

#include<stdio.h> 

int main(void)
{
    // 5개의 정수를 저장할 배열 선언
    int num[5];
    // 반복문에서 사용할 변수 선언
    int count; 

    // 사용자에게 정수를 입력하라는 안내 메시지 출력
    printf("5개의 정수를 입력하세요.\n"); 

    // 5번 반복하여 정수를 입력받아 배열에 저장
    for (count = 0; count < 5; count++)
    {
        scanf("%d", &num[count]);
    } 

    // 배열을 역순으로 출력
    for (count = 4; count >= 0; count--)
    {
        // 각 숫자 사이에 공백 추가하여 출력
        printf("%d ", num[count]);
    } 
    return 0;
}



// cd /workspace/SeowonCProject/assignment/week3/creation/ && gcc ./202311825.c -o /tmp/a.out -lm && clear && /tmp/a.out