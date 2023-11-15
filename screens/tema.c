#include "../headers/screens.h"
#include "../headers/database.h"
#include "../resources/struct.c"
#include <stdio.h>
#include <stdlib.h>

/**
 * Author:    Bernardo Gualberto
 * Created:   11.10.2023
 *
 * (c) Copyright by Museu do Presente.
 **/

int tema()
{
    system("clear"); // Limpa a tela

    do
    {
        printf("\n\n••••••••••••• Tema •••••••••••••\n\n");

        printf("\tTEMA:\n");

        // Reapeat four times show the themes with base in file
        struct TemaRow data;
        struct TemaRow arraySorted[4];

        for (int index = 1; index <= 4; index++)
        {
            // Transform int index to char value
            int digit = snprintf(NULL, 0, "%d", index);
            char *digitToString = (char *)malloc(index);

            snprintf(digitToString, digit + 1, "%d", index);

            char *theme = read_csv("t", digitToString); // If use daynamic value them return an ERROR

            if (theme == NULL)
            {
                printf("Error: Line not found in CSV file\n");
                return 1;
            }

            int parsed = sscanf(theme, "%d;\"%99[^\"]\";\"%8191[^\"]\";%d;", &data.id, data.titulo, data.texto, &data.nota);

            if (parsed != 4)
            {
                printf("Error: Failed to parse CSV line\n");
                return 1;
            }

            printf("\n\t[ %d ] - %s - %d", data.id, data.titulo, data.nota);
        }

        printf("\n\n\t[ 0 ] - Fechar");

        printf("\n\n••••••••••••••••••••••••••••••••••••••••••••••••••\n\n");

        printf("Escolha o tema: ");

        int input;
        scanf("%i", &input);

        if (input == 1 || input == 2 || input == 3 || input == 4)
        {
            switch (input)
            {
            case 1:
                theme_screen(1);
                break;
            case 2:
                theme_screen(2);
                break;
            case 3:
                theme_screen(3);
                break;
            case 4:
                theme_screen(4);
                break;
            }
            break;
        }
        else if (input == 0)
        {
            exit(1);
        }
        else
        {
            system("clear");
            printf("Digite um número válido");
        }
    } while (2 > 1);
    return 0;
}