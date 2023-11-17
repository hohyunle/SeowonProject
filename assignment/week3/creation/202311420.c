/*
* 프로그램 내용: 정수형 배열에 저장된 숫자들 중에서 가장 큰 값을 찾는 프로그램 (창작 문제)
* 개발자: 연승현 (202311420)
*/

#include <stdio.h>

int findMax(int arr[], int size) {
    int max = arr[0]; // 배열의 첫 번째 요소를 최댓값으로 초기화

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i]; // 새로운 최댓값으로 갱신
        }
    }
    return max;
}

int main(void) {
    int list[] = {5, 2, 9, 1, 7}; 	// 정수 리스트
    int size = sizeof(list) / sizeof(list[0]); // 배열의 크기 계산

    int maxNum = findMax(list, size);
    printf("가장 큰 값: %d\n", maxNum);

    return 0;
}


// cd /workspace/SeowonCProject/assignment/week3/creation/ && gcc ./202311420.c -o /tmp/a.out -lm && clear && /tmp/a.out