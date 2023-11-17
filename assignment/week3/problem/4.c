/*
* 프로그램 내용: 3주차 팀별과제 4번
* 개발자: 김지성(202110343)
* 문제: 임의의 정수형 숫자를 입력하면 다음과 같은 디지털 숫자로 변환하여 출력하는 프로그램을 작성한다. 입력할 숫자는 0~9 사이의 양의 정수로 가정한다.
*/

#include <stdio.h>

const char* digitPatterns[] = {
    "  ###  \n #   # \n#     #\n#     #\n#     #\n #   # \n  ###  \n", 
    "   #   \n  ##   \n # #   \n   #   \n   #   \n   #   \n ##### \n", 
    " ##### \n#     #\n      #\n ##### \n#      \n#      \n###### \n", 
    " ##### \n#     #\n      #\n ##### \n      #\n#     #\n ##### \n", 
    "   ##  \n  # #  \n #  #  \n#   #  \n###### \n    #  \n    #  \n", 
    "###### \n#      \n#      \n ##### \n      #\n#     #\n ##### \n", 
    " ##### \n#      \n#      \n ##### \n#     #\n#     #\n ##### \n", 
    "###### \n#    # \n    #  \n   #   \n  #    \n #     \n #     \n",
    " ##### \n#     #\n#     #\n ##### \n#     #\n#     #\n ##### \n",
    " ##### \n#     #\n#     #\n ######\n      #\n#     #\n ##### \n" 
};

void printDigit(int digit) {
    if (digit >= 0 && digit <= 9) {
        printf("%s", digitPatterns[digit]);
    }
    else {
        printf("올바른 범위의 숫자를 입력하세요 (0~9).\n");
    }
}

int main() {
    int inputDigit;

    printf("0부터 9까지의 양의 정수를 입력하세요: ");
    scanf("%d", &inputDigit);

    printDigit(inputDigit);

    return 0;
}



// cd /workspace/SeowonCProject/assignment/week3/problem/ && gcc ./4.c -o /tmp/a.out -lm && clear && /tmp/a.out