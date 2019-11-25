#include <stdio.h>
#include "VM.h"
#include "CG.h"
#include "Infix2Postfix.h"
#include <windows.h>


void CG(char arr[120][40], int size);
int VM(char arr[120], int size);
char * Tok();



int main() {

    char * result = Tok();

    //Sleep(2000000);

    return 0;
}