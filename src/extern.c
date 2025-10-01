#include "headers/extern.h"
#include <stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include "headers/builtin.h"
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