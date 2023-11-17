/*
* 프로그램 내용: 정수 5개를 입력받고 최대값을 출력하는 프로그램 (창작 문제)
* 개발자: 김지성 (202110343)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 5;

    int* numbers = (int*)malloc(size * sizeof(int));

    if (numbers == NULL) {
        fprintf(stderr, "메모리 할당 오류\n");
        return 1;
    }

    printf("정수 %d개를 입력하세요:\n", size);
    for (int i = 0; i < size; i++) {
        printf("정수 %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    printf("입력한 정수 중 최대값: %d\n", max);
    free(numbers);
    return 0;
}

// cd /workspace/SeowonCProject/assignment/week3/creation/ && gcc ./202110343.c -o /tmp/a.out -lm && clear && /tmp/a.out