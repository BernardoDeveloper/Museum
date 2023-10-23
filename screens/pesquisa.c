#include "../headers/pesquisa.h"
#include "../headers/database.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pesquisa()
{
    system("clear"); // Limpa a tela

    int tema, pontuacao, num;
    char nome[40];

    // Cabeçalho para visualização
    printf("\n\n••••••••••••• Pesquisa •••••••••••••\n\n");

    printf("\tPERGUNTAS:\n");

    // Pegar os dados do usuário
    // TODO: Colocar uma verificação para deifinir um limite de 13 caracteres
    printf("\n\t1 - Qual o seu nome: ");
    fgets(nome, 40, stdin);
    scanf("%s", nome);

    printf("\n\t2 - Qual tema você mais gostou: ");
    scanf("%i", &tema);
    // Aviso caso o tema escolhido seja inválido.
    if (tema > 4)
    {
        printf("\n\n••••••••••••• Este não é válido! •••••••••••••\n\n");

        // Botão voltar

        printf("\n\t[ Pressione: 1 ] Para voltar.\n\t");

        int voltar;
        scanf("%i", &voltar);

        if (voltar == 1)
        {
            switch (voltar)
            {
            case 1:
                pesquisa();
                break;
            }
        }
        return 0;
    }

    printf("\n\t3 - Qual a sua nota para o tema %i de [0-10]: ", tema);
    scanf("%i", &pontuacao);

    printf("\n\tOrigado pela participação ;)\n");
    printf("\n\n••••••••••••••••••••••••••••••••••••••••••••••••••\n\n");

    // Inicializando um tempo para gerar os ID's aleatórios.
    srand(time(NULL));
    int id = rand() % 101;

    char dados[1024];
    snprintf(dados, sizeof(dados), "%i;%s;%i;%i;", id, nome, tema, pontuacao);

    // Escrever no arquivo os dados que ele inseriu
    write_csv("u", dados);

    // TODO: Perguntar se o usuário quer fechar o programa ou voltar a tela inicial

    return 0;
}