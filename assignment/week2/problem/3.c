/*
* 프로그램 내용: 2주차 팀별과제 3번
* 개발자: 양혜성 (202311420)
* 문제: 사용자에게 파스칼의 삼각형의 행의 수를 입력 받고 입력 받은 수만큼의 삼각형을 그려 출력하는 프로그램
*/

#include <stdio.h>

long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

long binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

void Pascalstriangle(int rows) {
    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%ld ", binomialCoefficient(i, j));
        }
        printf("\n");
    }
}

int main(void) {
    int rows;

    printf("행의 수: ");
    scanf("%d", &rows);

    Pascalstriangle(rows);

    return 0;
}






// cd /workspace/SeowonCProject/assignment/week2/problem/ && gcc ./3.c -o /tmp/a.out -lm && clear && /tmp/a.out