//
// Created by Rory O'Connor on 18/11/2019.
//
#include "tok.h"
#include "Infix2Postfix.h"

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int InfixToPostfix(char* array, int inSize);

char * Tok(){
    FILE *fp;


    // open specified file, weirdly must be absolute path
    fp = fopen("..\\file.txt", "r");

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

            char * str = ch;
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
                if (isdigit(str)) {
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
        }
        if (number){


            printf("\n %s \n", tempnum);
            // add to position i in sum
            strcpy(sum[i], tempnum);
            i++;

            // clear tempnum for next number
            memset(tempnum, 0, sizeof(tempnum));

        }

        printf("Closing the file \n");

        fclose(fp);


        char * mattsoutString = "";
        for(int j = 0; j < i ; j++){
            printf("%s \n ", sum[j]);

            char * toadd = strcat(sum[j], " ");
            //printf("\n%ssh\n", toadd);
            strcat(mattsoutString, toadd);

        }
        printf("%s \n", mattsoutString);
        //return mattsoutString;

        InfixToPostfix(mattsoutString, i);
        // call I2P here
    }



}