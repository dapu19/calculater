#include <stdio.h>
#include "VM.h"
void calculate(char arr[120]);


int main() {
    printf("Hello, World!\n");
    char sum[6][1] = {{"+"},{"-"}, {"*"}, {"/"}, {"5"}, {"7"}};

    calculate(sum, 6);
    return 0;
}