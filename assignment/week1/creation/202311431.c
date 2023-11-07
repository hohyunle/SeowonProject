/*
* 프로그램 내용: 가격을 입력받아 할인된 가격을 출력하는 프로그램
* 개발자: 이정호 (202311431) 
*/
#include <stdio.h>


int main(void) {
    float price;
	float result;
	double sum;
    printf("물건의 가격을 입력하세요: ");
    scanf("%f", &price);

	result = price * 0.3;
	sum=price-result;

    printf("할인된 가격은: %.2f\n전체 가격은: %.2f", result,sum);

    return 0;
}


// cd /workspace/SeowonCProject/assignment/week1/creation/ && gcc ./202311431.c -o /tmp/a.out -lm && clear && /tmp/a.out