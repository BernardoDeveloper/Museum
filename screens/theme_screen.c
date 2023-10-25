#include "../headers/tema.h"
#include "../resources/struct.c"
#include "../headers/pesquisa.h"
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
    int parsed = sscanf(theme, "%d;\"%99[^\"]\";\"%8191[^\"]\";%d;", &data.id, data.titulo, data.texto, &data.nota);

    printf("\n\n••••••••••••• %s •••••••••••••\n\n", data.titulo);

    printf("\t%s\n", data.texto);

    printf("\n\n••••••••••••••••••••••••••••••••••••••••••••••••••\n\n");

    printf("Deseja realizar a pesquisa de satisfação relacionada ao tema? (y/n) ");

    char input;
    input = getchar();
    scanf("%c", &input);

    if (input == 'y') {
        pesquisa();
    } else {
        // TODO: Verificação de ERRO
        printf("FODA-SE SAI DAQUI\n");
    }

    return 0;
}