#include "headers/extern.h"
#include <stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include "headers/builtin.h"
#include <fcntl.h>

//this function for execution extern command
void  extern_command(char *args[]){
    pid_t processus;
    
    fflush(stdout);

    processus = fork();

    if(processus < 0){
        perror("Process create  error\n");
    }
    else if(processus == 0){
        execvp(args[0], args);

        perror(ANSI_COLOR_ROUGE "Claush: Command not found" ANSI_COLOR_RESET);
        exit(EXIT_FAILURE);
    }
    else{
        wait(NULL);
        
    }
}

//this function for execution extern command with redirection
void  extern_command_redirection(char *args[],const char *filename){
    pid_t processus;
    
    fflush(stdout);

    processus = fork();

    if(processus < 0){
        perror("Process create  error\n");
    }
    else if(processus == 0){

        int desc = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);

        if (desc < 0) {
            perror("claus: Error file description\n");
            exit(EXIT_FAILURE);
        }

        if(dup2(desc, STDOUT_FILENO) < 0){
            perror("Claush: error dup2\n");
            close(desc);
            exit(EXIT_FAILURE);
        }

        close(desc);

        execvp(args[0], args);

        perror(args[0]);
        printf("\n");
        exit(EXIT_FAILURE);

    }
    else{
        wait(NULL);
        
    }
}