#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h>

#define size 10

struct stack {
    int count;
    char stack[size];
} s;

void stack_push(char c) {
    if(s.count < size) {
        s.stack[s.count] = c;
        s.count += 1;
    }
}

char stack_pop() {
    char item;
    if(s.count > 0) {
        s.count -= 1;
        item = s.stack[s.count];
    }
    return item;
}

int stack_isEmpty() {
    return s.count == 0;
}

char stack_topChar() {
    return s.stack[s.count - 1];
}

int isOperand(char c) {
    return isdigit(c);
}

char* operators = "+-*/^\0";

int isOperator(char c) {
    int result = 0;
    for(int i = 0; operators[i] != '\0'; i ++) {
        if(operators[i] == c) {
            result = 1;
            break;
        }
    }
    return result;
}

int getPrecedence(char c) {
    int result = 0;
    for(int i = 0; operators[i] != '\0'; i ++) {
        result ++;
        if(operators[i] == c) {
            if(c == '-' || c == '/')
                result --;
            break;
        }
    }
    return result;
}

int getPrecedenceV2(char c) {
    int result = 0;
    switch(c) {
        case '^': result ++;
        case '/':
        case '*': result ++;
        case '-':
        case '+': result ++;
    }
    return result;
}

void printResult(char array[]) {
    for(int i = 0; array[i]; i++) {
        if(array[i] != '\0')
            printf("%c", array[i]);
    }
}

void toPostfix(char* expression) {
    char result[100];
    int idx = 0;
    for(int i = 0; expression[i] != '\0'; i ++) {
        char c = expression[i];
        if(isOperand(c)) {
            if(result[idx] == '#')
                idx++;
            result[idx++] = c;
        } else if(isOperator(c)) {
            if(result[--idx] != '#') {
                idx++;
                result[idx++] = '#';
            }
            char topChar;
            while(1) {
                topChar = stack_topChar();
                if(stack_isEmpty() || topChar == '(') {
                    stack_push(c);
                    break;
                } else {
                    int precedenceC = getPrecedence(c);
                    int precedenceTC = getPrecedence(topChar);

                    if(precedenceC > precedenceTC) {
                        stack_push(c);
                        break;
                    } else {
                        char cpop = stack_pop();
                        result[idx++] = cpop;
                    }
                }
            }
        } else if(c == '(') {
            stack_push(c);
            if(idx != 0)
                if(result[--idx] != '#') {
                    idx++;
                    result[idx++] = '#';
                }
        } else if(c == ')') {
            if(result[--idx] != '#') {
                idx++;
                result[idx++] = '#';
            }
            char cpop = stack_pop();
            while(cpop != '(') {
                result[idx++] = cpop;
                cpop = stack_pop();
            }
        }
    }
    while(!stack_isEmpty()) {
        result[idx++] = '#';
        char c = stack_pop();
        result[idx++] = c;
    }
    result[idx] = '\0';
    printResult(result);
    //printf("%s", result);


    int init_size = strlen(result);
    char delim[] = "#";
    char outsrting[200][8];
    int z = 0;

    char *ptr = strtok(result, delim);

    while(ptr != NULL)
    {
        printf("'%s'\n", ptr);
        strcpy(outsrting[z], ptr);
        ptr = strtok(NULL, delim);
        z++;
    }
    for(int j = 0; j < z ; j++){
        printf("%s \n ", outsrting[j]);

    }
}

int InfixToPostfix(char* expression) {
    toPostfix(expression);
    return 0;
}
/*
int main() {
    printf("Insert expression: ");
    char* expression;
    char c;
    int idx = 0;
    do {
        c = getchar();
        if(c == '\n' || c == EOF)
            c = '\0';
        expression[idx++] = c;
    }
    while(c != '\0');
    toPostfix(expression);
    return 0;
}
 */