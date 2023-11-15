#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <time.h>

char* getDate() {
    char date[30];
    time_t t = time(NULL);
    struct tm tm_info = *localtime(&t);
    // 현재 날짜를 yyyy-mm-dd 형식으로 문자열에 저장
    sprintf(date, "%04d-%02d-%02d", tm_info.tm_year + 1900, tm_info.tm_mon + 1, tm_info.tm_mday);
    return date;
}


#endif // UTIL_H