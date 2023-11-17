/*
* 프로그램 내용: 병원 예약 관리 프로그램 (창작 문제)
* 개발자: 양혜성 (202311419)
*/

#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define TIME_SLOTS 14

// 예약 정보 구조체
struct Reservation {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int hour;
    int minute;
};

// 초기화된 배열
int availability[TIME_SLOTS] = { 0 };
struct Reservation reservations[TIME_SLOTS];

// 복사 함수
void copyString(char dest[], const char src[], int max_length) {
    for (int i = 0; i < max_length - 1 && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[max_length - 1] = '\0';  // NULL 문자 추가
}

// 예약을 추가하는 함수
void reserveAppointment() {
    int hour;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];

    // 예약 가능한 시간대 출력
    printf("예약 가능한 시간대:\n");
    for (int i = 0; i < TIME_SLOTS; i++) {
        if (availability[i] == 0) {
            printf("%d. %02d:%02d  ", i + 1, 7 + i / 2, (i % 2) * 30);
        }
    }

    // 사용자로부터 예약 시간 선택
    printf("\n예약하려는 시간의 번호를 입력하세요: ");
    scanf("%d", &hour);

    // 입력된 시간이 유효한지 확인
    if (hour < 1 || hour > TIME_SLOTS || availability[hour - 1] == 1) {
        printf("예약할 수 없는 시간입니다. 다시 시도하세요.\n");
        return;
    }

    // 예약자 정보 입력
    printf("예약자 이름을 입력하세요: ");
    scanf(" %[^\n]s", name);  // 이름에 공백이 포함될 수 있도록 수정

    printf("예약자 전화번호를 입력하세요: ");
    scanf(" %[^\n]s", phone);  // 전화번호에 공백이 포함될 수 있도록 수정

    // 예약 정보 저장
    reservations[hour - 1].hour = 7 + (hour - 1) / 2;
    reservations[hour - 1].minute = (hour - 1) % 2 * 30;

    // 복사 함수를 사용하여 문자열 복사
    copyString(reservations[hour - 1].name, name, MAX_NAME_LENGTH);
    copyString(reservations[hour - 1].phone, phone, MAX_PHONE_LENGTH);

    // 예약된 시간으로 표시
    availability[hour - 1] = 1;

    printf("예약이 완료되었습니다.\n");
}

// 예약 확인을 위한 함수
void checkAppointment() {
    int choice;

    // 예약된 시간대 출력
    printf("예약된 시간대:\n");
    for (int i = 0; i < TIME_SLOTS; i++) {
        if (availability[i] == 1) {
            printf("%d. %02d:%02d  ", i + 1, reservations[i].hour, reservations[i].minute);
        }
    }

    // 사용자로부터 확인할 시간 선택
    printf("\n확인하려는 시간의 번호를 입력하세요: ");
    scanf("%d", &choice);

    // 입력된 시간이 유효한지 확인
    if (choice < 1 || choice > TIME_SLOTS || availability[choice - 1] == 0) {
        printf("예약된 시간이 아니거나 유효하지 않은 시간입니다.\n");
    }
    else {
        // 선택한 시간의 예약 정보 출력
        printf("%02d:%02d분 예약입니다.\n", reservations[choice - 1].hour, reservations[choice - 1].minute);
        printf("이름: %s\n전화번호: %s\n", reservations[choice - 1].name, reservations[choice - 1].phone);
    }
}

int main() {
    int choice;

    printf("병원 예약 관리 프로그램을 시작합니다.\n");

    do {
        // 메뉴 출력
        printf("\n1. 예약\n");
        printf("2. 예약 확인\n");
        printf("3. 종료\n");
        printf("선택하세요 (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            reserveAppointment();
            break;
        case 2:
            checkAppointment();
            break;
        case 3:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("유효하지 않은 선택입니다. 다시 선택하세요.\n");
        }

    } while (choice != 3);
    return 0;
}


// cd /workspace/SeowonCProject/assignment/week3/creation/ && gcc ./202311419.c -o /tmp/a.out -lm && clear && /tmp/a.out