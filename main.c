#include <stdio.h>
#include "VM.h"
#include "CG.h"
#include "Infix2Postfix.h"

void CG(char arr[120][40], int size);
int VM(char arr[120], int size);
char * Tok();



int main() {
    //printf("Hello, World!\n");
    char * result = Tok();
    printf("Tokiniser result: %s\n", result);
    char Mattsum[][40] = { "5", "3457","+","6","2", "-", "*"};

    CG(Mattsum, 7);

    return 0;
}