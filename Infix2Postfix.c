//
// Created by mattie on 18/11/2019.
//

#include "Infix2Postfix.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


void push(char item, char *pointerToMatthewsAwesomeStack, int top) {
    //printf("\nPushing");
    pointerToMatthewsAwesomeStack[++top] = item;
}

char pop(char *pointerToMatthewsAwesomeStack, int top) {
    //printf("\nPopping");
    return(pointerToMatthewsAwesomeStack[top--]);
}

int precedence(char item) {
    //printf("\nPrecedence");
    if (item == '*' || item == '/')
        return 2;
    else if (item == '+' || item == '-')
        return 1;
    else
        return 0;
}

int isOperator(char item) {
    //printf("\nOperator Check");
    if (item == '+' || item == '-' || item == '*' || item == '/')
        return 1;
    else
        return 0;
}

/*int isNumber(char * item) {
    printf("\nNumber Check");
    //Function takes in a string and checks if that string is a number
    if (item == NULL || *item == '\0')
        return 0;
    char * num;
    strtod(item, &num);
    return *num == '\0';
}

void printArray(char *pointerToArray[]) {
    int i;
    for(i = 0; i <= 10; i++) {
        printf("%s", pointerToArray[i]);
    }
}*/

int Infix2Postfix(char infixArray[][3], char postfixArray[]) {
    //printf("\nMain i2p function");
    //printf("\nInputted array: ");
    //printArray(infixArray);
    char MatthewsAwesomeStack[32];
    int top = -1;
    int i = 0;
    int j = 0;
    char item;
    char temp;

    push('(', MatthewsAwesomeStack, top);
    strcat((char *) infixArray, ")");

    item = *infixArray[i];

    while(item != '\0') {
        if (item == '(') {
            push(item, MatthewsAwesomeStack, top);
        }else if (isdigit(item)) {
            postfixArray[j] = item;
            j++;
        }else if(isOperator(item)) {
            temp = pop(MatthewsAwesomeStack, top);
            while(isOperator(temp) && precedence(temp) >= precedence(item)) {
                postfixArray[j] = temp;
                j++;
                temp = pop(MatthewsAwesomeStack, top);
            }
            push(temp, MatthewsAwesomeStack, top);
            push(item, MatthewsAwesomeStack, top);
        }else if(item == ')') {
            temp = pop(MatthewsAwesomeStack, top);
            while(temp != '(') {
                postfixArray[j] = temp;
                j++;
                temp = pop(MatthewsAwesomeStack, top);
            }
        }else {
            printf("\nInvalid infix expression no.1\n");
            exit(1);
        }
        i++;
        item = *infixArray[i];
    }
    if(top > 0) {
        printf("\nInvalid infix expression no.2\n");
        exit(1);
    }
    //printf("\nHere?");
    postfixArray[j] = '\0';
    //printf("\nOutputted array: ");
    //printArray(postfixArray);
    return 0;
}