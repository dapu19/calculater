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
    char sum[200][4];
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
            char * ops = "";



            if (strncmp(&ch,"+", 1) == 0  || strncmp(&ch,"-", 1) == 0 || strncmp(&ch,"*", 1) == 0 ||
            strncmp(&ch,"/", 1) == 0 || strncmp(&ch,"(", 1) == 0 || strncmp(&ch,")", 1) == 0){


                if (number){
                    number = false;

                    printf("\n %s \n", tempnum);
                    strcpy(sum[i], tempnum);
                    i++;
                    memset(tempnum, 0, sizeof(tempnum));

                }


                printf("\n operator \n");
                size_t len = strlen(ops);
                char *str2 = malloc(len + 1 + 1);
                strcpy(str2, ops);
                str2[len] = str;
                str2[len + 1] = '\0';


                strcpy(sum[i], str2);
                free(str2);
                i++;
            }else{
                if (!number) {
                    number = true;
                }


                size_t len = strlen(strs);
                char *str2 = malloc(len + 1 + 1);
                strcpy(str2, strs);
                str2[len] = str;
                str2[len + 1] = '\0';

                strcat(tempnum, str2);

                free(str2);



            }





        }

        printf("Closing the file \n");

        fclose(fp);

        for(int j = 0; j < i; j++){
            printf("%s \n ", sum[j]);
        }
    }



}