/*
* 프로그램 내용: 2주차 팀별과제 4번
* 개발자: 이정호(203311431)
* 문제: 각도가 0도에서 360도까지 15도씩 증가할 때 함수 sine 그래프와 cosine 그래프를 하나 의 좌표에 동시에 출력하는 프로그램을 작성한다.
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main() {
    int angle;
    float sine, cosine;

    printf("각도\tSine\tCosine\n");
    for (angle = 0; angle <= 360; angle += 15) {
        sine = sin(angle * PI / 180.0);
        cosine = cos(angle * PI / 180.0);

        if (fabs(sine - cosine) < 0.1) {
            printf("%d\t*\t*\n", angle);
        }
        else if (sine < cosine) {
            printf("%d\tS\tC\n", angle);
        }
        else {
            printf("%d\t\tS\tC\n", angle);
        }
    }

    return 0;
}





// cd /workspace/SeowonCProject/assignment/week2/problem/ && gcc ./4.c -o /tmp/a.out -lm && clear && /tmp/a.out