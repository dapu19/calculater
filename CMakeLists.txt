cmake_minimum_required(VERSION 3.15)
project(calculater C)

set(CMAKE_C_STANDARD 99)

add_executable(calculater main.c VM.c VM.h CG.c CG.h Infix2Postfix.c Infix2Postfix.h)