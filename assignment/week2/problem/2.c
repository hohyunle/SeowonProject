/*
* 프로그램 내용: 2주차 팀별과제 2번
* 개발자: 김지성 (202110343)
* 문제: 계차수열은 인접하는 항의 차로 이루어진 수열을 말한다. 점화식을 이용하여 표현한 다음의 계차수열에 대해 항까지 출력하는 함수와 프로그램을 작성한다.
*/

#include <stdio.h>

int count(int n) {
    int term = 1;
    
    printf("점화식\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", term);
        term += i + 1;
    }
    printf("\n");
}

int main(void) {
    int n;

    printf("출력할 항의 개수를 입력 후 Enter>");
    scanf("%d", &n);

    count(n);
    
    return 0;
}






// cd /workspace/SeowonCProject/assignment/week2/problem/ && gcc ./2.c -o /tmp/a.out -lm && clear && /tmp/a.out