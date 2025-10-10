#include "headers/parser.h"
#include "headers/builtin.h"
#include<string.h>
#include <stdio.h>

//this function for test if a command is intern or extern
int check_commande(char *args[]){
    int i = 0;

    while (builtin[i] != NULL) {
        
        if(strcmp(args[0],builtin[i]) == 0){
            
            return 1;
        }

        i++;
    }

    return 0;

}

//Function for remove $ on in variable
char *parse_word(char *str){
  
    if(str[0] == '$'){
        return str + 1;
    }

    return str;
}

//function parsing string for get > symbol
char *parse_redirection(char *args[]){

    int i = 0;
    char *filename;

    while (args[i] != NULL) {


        if(args[i+1] != NULL && strcmp(args[i + 1], ">") == 0){
            
            if(args[i+2] == NULL){
                return NULL;
            }

            filename = args[i+2];
            
            args[i+1] = NULL;
            return filename;
        }

        i++;
    }
    return NULL;
}