//
// Created by david on 18/11/2019.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "VM.h"
#include "CG.h"

int VM(char arr[120], int size);

void CG(char arr[120][40], int size){
    printf("generate \n");
    printf("%d", size);
    // for ever item in the input array
    for(int i = 0; i < size; i++) {
        printf("forloop \n");

        // if item is operator replace with code equivalent
        if (strncmp(arr[i] ,"+", 1) == 0){

            strcpy(arr[i], "add");
            printf("added \n");

        }
        else if (strncmp(arr[i] ,"-", 1) == 0){

            strcpy(arr[i], "sub");
        }else if (strncmp(arr[i] ,"^", 1) == 0){

            strcpy(arr[i], "power");
        }
        else if (strncmp(arr[i] ,"%", 1) == 0){

            strcpy(arr[i], "mod");
        }
        else if (strncmp(arr[i] ,"*", 1) == 0){

            strcpy(arr[i], "mul");
        }
        else if (strncmp(arr[i] ,"/", 1) == 0){

            strcpy(arr[i], "div");
        }else{
            // if number append loadint to the start
            if ((strncmp(arr[i]," ", 1) != 0 )) {
                char code[40] = "loadint ";
                strcat(code, arr[i]);
                printf("%s", code);
                strcpy(arr[i], code);
            }
        }
    }

    // call VM
    printf("got result");
    int result = VM(arr, size);
    printf("result = %d", result);



}