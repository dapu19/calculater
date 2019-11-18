#include <stdio.h>
#include "VM.h"
#include "Infix2Postfix.h"
int VM(char arr[120], int size);
int Infix2Postfix(char infix[240]);


int main() {
    printf("Hello, World!\n");
    char sum[][40] = { "loadint 5", "loadint 7","add","loadint 6","loadint 2", "sub", "mul"};

    int result = VM(sum, 7);
    printf("result = %d", result);

    char infixArray[][240] = {"1", "+", "2"};
    char postfixArray = Infix2Postfix(infixArray);
    printf(postfixArray);



    return 0;
}