/*
* 프로그램 내용: 키와 몸무게를 입력받아 bmi를 계산하는 코드를 작성하십시오 (창작 문제)
* 개발자: 장서진
* 학번: 202311825
*/


#include <stdio.h>

int main() {
    float weight, height, bmi;

    printf("체중(kg)을 입력하세요: ");
    scanf("%f", &weight);

    printf("키(m)를 입력하세요: ");
    scanf("%f", &height);

    bmi = weight / (height * height);

    printf("당신의 BMI는 %.2f 입니다.\n", bmi);

    if (bmi < 18.5) {
        printf("저체중");
    } else if (bmi < 24.9) {
        printf("정상");
    } else if (bmi < 29.9) {
        printf("과체중");
    } else {
        printf("비만");
    }

    return 0;
}


// cd /workspace/SeowonCProject/assignment/week1/creation/ && gcc ./202311825.c -o /tmp/a.out -lm && clear && /tmp/a.out