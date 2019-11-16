#include <stdio.h>
#include "VM.h"
int calculate(char arr[120], int size);


int main() {
    printf("Hello, World!\n");
    char sum[][40] = { "loadint 2", "loadint 2","loadint 8", "mul", "add"};

    int result = calculate(sum, 5);
    printf("result = %d", result);
    return 0;
}