#include <stdio.h>
#include "VM.h"
int VM(char arr[120], int size);


int main() {
    printf("Hello, World!\n");
    char sum[][40] = { "loadint 5", "loadint 7","add","loadint 6","loadint 2", "sub", "mul"};

    int result = VM(sum, 7);
    printf("result = %d", result);



    return 0;
}