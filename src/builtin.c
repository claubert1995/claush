#include "headers/builtin.h"
#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<string.h>

char *builtin[] ={
    "exit",
    "cd",
    "echo",
    "pwd",
    "env",
    NULL
};


void dispacth(char *args[]){
    if (strcmp(args[0], "cd") == 0) {
        builtin_cd(args);
    }
    else if(strcmp(args[0], "echo") == 0){
        builtin_echo(args);
    }
    else if(strcmp(args[0], "pwd") == 0){
        builtin_pwd();
    }
    else if (strcmp(args[0], "env") == 0) {
        builtin_env(args);
    }
    else{
        printf(ANSI_COLOR_ROUGE "Command not found" ANSI_COLOR_RESET);
    }
}

//this function implement command CD
void builtin_cd(char *args[]){

    if(args[2] != NULL){
        printf("Too many argument \n");
        return;
    }
    else if(args[1] == NULL){
        if(getenv("HOME") == NULL){
            printf("Erreur");
            return;
        }

        if(chdir(getenv("HOME")) != 0){
            perror("Access denied: ");
        }
    }
    else{
        if(chdir(args[1]) != 0){
            perror(" ");
        }
    }
  
}

//this function implement command CD
void builtin_echo(char *args[]){
    
    int i = 1;

    while (args[i] != NULL) {
        printf("%s",args[i]);
        if(args[i+1]  != NULL ){
            printf(" ");
        }

        i++;
    }
    printf("\n");
}

//this builtin function PWD
void builtin_pwd(){
    char dir[PATH_BUF];

    if (getcwd(dir, PATH_BUF) != NULL) {
        printf("%s\n",dir);
    } 
    else {
        perror(" ");
    }
    
}

//function env
void builtin_env(char *args[]){

    char **current_env = environ;
    while (*current_env != NULL) {
        printf("%s\n",*current_env);
        current_env++;
    }
}