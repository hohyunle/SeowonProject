/*
* 프로그램 내용: 네 개의 숫자를 각각 입력받아. 하나의 정수 변수에 저장한다음, 다시 저장된 변수에서 다시 숫자를 높은 순서대로 정렬하여 출력하는 프로그램을 작성하시오 (창작 문제)
* 개발자: 양혜성
* 학번: 202311419
*/


#include <stdio.h>

int main(void) {
    int numbers[4];
    int temp;
    int i, j;

    printf("네 개의 숫자를 입력하세요:\n");
    for (i = 0; i < 4; i++) {
        scanf_s("%d", &numbers[i]);
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3 - i; j++) {
            if (numbers[j] < numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    printf("정렬된 숫자 (높은 순서대로):\n");
    for (i = 0; i < 4; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}