#include <stdio.h>

int main(void)
{
    char a, b, c, d;
    int num = 0;

    printf("문자 입력(띄어쓰기로 구분) >> ");
    scanf("%c %c %c %c", &a, &b, &c, &d);
    num = (num << 8) | a; 
    num = (num << 8) | b;
    num = (num << 8) | c;
    num = (num << 8) | d;


    printf("입력한 문자 >> %c%c%c%c\n", (num>>24), (num>>16), (num>>8), num);

    return 0;
}