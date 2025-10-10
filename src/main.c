#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include "headers/builtin.h"
#include "headers/parser.h"
#include "headers/extern.h"
#define MAX_ARGS 30 // La taille que vous utilisez pour args[]
/*
|--------------------------------------------------------------
|NAME: CLAUSH ( CLAUBERT SHELL )
|AUTHOR: JONASSON CLAUBERT JOACHIN
|VERSION: 1.0.0
|DATE: 27 September 2025
|--------------------------------------------------------------
*/

int main(void){

    char cmd_line[MAX_SIZE];//Line for get input user
    int continu = 1; //variable for exit the loop 1 = true or 0 = false
    char *token; // variable for stock token from strtok()
    char *args[MAX_SIZE];
    char path[PATH_BUF];
    char *file_redirect; //gettter for filename 

    printf("claush - version 1.0.0 - copyright 2025\n");
    chdir("/home");

    do {
        memset(args, 0, sizeof(char *) * MAX_ARGS); 
        printf(ANSI_COLOR_VERT "[%s@claush: %s] -> "ANSI_COLOR_RESET,getenv("USER"),
            getcwd(path, PATH_BUF));

        //get command from user
        if(fgets(cmd_line,MAX_SIZE,stdin) == NULL){
            continu = 0;
            break;
        } 
        
        size_t len = strlen(cmd_line);
        if(len > 0 && cmd_line[len - 1] == '\n'){
            cmd_line[len - 1] = '\0'; //replace \n -> \0
        }

        token = strtok(cmd_line," ");
        int i = 0;

        //loop for add token on argument variable
        while (token != NULL) {
            args[i] = token;
            i++;

            token = strtok(NULL," ");
        }

        args[i] = NULL;
        //check if args is empty
        if (args[0] == NULL) {
            continue;
        }

        if(strcmp(args[0],"exit") == 0){
            continu = 0;
        }
        
        file_redirect = parse_redirection(args);

        if(file_redirect != NULL){

            extern_command_redirection(args, file_redirect);
        }
        else{
            if(check_commande(args) == 1) {
                dispacth(args);
            }
            else{
                extern_command(args);
            }
        }
        
    }while(continu);

    printf("Good Bye\n");
    return 0;
}