/*
* 프로그램 내용: 1주차 팀별과제 3번
* 개발자: 김지성 (202110343)
* 문제: 두 학생의 이름과 중간, 기말 성적을 입력 받아, 평균을 구하여 출력하고(소수점이하 2자리까지 출력),  성적이 좋은 학생의 이름을 출력하는 프로그램을 작성하세요.
*/

#include <stdio.h>

int main(void) {
    char name1[50], name2[50];
    float mid1, mid2, final1, final2;
    float avg1, avg2;

    printf("첫 번째 학생 이름을 입력하세요: ");
    scanf("%s", name1);
    printf("첫 번째 학생의 중간 성적을 입력하세요: ");
    scanf("%f", &mid1);
    printf("첫 번째 학생의 기말 성적을 입력하세요: ");
    scanf("%f", &final1);

    printf("두 번째 학생 이름을 입력하세요: ");
    scanf("%s", name2);
    printf("두 번째 학생의 중간 성적을 입력하세요: ");
    scanf("%f", &mid2);
    printf("두 번째 학생의 기말 성적을 입력하세요: ");
    scanf("%f", &final2);

    avg1 = (mid1 + final1) / 2;
    avg2 = (mid2 + final2) / 2;

    printf("첫 번째 학생의 평균 성적: %.2f\n", avg1);
    printf("두 번째 학생의 평균 성적: %.2f\n", avg2);

    if (avg1 > avg2) {
        printf("성적이 좋은 학생: %s\n", name1);
    }
    else if (avg2 > avg1) {
        printf("성적이 좋은 학생: %s\n", name2);
    }
    else {
        printf("두 학생의 성적이 동일합니다.\n");
    }
    return 0;
}

// cd /workspace/SeowonCProject/assignment/week1/problem/ && gcc ./3.c -o /tmp/a.out -lm && clear && /tmp/a.out