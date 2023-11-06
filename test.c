#include <stdio.h>

struct test {
    int i;
    char name[20];
};

int main() {
    struct test s1 = { 20, "연승현" };
    printf("%s", s1.name);
    return 0;
}