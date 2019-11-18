//
// Created by mattie on 18/11/2019.
//

#include "Infix2Postfix.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[240];
int top = -1;

int Infix2Postfix(char infixArray[], char postfixArray[240]) {
    int i = 0;
    int j = 0;
    char item;
    char temp;

    push('(');
    strcat(infixArray, ")");

    item = infixArray[i];

    while(item != '\0') {
        if (item == '(') {
            push(item);
        }else if (isNumber(item)) {
            postfixArray[j] = item;
            j++;
        }else if(isOperator(item)) {
            temp = pop();
            while(isOperator(temp) && precedence(temp) >= precedence(item)) {
                postfixArray[j] = temp;
                j++;
                temp = pop();
            }
            push(temp);
            push(item);
        }else if(item == ')') {
            temp = pop();
            while(temp != '(') {
                postfixArray[j] = temp;
                j++;
                temp = pop();
            }
        }else {
            printf("\nInvalid infix expression.\n");
            getchar();
            exit(1);
        }
        i++;
        item = infixArray[i];
    }
    if(top > 0) {
        printf("\nInvalid infix expression.\n");
        getchar();
        exit(1);
    }
    postfixArray[j] = '\0';
}

void push(char item) {
    stack[++top] = item;
}

char pop() {
    return(stack[top--]);
}

int precedence(char item) {
    if (item == '*' || item == '/')
        return 2;
    else if (item == '+' || item == '-')
        return 1;
    else
        return 0;
}

int isOperator(char item) {
    if (item == '+' || item == '-' || item == '*' || item == '/')
        return 1;
    else
        return 0;
}

int isNumber(char * item) {
    //Function takes in a string and checks if that string is a number
    if (item == NULL || *item == '\0')
        return 0;
    char * num;
    strtod(item, &num);
    return *num == '\0';
}