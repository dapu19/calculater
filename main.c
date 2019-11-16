#include <stdio.h>
#include "VM.h"
int calculate(char arr[120], int size);


int main() {
    printf("Hello, World!\n");
    char sum[][40] = { "loadint 4", "loadint 5","loadint 7","loadint 2","add", "sub", "mul"};

    int result = calculate(sum, 7);
    printf("result = %d", result);
    return 0;
}