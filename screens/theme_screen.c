#include "../headers/screens.h"
#include "../headers/errormsg.h"
#include "../resources/struct.c"
#include <stdio.h>
#include <stdlib.h>

/**
 * Author:    Bernardo Gualberto
 * Created:   21.10.2023
 *
 * (c) Copyright by Museu do Presente.
 **/

int theme_screen(int theme_id)
{
    do
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

        if (input == 'y' || input == 'Y') {
            pesquisa();
            break;
        }
        else if (input == 'n' || input == 'N')
        {
            main();
            break;
        }
        else
        {
            system("clear");
            error_msg("Valor inválido");
        }
    } while (2 > 1);

    return 0;
}