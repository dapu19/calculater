//
// Created by david on 18/11/2019.
//
#include "tok.h"

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void Tok(){
    FILE *fp;
    char data[500];


    fp = fopen("C:\\Users\\david\\CLionProjects\\calculater\\file.txt", "r");

    char ch ;
    char sum[100][240];
    int i = 0;
    bool number = false;

    if ( fp == NULL )
    {
        printf( "Could not open file \n" );
    }
    else{
        printf("found\n");
        char * strs = "";
        char * tempnum = "";

        while ((ch = fgetc(fp)) != EOF)
        {

            char str = ch;



            if (strncmp(&ch,"+", 1) == 0  || strncmp(&ch,"-", 1) == 0 || strncmp(&ch,"*", 1) == 0 ||
            strncmp(&ch,"/", 1) == 0 || strncmp(&ch,"(", 1) == 0 || strncmp(&ch,")", 1) == 0){
                printf("\n operator");
                if (number){
                    number = false;

                }
            }else{
                if (number) {
                    size_t len = strlen(strs);
                    char *str2 = malloc(len + 1 + 1);
                    strcpy(str2, strs);
                    str2[len] = str;
                    str2[len + 1] = '\0';
                    //printf("\n %c", str);

                    //printf("\n %s", str2);
                    strcat(tempnum, str2);
                    free(str2);
                    printf(tempnum);
                }else{
                    number = true;
                    size_t len = strlen(strs);
                    char *str2 = malloc(len + 1 + 1);
                    strcpy(str2, strs);
                    str2[len] = str;
                    str2[len + 1] = '\0';

                    strcat(tempnum, str2);

                    free(str2);
                    printf(tempnum);

                }
            }





        }

        printf("Closing the file \n");
        fclose(fp);
    }



}