#pragma once

#define ANSI_COLOR_RESET    "\033[0m"
#define ANSI_COLOR_NOIR     "\033[30m"
#define ANSI_COLOR_ROUGE    "\033[31m"
#define ANSI_COLOR_VERT     "\033[32m"
#define ANSI_COLOR_JAUNE    "\033[33m"
#define ANSI_COLOR_BLEU     "\033[34m"
#define ANSI_COLOR_MAGENTA  "\033[35m"
#define ANSI_COLOR_CYAN     "\033[36m" 

#define MAX_SIZE 200
#define PATH_BUF 200 //number of charactere for string path
#include <stddef.h>

extern char *builtin[];
extern char **environ;

void dispacth(char *args[]);

void builtin_cd(char *args[]);

void builtin_echo(char *args[]);

void builtin_pwd();

void builtin_env(char *args[]);

char *parse_word(char *str);

