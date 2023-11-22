#include "../headers/screens.h"
#include "../headers/database.h"
#include "../headers/errormsg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * Author:    Matheus && Matheus Moreira
 * Created:   27.10.2023
 *
 * (c) Copyright by Museu do Presente.
 **/

int bilheteria()
{
    system("clear");

    char nome_titular[255];
    char numero_cartao[1024];
    int tipoDeIngresso, idade, opcao_pagamento, mes_validade, ano_validade;
    const float precoBase = 20.99;
    float preco = 20.99;

    printf("•••••• BILHETERIA ••••••\n");

    while (1)
    {
        printf("\n\tIngressos:\n");

        printf("\n\t[ 1 ] - Inteira (R$%.2f)", preco);
        printf("\n\t[ 2 ] - Meia (R$%.2f)", preco / 2);

        printf("\n\n\t[ 0 ] - Voltar");

        printf("\n\n••••••••••••••••••••••••••••••••••••••••••••••••••\n\n");

        printf("\t\nQual o tipo de ingresso: ");
        scanf("%d", &tipoDeIngresso);

        if (tipoDeIngresso == 0)
            main();

        if (tipoDeIngresso == 2)
        {
            printf("\t\nDigite a sua idade: ");
            scanf("%d", &idade);

            if (idade < 0 || idade <= 12 || idade >= 60)
            {
                preco = precoBase / 2;
                printf("\t\nO valor do seu ingresso, ficou: R$%.2f", preco);
            }
            else
            {
                system("clear");
                error_msg("Você não tem direito a meia entrada");
                continue;
            }
        }

        // Solicitar a forma de pagamento
        printf("\t\nForma de pagamento:\n");
        printf("\t\n [ 1 ] - Cartão de Crédito");
        printf("\t\n [ 2 ] - Cartão de Débito");
        printf("\t\n\nDigite a opção desejada: ");
        scanf("%d", &opcao_pagamento);

        printf("\t\nTitular do cartão: ");
        scanf("%s", nome_titular);

        printf("\t\nNúmero do cartão (16 dígitos): ");
        scanf("%s", numero_cartao);

        if (strlen(numero_cartao) != 16)
        {
            system("clear");
            preco = precoBase; // reinicia o preço
            error_msg("Cartão inválido :/");
            continue;
        }

        if (opcao_pagamento == 1)
        {
            printf("Mês de validade do cartão: ");
            scanf("%d", &mes_validade);

            if (mes_validade > 12)
            {
                system("clear");
                error_msg("Mês inválido :/");
                continue;
            }

            printf("Ano de validade do cartão: ");
            scanf("%d", &ano_validade);

            if (ano_validade < 23)
            {
                system("clear");
                error_msg("Cartão vencido :/");
                continue;
            }
        }

        // Gere um código de ingresso aleatório
        srand(time(NULL));
        int codigo_ingresso = rand() % 10000; // Código aleatório de 4 dígitos

        printf("\x1b[32m");
        printf("\n\n---------------------------------------\n");
        printf("\tINGRESSO:\n");
        printf("\n");
        printf("\tTitular: %s\n", nome_titular);
        printf("\tPreço: R$%.2f\n", preco);
        printf("\tCódigo do ingresso: %d\n", codigo_ingresso);
        printf("---------------------------------------\n");
        printf("\33[0m");

        char data[1024];
        snprintf(data, sizeof(data), "%d;", codigo_ingresso);

        write_csv("b", data);

        printf("\n\t[ 0 ] - Voltar\n\t");

        printf("Digite: ");
        int voltar;
        scanf("%i", &voltar);
        if (voltar == 0)
        {
            main();
            break;
        }

        break; // Sai do loop quando a compra é concluída
    }

    return 0;
}