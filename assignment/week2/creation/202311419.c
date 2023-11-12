/*
* 프로그램 내용: 도형을 작성하고 변의 길이를 입력하여 도형을 만들어내는 코드 (창작 문제)
* 개발자: 양혜성 (202311419)
*/

#include <stdio.h>

void drawTriangle(int sideLength) {
    for (int i = 0; i < sideLength; i++) {
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void drawSquare(int sideLength) {
    for (int i = 0; i < sideLength; i++) {
        for (int j = 0; j < sideLength; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void drawCircle(int radius) {
    printf("원은 변이 없기에 만들수 없습니다. \n");
}

int main(void) {
    char shape;
    printf("도형을 선택하세요 (삼각형:T, 사각형:S, 원:C): ");
    scanf(" %c", &shape);

    if (shape == 'T' || shape == 't' || shape == 'S' || shape == 's' || shape == 'C' || shape == 'c') {
        int sideLength;
        printf("변의 길이를 입력하세요: ");
        scanf("%d", &sideLength);

        if (sideLength > 0) {
            printf("\n");

            switch (shape) {
            case 'T':
            case 't':
                drawTriangle(sideLength);
                break;
            case 'S':
            case 's':
                drawSquare(sideLength);
                break;
            case 'C':
            case 'c':
                drawCircle(sideLength);
                break;
            }
        }
        else {
            printf("변의 길이는 양수여야 합니다.\n");
        }
    }
    else {
        printf("올바른 도형을 선택하세요 (T, S, C).\n");
    }
    return 0;
}


// cd /workspace/SeowonCProject/assignment/week2/creation/ && gcc ./202311419.c -o /tmp/a.out -lm && clear && /tmp/a.out