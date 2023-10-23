#include "../headers/tema.h"
#include "../headers/database.h"
#include <stdio.h>
#include <stdlib.h>

int tema()
{
    system("clear"); // Limpa a tela

    printf("\n\n••••••••••••• Tema •••••••••••••\n\n");

    printf("\tTEMA:\n");
    printf("\n\t[ - ] - Vazio");

    printf("\n\n\t[ 0 ] - Fechar");

    printf("\n\n••••••••••••••••••••••••••••••••••••••••••••••••••\n\n");

    read_csv("t", "1");

    return 0;
}