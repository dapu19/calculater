#include <stdio.h>
#include "VM.h"
#include "CG.h"
#include "Infix2Postfix.h"


int Infix2Postfix(char infixArray[], char postfixArray[240]);
void CG(char arr[120][40], int size);
int VM(char arr[120], int size);


int main() {
    char sum[120][40] =  {"2", "+", "2", "*", "8"};

    printf("Hello, World!\n");
    char Mattsum[][40] = { "5", "3457","+","6","2", "-", "*"};

    CG(Mattsum, 7);


    return 0;
}