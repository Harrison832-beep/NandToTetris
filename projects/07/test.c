#include <stdio.h>

void staticTest();

int main(void) {
    for(int i=0; i<15; i++) {
        staticTest();
    }
    return 0;
}

void staticTest(){
    static int i=0, j=0, k=0;
    printf("i:%d j:%d k:%d\n", i, j, k);
    i++;
    j++;
    k++;
}

