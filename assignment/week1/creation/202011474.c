/*
* 프로그램 내용: 1부터 100까지 수를 생성하여 힌트를 받으며 숫자를 맞추는 프로그램 (창작 문제)
* 개발자: 정희태
* 학번: 202011474
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int random, number;
    
    srand(time(NULL));
    random = rand() % 101 + 1;
          
    printf("1~100까지의 수를 적어주세요: ");
    
    while(1) {
          
        scanf("%d",&number);
          
        if(random == number) {
              printf("맞습니다\n");
              break;       
          } else if (random > number) {
            printf("좀 더 큰 숫자를 써주세요: ");
            continue;
        } else if (random<number) {
            printf("좀 더 작은 숫자를 써주세요: ");
            continue;
          }
    }
          
    return 0;
}


// cd /workspace/SeowonCProject/assignment/week1/creation/ && gcc ./202311420.c -o /tmp/a.out -lm && clear && /tmp/a.out