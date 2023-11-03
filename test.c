#include <stdio.h>

int main() {
    float rate = 1338.58;  // 환율: 1 달러 당 원화
    int won;
    float dollar;

    printf("환전할 금액(원) 입력 >> ");
    scanf("%d", &won);

    dollar = won / rate;
    printf("%d원을 환전하면 %.2f 달러입니다.\n", won, dollar);

    return 0;
}