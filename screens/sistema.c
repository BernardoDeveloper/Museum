#include "../headers/screens.h"
#include <stdio.h>
#include <string.h>
#include <string.h>

const char *getfield(char *line, int num)
{
    const char *tok;
    for (tok = strtok(line, ",");
         tok && *tok;
         tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int sistema()
{
    system("clear");
    printf("\n\n••••••••••••• Sistema •••••••••••••\n\n");

    printf("\tDigite seu código (0 para voltar): ");

    char *code;
    scanf("%s", code);

    if (strcmp(code, "0"))
    {
        main();
    }

    FILE *stream = fopen("database/bilheteria.csv", "r");
    char line[1024];

    if (fgets(line, sizeof(line), stream) == NULL)
    {
        perror("Error reading CSV header");
        return NULL;
    }

    while (fgets(line, sizeof(line), stream) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "7657") == 0)
        {
            printf("Input matches one of the values.\n");
        }
        else
        {
            printf("Input does not match any of the values.\n");
        }
    }

    fclose(stream);

    printf("\tTELAS:\n");
    printf("\n\t[ 1 ] - Tema");
    printf("\n\t[ 2 ] - Pesquisa");

    printf("\n\n\t[ 0 ] - Fechar");

    printf("\n\n••••••••••••••••••••••••••••••••••••••••••••••••••\n\n");

    printf("Escolha a tela: ");

    int entrada;
    scanf("%i", &entrada);

    return 0;
}