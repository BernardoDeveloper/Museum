#include "../headers/tema.h"
#include "../headers/database.h"
#include "../resources/struct.c"
#include <stdio.h>
#include <stdlib.h>

int tema()
{
    system("clear"); // Limpa a tela

    printf("\n\n••••••••••••• Tema •••••••••••••\n\n");

    printf("\tTEMA:\n");

    // TODO: split the return of variable and get the specific data of a string, and return then
    

    struct TemaRow data;
    int index;
    for (index = 1; index <= 4; index++) {
        // char* theme = read_csv("t", "1"); - If run with fixed value return OK
        char* theme = read_csv("t", index); // If use daynamic value them return an ERROR

        if (theme == NULL) {
            printf("Error: Line not found in CSV file\n");
            return 1;
        }

        int parsed = sscanf(theme, "%d;\"%99[^\"]\";\"%99[^\"]\";%d;", &data.id, data.titulo, data.texto, &data.nota);

        if (parsed != 4) {
            printf("Error: Failed to parse CSV line\n");
            return 1;
        }

        printf("\n\t[ %d ] - %s", data.id, data.titulo);
    }

    printf("\n\n\t[ 0 ] - Fechar");

    printf("\n\n••••••••••••••••••••••••••••••••••••••••••••••••••\n\n");
   
    return 0;
}