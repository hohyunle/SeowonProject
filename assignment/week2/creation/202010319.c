/*
* 프로그램 내용: 스낵 자동판매기 제어 프로그램 (창작 문제)
* 개발자: 김예은 (202010319)
*/

#include <stdio.h>

int main(void) {
    // 초기 상품 정보 및 최저 상품 가격 정의
    char product1[] = "초콜릿";
    char product2[] = "감자칩";
    char product3[] = "빼빼로";

    int price1 = 640;
    int price2 = 990;
    int price3 = 730;

    int min_price = 330;

    // 금액 입력
    int amount;
    printf("금액을 입력하세요 (0원 이상, 1000원 이하): ");
    scanf("%d", &amount);

    // 입력된 금액을 기준으로 판매 가능 여부 판단
    if (amount < min_price) {
        printf("현재 금액이 최저 상품 가격보다 작습니다. 거스름돈: %d원\n", amount);
    }
    else {
        // 상품 목록 출력
        printf("\n상품 목록:\n");
        printf("1. %s(%d원)\n", product1, price1);
        printf("2. %s(%d원)\n", product2, price2);
        printf("3. %s(%d원)\n", product3, price3);

        // 상품 선택
        int product_num;
        printf("\n상품 번호를 입력하세요 (1~3): ");
        scanf("%d", &product_num);

        // 선택한 상품 출력
        if (product_num == 1) {
            printf("\n선택한 상품: %s(%d원)\n", product1, price1);
        }
        else if (product_num == 2) {
            printf("\n선택한 상품: %s(%d원)\n", product2, price2);
        }
        else if (product_num == 3) {
            printf("\n선택한 상품: %s(%d원)\n", product3, price3);
        }
        else {
            printf("\n잘못된 상품 번호를 입력했습니다.\n");
            return 0;
        }

        // 구매 가능 여부 판단 및 처리
        int selected_price;
        if (product_num == 1) {
            selected_price = price1;
        }
        else if (product_num == 2) {
            selected_price = price2;
        }
        else {
            selected_price = price3;
        }

        if (amount >= selected_price) {
            printf("구매가능! 잔액: %d원\n", amount - selected_price);
        }
        else {
            printf("구매 불가! 현재 금액으로는 구매가 불가능합니다.\n");
        }
    }

    return 0;
}

s
// cd /workspace/SeowonCProject/assignment/week2/creation/ && gcc ./202010319.c -o /tmp/a.out -lm && clear && /tmp/a.out