/*
* 프로그램 내용: 2주차 팀별과제 1번
* 개발자: 연승현 (202311420)
* 문제: 월급에 붙는 소득세를 계산하여 보자. 과표 구간은 1000만원 이하 8%, 1000만원 초과 4000천만원 이하 구간은 17%, 4000만원 초과 8000만원 이하는 26%, 8000만원 초과 35%로 되어 있다고 가정한다. 사용자로부터 소득을 입력 받아서, 소득의 구간에 따라서 세금을 계산하는 c언어 프로그램을 작성하라. 단 최종 부과 세금은 소수점 이하는 반올림한 다음, 10원 미만의 단위는 절삭한다. 또한 최종 부과 세금 출력 형태는 화폐 출력 형식에 따라, 3자리 수마다 콤마(",") 문자 를 추가해서 출력해야함
*/

#include <stdio.h>
#include <locale.h>
#include <math.h>


int main(void) {
    double money, tax;
    
    // 현재 지역 설정을 사용하여 콤마 출력을 위해 (locale.h: 지역 설정은 프로그램이 실행되는 환경의 지역과 언어 관련 정보를 설정하는 것으로, 날짜, 시간, 통화, 숫자 등의 형식을 해당 지역의 관례에 맞게 표시할 수 있도록 도와줍니다.)
    setlocale(LC_ALL, ""); 

    printf("월급을 입력하세요 (단위: 원): ");
    scanf("%lf", &money);

    if (money <= 10000000) {
        // 1000만원 이하 8%
        tax = money * 0.08;
    } else if (money <= 40000000) {
        // 1000만원 초과 4000천만원 이하 구간은 17% (구간마다 다르게)
        tax = 10000000 * 0.08 + (money - 10000000) * 0.17;
    } else if (money <= 80000000) {
        // 4000만원 초과 8000만원 이하는 26% (구간마다 다르게)
        tax = 10000000 * 0.08 + 30000000 * 0.17 + (money - 40000000) * 0.26;
    } else {
        // 8000만원 초과 35% (구간마다 다르게)
        tax = 10000000 * 0.08 + 30000000 * 0.17 + 40000000 * 0.26 + (money - 80000000) * 0.35;
    }
    
    // 소수점 이하 반올림 (math.h)
    tax = round(tax); 
    // 소득세를 10으로 나눠 정수변환 후 10을 곱해 10원 미만 단위 절삭
    tax = (int)(tax / 10) * 10;    
    // `'`: 천 단위로 콤마(천 단위 구분 기호)를 표시, `0.0`: 소수점 이하 표시 X
    printf("소득세: %'0.0lf 원\n", tax);

    return 0;
}






// cd /workspace/SeowonCProject/assignment/week2/problem/ && gcc ./1.c -o /tmp/a.out -lm && clear && /tmp/a.out