//
// Created by david on 09/11/2019.
//

#include "VM.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void calculate(char arr[120][2], int size){
    printf("calculate \n");
    size_t i = 0;
    int stack[32];
    int stptr = 0;
    for( i = 0; i < size; i++) {
        char r = arr[0][i];

        if (strncmp(&r ,"+", 1) == 0) {
            printf("plus \n");

        } else if (strncmp(&r ,"-", 1) == 0) {
            printf("minus \n");
        } else if (strncmp(&r ,"*", 1) == 0) {
            printf("mul \n");
        } else if (strncmp(&r ,"/", 1) == 0) {
            printf("div \n");
        }
        else{
            if (strncmp(&r ,"0", 1) != 0){
                printf("hi %c \n", r);

                char *ptr;
                long ret;
                ret = strtol(&r, &ptr, 10);

                int g = (int)ret;
                printf("%d \n",g);

                stack[stptr] = g;
                stptr++;

            }
        }

    }
    for( i = 0; i < stptr; i++){
        printf("%d", stack[i]);
    }
}