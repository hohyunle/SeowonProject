/*
* 프로그램 내용: 금액을 입력받아 콤마를 넣어 표시해주는 함수 프로그램 만들기 (창작 문제)
* 개발자: 연승현 (202311420)
*/

#include <stdio.h>
#include <locale.h>

int comma(int money) {
    // 현재 지역 설정을 사용하여 콤마 출력을 위해 (locale.h: 지역 설정은 프로그램이 실행되는 환경의 지역과 언어 관련 정보를 설정하는 것으로 날짜, 시간, 통화, 숫자 등의 형식을 해당 지역의 관례에 맞게 표시할 수 있도록 도와줍니다.)
    setlocale(LC_ALL, "");
    printf("금액: %d 원\n", money);
}

int main(void) {
    unsigned int money;
    
    printf("금액을 입력해주세요: ");
    scanf("%d", &money);
    comma(money);
    
    return 0;
}



// cd /workspace/SeowonCProject/assignment/week2/creation/ && gcc ./202311420.c -o /tmp/a.out -lm && clear && /tmp/a.out