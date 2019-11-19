//
// Created by david on 09/11/2019.
//

#include "VM.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int VM(char arr[120][40], int size){
    printf("calculate \n");
    size_t i = 0;
    int stack[32];
    int stptr = 0;
    // loop array
    for(int i = 0; i < size; i++) {


        //if operands
        if (strncmp(arr[i] ,"add", 1) == 0) {

            int a = stack[stptr -1];
            stptr--;
            int b = stack[stptr -1];
            stptr--;
            printf("%d + %d = %d \n", b, a, b+a);
            stack[stptr] = b+a;
            stptr++;


        } else if (strncmp(arr[i] ,"sub", 1) == 0) {

            int a = stack[stptr -1];
            stptr--;
            int b = stack[stptr -1];
            stptr--;
            printf("%d - %d = %d \n", b, a, b-a);
            stack[stptr] = b - a;
            stptr++;
        } else if (strncmp(arr[i] ,"mul", 1) == 0) {

            int a = stack[stptr -1];
            stptr--;
            int b = stack[stptr -1];
            stptr--;
            printf("%d * %d = %d \n", b, a, b*a);
            stack[stptr] = b*a;
            stptr++;
        } else if (strncmp(arr[i] ,"div", 1) == 0) {

            int a = stack[stptr -1];
            stptr--;
            int b = stack[stptr -1];
            stptr--;
            printf("%d / %d = %d \n", b, a, b/a);
            stack[stptr] = b/a;
            stptr++;
        }
        //if not operator, remove chars from string, then append int to stack
        else{
            if (strncmp(arr[i] ,"0", 1) != 0){

                char  *str = arr[i], *ptr = str ;
                while (*ptr) {
                    if (isdigit(*ptr)) {
                        // assigns the number part to the long val
                        long val = strtol(ptr, &ptr, 10);

                        // converts the long to an int
                        int g = (int)val;

                        // pushes g to stack
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


    return stack[0];

}