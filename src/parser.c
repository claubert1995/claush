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