#include "../headers/errormsg.h"

void red () {
    printf("\033[1;31m");
}

void reset () {
    printf("\033[0m");
}

char *error_msg(char text[]) {
    red();
    printf("--------------------------------------------------------\n");
    printf("\n     [ERRO]: %s\n\n", text);
    printf("--------------------------------------------------------\n");
    reset();
}