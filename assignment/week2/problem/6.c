/*
* 프로그램 내용: 2주차 팀별과제 6번
* 개발자: 김예은 (202010319)
* 문제: 상품명과 가격을 화면에 표시하고, 금액과 품목을 입력하면 다음의 처리 기준에 의해 작동하는 자동판매기 제어 프로그램을 작성한다.
*/

#include <stdio.h>

// 상품 정보
typedef struct {
    char name[20];
    int price;
} Product;

// 초기 상품 설정
Product products[] = { {"커피", 330}, {"콜라", 480}, {"주스", 600} };
int numProducts = sizeof(products) / sizeof(products[0]);

// 거스름돈 단위
int denominations[] = { 500, 100, 50, 10 };
int numDenominations = sizeof(denominations) / sizeof(denominations[0]);

// 함수 선언
void displayProducts();
void processPurchase(int productIndex, int amount);

int main() {
    int userAmount;
    int selectedProductIndex;

    printf("=== 자동판매기 프로그램 ===\n");

    while (1) {
        displayProducts();

        // 금액 입력
        printf("\n금액을 입력하세요 (0원 이상, 1000원 이하): ");
        scanf_s("%d", &userAmount);

        if (userAmount < 0 || userAmount > 1000) {
            printf("입력이 올바르지 않습니다. 다시 입력하세요.\n");
            continue;
        }

        // 상품 선택
        printf("\n상품 번호를 입력하세요 (1~%d, 0: 종료): ", numProducts);
        scanf_s("%d", &selectedProductIndex);

        if (selectedProductIndex < 0 || selectedProductIndex > numProducts) {
            printf("입력이 올바르지 않습니다. 다시 입력하세요.\n");
            continue;
        }

        if (selectedProductIndex == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        // 상품 처리
        processPurchase(selectedProductIndex - 1, userAmount);
    }

    return 0;
}

void displayProducts() {
    printf("\n상품 목록:\n");
    for (int i = 0; i < numProducts; ++i) {
        printf("%d. %s (%d원)\n", i + 1, products[i].name, products[i].price);
    }
}

void processPurchase(int productIndex, int amount) {
    Product selectedProduct = products[productIndex];

    printf("\n선택한 상품: %s (%d원)\n", selectedProduct.name, selectedProduct.price);

    if (amount < selectedProduct.price) {
        printf("금액이 부족합니다. 구매를 계속할 수 없습니다.\n");
    }
    else {
        printf("구매가능합니다. 구매를 진행합니다.\n");

        // 거스름돈 계산 및 출력
        int change = amount - selectedProduct.price;
        printf("거스름돈: %d원\n", change);

        // 거스름돈 단위별로 출력
        printf("거스름돈 동전 단위: ");
        for (int i = 0; i < numDenominations; ++i) {
            int count = change / denominations[i];
            if (count > 0) {
                printf("%d원(%d개) ", denominations[i], count);
                change -= count * denominations[i];
            }
        }
        printf("\n");
    }
}






// cd /workspace/SeowonCProject/assignment/week2/problem/ && gcc ./1.c -o /tmp/a.out -lm && clear && /tmp/a.out