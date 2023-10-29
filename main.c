#include "./headers/screens.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Author:    Bernardo Gualberto
 * Created:   28.09.2023
 *
 * (c) Copyright by Museu do Presente.
 **/

int main(void)
{
    system("clear");
    
    do
    {
        printf("\n\n••••••••••••• Gerenciamento de Museu •••••••••••••\n\n");

        printf("\tTELAS:\n");
        printf("\n\t[ 1 ] - Temas");
        printf("\n\t[ 2 ] - Pesquisa");
        printf("\n\t[ 3 ] - Bilheteria");
        printf("\n\t[ 4 ] - Login");

        printf("\n\n\t[ 0 ] - Fechar");

        printf("\n\n••••••••••••••••••••••••••••••••••••••••••••••••••\n\n");

        printf("Escolha a tela: ");

        int entrada;
        scanf("%i", &entrada);

        if (entrada == 1 || entrada == 2 || entrada == 3 || entrada == 4)
        {
            switch (entrada)
            {
            case 1:
                tema();
                break;
            case 2:
                pesquisa();
                break;
            case 3:
                bilheteria();
                break;
            case 4:
                login();
                break;
            }

            break;
        }
        else if (entrada == 0)
        {
            exit(1);
        }
        else
        {
            system("clear");
            printf("Digite um número válido");
        }

        printf("\n\n");
    } while (2 > 1);
    return 0;
}