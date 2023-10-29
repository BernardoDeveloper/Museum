#include "../headers/screens.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Author:    Matheus Corsa
 * Created:   27.10.2023
 *
 * (c) Copyright by Museu do Presente.
 **/

int bilheteria() {
    int quantidade_ingressos;
    int tipo_ingresso; // 1 para inteira, 2 para meio ingresso
    float preco_inteira = 10.0;
    float preco_meio = 5.0;
    float total_venda;
    int opcao_pagamento;
    char nome_titular[100];
    char numero_cartao[16];
    int mes_validade, ano_validade;

    printf("•••••• BILHETERIA ••••••\n");

    while (1) {
        // Solicitar a quantidade de ingressos
        printf("\nQuantos ingressos deseja comprar? ");
        scanf("%d", &quantidade_ingressos);

        // Solicitar o tipo de ingresso
        printf("Escolha o tipo de ingresso:\n");
        printf("1 - Inteira (R$%.2f)\n", preco_inteira);
        printf("2 - Meio (R$%.2f)\n", preco_meio);
        printf("Digite o número correspondente: ");
        scanf("%d", &tipo_ingresso);

        if (tipo_ingresso != 1 && tipo_ingresso != 2) {
            printf("Tipo de ingresso inválido. Por favor, insira 1 para inteira ou 2 "
                    "para meio ingresso.\n");
            continue; // Reinicia o loop para que o usuário insira dados corretos
        }

        if (tipo_ingresso == 1) {
            total_venda = quantidade_ingressos * preco_inteira;
        } else {
            total_venda = quantidade_ingressos * preco_meio;
        }

        // Imprimir o recibo
        printf("\nRecibo de Compra:\n");
        printf("Quantidade de ingressos: %d\n", quantidade_ingressos);
        printf("Tipo de ingresso: %s\n", (tipo_ingresso == 1) ? "Inteira" : "Meio");
        printf("Total a pagar: R$%.2f\n", total_venda);

        // Solicitar a forma de pagamento
        printf("\nEscolha a forma de pagamento:\n");
        printf("1 - Cartão de Crédito\n");
        printf("2 - Cartão de Débito\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao_pagamento);

        if (opcao_pagamento == 1) {
            printf("Digite o nome do titular do cartão: ");
            scanf("%s", nome_titular);
            printf("Digite o número do cartão de crédito (16 dígitos): ");
            scanf("%s", numero_cartao);
            printf("Digite o mês de validade do cartão: ");
            scanf("%d", &mes_validade);
            printf("Digite o ano de validade do cartão: ");
            scanf("%d", &ano_validade);

            printf("\nProcessando o pagamento com cartão de crédito...\n");
            // Lógica de processamento do pagamento com cartão de crédito
        } else if (opcao_pagamento == 2) {
            printf("Digite o nome do titular do cartão: ");
            scanf("%s", nome_titular);
            printf("Digite o número do cartão de débito (16 dígitos): ");
            scanf("%s", numero_cartao);

            printf("\nProcessando o pagamento com cartão de débito...\n");
            // Lógica de processamento do pagamento com cartão de débito
        } else {
            printf("Opção de pagamento inválida. Por favor, insira 1 para cartão de "
                    "crédito ou 2 para cartão de débito.\n");
            continue; // Reinicia o loop para que o usuário insira dados corretos
        }

        // Gere um código de ingresso aleatório
        srand(time(NULL));
        int codigo_ingresso = rand() % 10000; // Código aleatório de 4 dígitos
        printf("Pagamento aprovado. Seu código de ingresso é: %d\n",
                codigo_ingresso);

        break; // Sai do loop quando a compra é concluída
    }

    return 0;
}