/*
* 프로그램 내용: 2주차 팀별과제 5번
* 개발자: 이호현 (202311437)
* 문제: 주행거리에 따라 요금을 계산하는 택시미터기 제어 프로그램을 작성한다. 기본요금은 출 발하여 2km 이내까지 2000원이고, 출발 후 2km를 초과할 경우 요금은 144m당 100원씩 추가된다. 프로그램 시작과 동시에 시속 75km로 출발하며 화면에는 다음과 같은 정보를 출력 한다.
*/

#include <stdio.h>
#include <time.h>

#define INITIAL_FARE 2000       // 기본 요금
#define FARE_PER_METER 100      // 미터당 추가 요금
#define INITIAL_SPEED 75        // 초깃값으로 설정된 시속

int main(void) {
    time_t start_time, current_time;
    double distance = 0.0;
    int fare = INITIAL_FARE;
    int speed = INITIAL_SPEED;

    // 초깃값으로 현재 시간 설정
    time(&start_time);

    // 프로그램 시작 메시지 출력
    printf("택시 미터기 제어 프로그램을 시작합니다.\n");

    // 메인 루프
    while (1) {
        // 현재 시간 갱신
        time(&current_time);

        // 주행 시간 계산
        int elapsed_time = difftime(current_time, start_time);
        int hours = elapsed_time / 3600;
        int minutes = (elapsed_time % 3600) / 60;
        int seconds = elapsed_time % 60;

        // 주행 거리 및 현재 요금 계산
        distance += (speed * 1000) / 3600.0; // 초당 이동 거리 계산
        fare = INITIAL_FARE + (int)((distance - 2.0) / 0.144) * FARE_PER_METER;

        // 화면 출력
        printf("현재 시간: %d시 %d분 %d초\n", hours, minutes, seconds);
        printf("주행 시간: %d시 %d분 %d초\n", hours, minutes, seconds);
        printf("주행 거리: %.3lfkm\n", distance);
        printf("현재 요금: %d원\n", fare);

        // 1초 대기
        sleep(1);
    }

    return 0;
}







// cd /workspace/SeowonCProject/assignment/week2/problem/ && gcc ./5.c -o /tmp/a.out -lm && clear && /tmp/a.out