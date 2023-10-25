#include "../headers/tema.h"
#include "../resources/struct.c"
#include <stdio.h>
#include <stdlib.h>

int theme_screen(int theme_id)
{
    system("clear");

    int digit = snprintf(NULL, 0, "%d", theme_id);
    char *digitToString = (char *)malloc(theme_id);

    snprintf(digitToString, digit + 1, "%d", theme_id);

    struct TemaRow data;
    char* theme = read_csv("t", digitToString);
    int parsed = sscanf(theme, "%d;\"%99[^\"]\";\"%99[^\"]\";%d;", &data.id, data.titulo, data.texto, &data.nota);

    printf("\n\n••••••••••••• %s •••••••••••••\n\n", data.titulo);

    printf("\t%s\n", data.texto);

    printf("\n\n••••••••••••••••••••••••••••••••••••••••••••••••••\n\n");

    return 0;
}