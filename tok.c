//
// Created by david on 18/11/2019.
//
#include "tok.h"

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>



void Tok(){
    FILE *fp;
    char data[500];


    fp = fopen("C:\\Users\\david\\CLionProjects\\calculater\\file.txt", "r");

    char ch;
    char sum[240];
    int count = 0;
    bool number = false;
    char numberHolder[120] = "";
    int i = 0;
    if ( fp == NULL )
    {
        printf( "Could not open file \n" );
    }
    else{
        printf("found\n");

        while ((ch = fgetc(fp)) != EOF)
        {

            if (strncmp(&ch,"+", 1) == 0  || strncmp(&ch,"-", 1) == 0 || strncmp(&ch,"*", 1) == 0 ||
            strncmp(&ch,"/", 1) == 0 || strncmp(&ch,"(", 1) == 0 || strncmp(&ch,")", 1) == 0){
                if (number){
                    printf("adding number %s", &numberHolder);
                    sum[count] = numberHolder;
                    count++;
                }
                printf("\n operator");
                sum[count] = ch;
                count++;
            }else{
                if (!isdigit(ch)){
                    printf("invalid input");
                    continue;

                }else
                {
                    printf("number");
                    if (number){
                        char src[50];
                        char dest[50];

                        strcpy(dest, numberHolder);
                        printf(dest);
                        strcat( dest, &ch);
                        printf("cat\n");
                        printf("%s", numberHolder);
                    }
                    number = true;
                    numberHolder[0] = ch;
                }
                printf("\n %c \n", ch);
                //printf("%c", numberHolder);
            }


        }

        printf("Closing the file \n");
        fclose(fp);
    }



}