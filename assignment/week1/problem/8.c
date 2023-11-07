/*
* 프로그램 내용: 1주차 팀별과제 8번
* 개발자: 정희태 (202011474)
* 문제: 초단위의 시간을 입력 받아서 몇시 몇분 몇초 인지를 계산하여 출력하는 프로그램을 작성하세요.
*/

#include <stdio.h>

int main(void) {
    int total_seconds, remain_seconds, hours, minutes, seconds;

    printf("초 단위를 입력하세요. ");
    scanf("%d", &total_seconds);
    
    hours = total_seconds / 3600;               // 1 시간 = 3600 초
    remain_seconds = total_seconds % 3600;      // tatal_seconds를 시간으로 바꿔서 저장하고 남은 초를 다른 변수에 저장
    minutes = remain_seconds / 60;              // 1 분 = 60 초-> 몫은 분이 되고 나머지는 초가 된다
    seconds = remain_seconds % 60;              // 나머지 초

    // 결과 출력
    printf("입력한 시간은 %d시 %d분 %d초입니다.\n", hours, minutes, seconds);

    return 0;
}


// cd /workspace/SeowonCProject/assignment/week1/problem/ && gcc ./8.c -o /tmp/a.out -lm && clear && /tmp/a.out