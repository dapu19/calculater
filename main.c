#include <stdio.h>
#include "VM.h"
#include "CG.h"
#include "Infix2Postfix.h"

void CG(char arr[120][40], int size);
int VM(char arr[120], int size);
void Infix2Postfix(char in[10][240], char post[10][240]);
void Tok();



int main() {
    //printf("Hello, World!\n");
    Tok();
    char Mattsum[][40] = { "5", "3457","+","6","2", "-", "*"};

    CG(Mattsum, 7);

    char MatthewsAwesomeInfixArray[][1] = {"1", "+", "2"};
    char MatthewsAwesomePostfixArray[100][240];
    //Infix2Postfix(MatthewsAwesomeInfixArray, MatthewsAwesomePostfixArray);

    return 0;
}