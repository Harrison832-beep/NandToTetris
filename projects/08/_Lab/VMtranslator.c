//stack [256, 2047]
//static [16, 255]
//general purpose registers [13, 15]
//temp segment [5, 12]

//SP = 256
//LCL = 300
//ARG = 400
//THIS = 3000
//THAT = 3010

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

enum type {C_ARITHMETIC = 1, C_PUS, C_POP, C_LABEL, C_GOTO, C_IF, C_FUNCTION, C_RETURN, C_CALL};

void sysInit(FILE *);
void constructor1(FILE *, FILE *);
int hasMoreCommands();//feof
void advance();//fgets
const int commandType(char tex[]);
void compute(char arg1[], int arg2);
void constructor2(FILE *);
void writeArithmetic(char *, FILE *);
void writePushPop(const int , char *, int, FILE *);

int main(void) {
    char inFileName[30];
    char outFileName[30];
    printf("Enter input file name (fileName.vm): ");
    scanf("%s", inFileName);

    FILE *vmInPtr = fopen(inFileName, "r");
    //getchar();

    printf("Enter output file name (fileName.asm): ");
    scanf("%s", outFileName);
    FILE *vmOutPtr = fopen(outFileName, "w");
    //getchar();

    sysInit(vmOutPtr);
    constructor1(vmInPtr, vmOutPtr);

    return 0;
}

void sysInit(FILE *outfPtr) {
    fprintf(outfPtr, "%s",
            "(Sys.init)\n"
            "@256\n"
            "D = A\n"
            "@SP\n"
            "M = D\n"
            "@300\n"
            "D = A\n"
            "@LCL\n"
            "M = D\n"
            "@400\n"
            "D = A\n"
            "@ARG\n"
            "M = D\n"
            "@3000\n"
            "D = A\n"
            "@THIS\n"
            "M = D\n"
            "@3010\n"
            "D = A\n"
            "@THAT\n"
            "M = D\n"
            "\n(MAIN)\n");
}

void constructor1(FILE * infPtr, FILE *outfPtr) {


    if(infPtr == NULL) {
        puts("Unable to open Input file!");
    } else {
        char text[100];
        char digitChar[5];
        char *remainder;
        int digit;



        fgets(text, 100, infPtr);
        while(!feof(infPtr)) {
                int i=0, j=0, count=0;
            if(strstr(text, "//") == 0) {
                int ty = commandType(text);
                //printf("%d\n", ty);
                while(text[i] != '\0') {
                    if(isdigit(text[i])) {
                        digitChar[j] = text[i];
                        j ++;
                        i ++;
                        continue;
                    }
                    count ++;
                    i ++;
                }


                if(count != strlen(text)) {
                    digitChar[j] = '\0';
                    digit = strtol(digitChar, &remainder, 0);
                    //printf("%d\n", digit);
                    if(ty == 2 || ty == 3) {
                    writePushPop(ty, text, digit, outfPtr);
                    }

                } else {
                    if(ty == 1) {
                        writeArithmetic(text, outfPtr);
                    }
                }

            }
            fgets(text, 100, infPtr);
        }

        fclose(infPtr);
        fclose(outfPtr);
    }
}

const int commandType(char tex[]) {
    enum type vm = 0;
    //1: arithmetic
    //2: push
    //3: pop
    if(strstr(tex, "add") || strstr(tex, "sub") || strstr(tex, "eq") || strstr(tex, "or") || strstr(tex, "and")) {
        vm = 1;
    } else if(strstr(tex, "push")) {
        vm = 2;
    } else if(strstr(tex, "pop")) {
        vm = 3;
    }


    return vm;
}

void writePushPop(const int ty, char tex[], int dig, FILE *outPtr) {
    //local, constant, argument, this, that, temp
    char seg[30];
    int mark=0;
        if(strstr(tex, "local")) {
            sprintf(seg, "%s", "@LCL\n");
            mark = 1;
            //puts(seg);
        }
        if(strstr(tex, "constant")) {
            sprintf(seg, "%s", "constant");
            mark = 2;
            //puts(seg);
        }
        if(strstr(tex, "argument")) {
            sprintf(seg, "%s", "@ARG\n");
            mark = 1;
            //puts(seg);
        }
        if(strstr(tex, "this")) {
            sprintf(seg, "%s", "@THIS\n");
            mark = 1;
            //puts(seg);
        }
        if(strstr(tex, "that")) {
            sprintf(seg, "%s", "@THAT\n");
            mark = 1;
            //puts(seg);
        }
        if(strstr(tex, "temp")) {
            sprintf(seg, "%s", "temp");
            mark = 3;
            //puts(seg);
        }


    if(ty == C_PUS) {
            fprintf(outPtr, "//Push\n");
            switch(mark) {
                case 1:
                    fprintf(outPtr, "@%d\n", dig);
                    fprintf(outPtr, "D = A\n");
                    fprintf(outPtr, "%s", seg);
                    fprintf(outPtr, "%s",
                            "A = M + D\n"
                            "D = M\n");
                    break;

                case 2:
                    fprintf(outPtr, "@%d\n", dig);
                    fprintf(outPtr, "%s",
                            "D = A\n");
                    break;

                case 3:
                    fprintf(outPtr, "@%d\n", dig);
                    fprintf(outPtr, "D = A\n");
                    fprintf(outPtr, "@R5\n");
                    fprintf(outPtr, "%s",
                            "A = A + D\n"
                            "D = M\n");
                    break;
            }
        fprintf(outPtr, "%s",
                "@SP\n"
                "A = M\n"
                "M = D\n"
                "@SP\n"
                "M = M + 1\n");
    }

    if(ty == C_POP) {
            fprintf(outPtr, "//Pop\n");
            fprintf(outPtr, "%s",
                "@SP\n"
                "A = M - 1\n"
                "D = M\n"
                );
        switch(mark) {
                case 1:
                    fprintf(outPtr, "@%d\n", dig);
                    fprintf(outPtr, "D = A\n");
                    fprintf(outPtr, "%s", seg);
                    fprintf(outPtr, "%s",
                            "A = M + D\n"//RAM[LCL, ARG, THIS, THAT]
                            "D = A\n"
                            "@R13\n"
                            "M = D\n"
                            "@SP\n"
                            "A = M - 1\n"
                            "D = M\n"
                            "@R13\n"
                            "A = M\n"
                            "M = D\n");
                    break;

                case 3:
                    fprintf(outPtr, "@%d\n", dig);
                    fprintf(outPtr, "D = A\n");
                    fprintf(outPtr, "@R5\n");
                    fprintf(outPtr, "%s",
                            "A = A + D\n"
                            "D = A\n"
                            "@R13\n"
                            "M = D\n"
                            "@SP\n"
                            "A = M - 1\n"
                            "D = M\n"
                            "@R13\n"
                            "A = M\n"
                            "M = D\n");
                    break;
            }
        fprintf(outPtr, "%s",
                "@SP\n"
                "M = M - 1\n");
    }
}

void writeArithmetic(char tex[], FILE *outPtr) {
    char seg[30];
    int mark=0;
    if(strstr(tex, "add")) {
        mark = 1;
    }
    if(strstr(tex, "sub")) {
        mark = 2;
    }

    if(mark != 0) {
        switch(mark) {
            case 1:
                fprintf(outPtr, "//Add\n");
                fprintf(outPtr, "%s",
                        "@SP\n"
                        "M = M - 1\n"
                        "A = M\n"
                        "D = M\n"
                        "@SP\n"
                        "M = M - 1\n"
                        "A = M\n"
                        "D = M + D\n"
                        "@SP\n"
                        "A = M\n"
                        "M = D\n"
                        "@SP\n"
                        "M = M + 1\n");
                break;

            case 2:
                fprintf(outPtr, "//Sub\n");
                fprintf(outPtr, "%s",
                        "@SP\n"
                        "M = M - 1\n"
                        "A = M\n"
                        "D = M\n"
                        "@SP\n"
                        "M = M - 1\n"
                        "A = M\n"
                        "D = M - D\n"
                        "@SP\n"
                        "A = M\n"
                        "M = D\n"
                        "@SP\n"
                        "M = M + 1\n");
                break;
        }
    }
}
