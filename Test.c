//
// Created by david on 18/11/2019.
//
#include "VM.h"
#include "CG.h"
#include "Infix2Postfix.h"
#include "Test.h"
#include <ctap.h>


int InfixToPostfix(char* array, int inSize);

void CG(char arr[120][40], int size);
int VM(char arr[120], int size);

TESTS {
    char * li = {"loadint 2", "loadint 2", "loadint 8", "mul", "add"}
    char * liI2P = { "2", "+", "2", "*", "8"};




    is_int(VM(li, 5), "VM returns int");
    ok(VM(li, 5) == 18, "VM returns the appropriate value");

    ok(Infix2Postfix(liI2P, 5) == 0, "I2P terminates");

}

