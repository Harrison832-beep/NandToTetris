#include <stdio.h>

int main(void) {
    char c = '\0';
    printf("%d", c==0);
    c = '+';
    printf("%c", c);

    return 0;
}
