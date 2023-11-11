/*
* 프로그램 내용: BMI 구하는 함수 프로그램 (창작 문제)
* 개발자: 이호현 (202311437)
*/

#include <stdio.h>

int bmi(double weight, double height);

int main(void)
{
	char name[20];
	double weight, height;

	printf("이름, 키(m)와 몸무게(kg)를 입력하시오 : ");
	scanf("%s %lf %lf", name, 20, &height, &weight);

	double resultbmi = bmi(weight, height);

	printf("%s님의 BMI 지수 : %.2lf", name, resultbmi);

	return 0;
}

int bmi(double weight, double height)
{
	double bmi;
	bmi = weight / (height * height);

	return bmi;
}


// cd /workspace/SeowonCProject/assignment/week2/creation/ && gcc ./202311437.c -o /tmp/a.out -lm && clear && /tmp/a.out