#include <stdio.h>

#define LINE 100
#define LENGTH 100

char code[LINE][LENGTH];

int main(void) {
    //Open ASM file
    FILE *readfPtr = fopen("Add.asm", "r");

    if(readfPtr == NULL) {
        puts("Unable to open input file.");
    } else {
        //Use a character string to read codes from ASM file
        //Discard all the comments and new lines
        char read[LENGTH];

        fgets(read, LENGTH, readfPtr);
        while(!feof(readfPtr)) {



            fgets(read, LENGTH, readfPtr);//Gets the next line
        }

        fclose(readfPtr);
    }
    return 0;
}
