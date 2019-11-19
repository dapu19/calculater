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


    // open specified file, weirdly must be absolute path
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


        // while not end of file
        while ((ch = fgetc(fp)) != EOF)
        {

            char str = ch;
            char * ops = "";



            // if operator
            if (strncmp(&ch,"+", 1) == 0  || strncmp(&ch,"-", 1) == 0 || strncmp(&ch,"*", 1) == 0 ||
            strncmp(&ch,"/", 1) == 0 || strncmp(&ch,"(", 1) == 0 || strncmp(&ch,")", 1) == 0 ||
            strncmp(&ch,"^", 1) == 0 || strncmp(&ch,"%", 1) == 0){


                // if no number to be added, add current number to array before adding operator
                if (number){
                    number = false;

                    printf("\n %s \n", tempnum);
                    // add to position i in sum
                    strcpy(sum[i], tempnum);
                    i++;

                    // clear tempnum for next number
                    memset(tempnum, 0, sizeof(tempnum));

                }


                // add operator

                printf("\n operator \n");
                size_t len = strlen(ops);
                // alocate appropriate to var str2
                char *str2 = malloc(len + 1 + 1);
                // copy the op character to str2
                strcpy(str2, ops);
                str2[len] = str;
                // add end character
                str2[len + 1] = '\0';

                // add op to position i in sum
                strcpy(sum[i], str2);
                free(str2);
                i++;
            }else{
                if (!number) {
                    // first number
                    number = true;
                }



                size_t len = strlen(strs);
                char *str2 = malloc(len + 1 + 1);
                strcpy(str2, strs);
                str2[len] = str;
                str2[len + 1] = '\0';

                // concatenates number being looked at to tempnum var to be later added to the sum array
                strcat(tempnum, str2);

                free(str2);



            }
        }

        printf("Closing the file \n");

        fclose(fp);

        for(int j = 0; j < i; j++){
            printf("%s \n ", sum[j]);
        }

        // call I2P here
    }



}