//
// Created by david on 09/11/2019.
//

#include "VM.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int calculate(char arr[120][40], int size){
    printf("calculate \n");
    size_t i = 0;
    int stack[32];
    int stptr = 0;
    // loop array
    for( i = 0; i < size; i++) {
        char r = arr[i];
        printf(" est %s \n ", arr[i]);

        //if operands
        if (strncmp(arr[i] ,"add", 1) == 0) {
            printf("add \n");
            int a = stack[stptr -1];
            stptr--;
            int b = stack[stptr -1];
            stptr--;
            printf("%d + %d = %d", a, b, a+b);
            stack[stptr] = a+b;
            stptr++;


        } else if (strncmp(arr[i] ,"sub", 1) == 0) {
            printf("sub \n");
            int a = stack[stptr -1];
            stptr--;
            int b = stack[stptr -1];
            stptr--;
            printf("%d - %d = %d", a, b, a-b);
            stack[stptr] = a-b;
            stptr++;
        } else if (strncmp(arr[i] ,"mul", 1) == 0) {
            printf("mul \n");
            int a = stack[stptr -1];
            stptr--;
            int b = stack[stptr -1];
            stptr--;
            printf("%d * %d = %d", a, b, a*b);
            stack[stptr] = a*b;
            stptr++;
        } else if (strncmp(arr[i] ,"div", 1) == 0) {
            printf("div \n");
            int a = stack[stptr -1];
            stptr--;
            int b = stack[stptr -1];
            stptr--;
            printf("%d / %d = %d", a, b, a/b);
            stack[stptr] = a/b;
            stptr++;
        }
        //if not operator, remove chars from string, then append int to stack
        else{
            if (strncmp(arr[i] ,"0", 1) != 0){
                printf("hi %s \n", arr[i]);
                char  *str = arr[i], *ptr = str ;
                while (*ptr) {
                    if (isdigit(*ptr)) {
                        long val = strtol(ptr, &ptr, 10);
                        printf("%ld\n", val);
                        int g = (int)val;
                        printf("%d \n %c",g , *ptr);

                        stack[stptr] = g;
                        stptr++;
                    } else {
                        ptr++;
                    }
                }



                /*char *ptr;
                long ret;
                ret = strtol(arr[i], &ptr, 10);

                printf("%ld" , ret);
                int g = (int)ret;
                printf("%d \n %c",g , *ptr);

                stack[stptr] = g;
                stptr++;
                */
            }
        }

    }

    printf(" Stack \n %d \n", stack[0]);
    return stack[0];

}