#include "../headers/screens.h"
#include "../headers/errormsg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

/**
 * Author:    Matheus Corsa && Hudson
 * Created:   23.10.2023
 *
 * (c) Copyright by Museu do Presente.
 **/


typedef struct
{
    char login[40];
    char senha[40];
} pessoa;
pessoa p[1]; // Reduzindo o nome da string para "p" e o "[[1]" é o máximo de pessoas com logins e senhas]

int login()
{
    system("clear"); // Limpa a tela

    // Cabeçalho para visualização
    printf("\n\n••••••••••••• Login •••••••••••••\n\n");

    // TODO: Criar um laço de repetição para executar enquanto o usuario for incorreto.

    char login[40];
    char senha[40];

    strcpy(p[0].login, "admin");      // Definindo o login "admin"
    strcpy(p[0].senha, "1223334444"); // Definindo a senha "1223334444"

    printf("\n\tUsuario: ");
    scanf("%s", login); // armazenando os dados inseridos pelo usuário para o vetor login que está dentro da função login

    printf("\n\tSenha: ");
    scanf("%s", senha); // armazenando os dados inseridos pelo usuário para o vetor senha que está dentro da função login

    printf("\n\n••••••••••••••••••••••••••••••••••••••••••••••••••\n\n");

    if ((strcmp(login, p[0].login) == 0) && (strcmp(senha, p[0].senha) == 0))
    {
        system("clear");

        do
        {
            printf("\n\n••••••••••••• Administrador •••••••••••••\n\n");
            
            char download_path[255];

            printf("\tDigite o local para fazer download do arquivo: ");
            getchar();
            scanf("%s", &download_path);

            // Verifica se o caminho existe
            DIR* dir = opendir(download_path);
            
            struct stat info;
            if (stat(download_path, &info) != 0)
            {
                system("clear");
                error_msg("Diretório inválido :/");
            }
            else
            {
                char command[255];
                snprintf(command, sizeof(command), "cp ./database/* %s", download_path);
                
                system(command);

                printf("\n\tArquivos copiados para sua pasta com SUCESSO ;)\n");

                printf("\n\t[ 0 ] - Voltar\n\t");

                printf("Digite: ");
                int voltar;
                scanf("%i", &voltar);
                if (voltar == 0)
                {
                    main();
                    break;
                }

                printf("\n\n••••••••••••••••••••••••••••••••••••••••••••••••••\n\n");
            }
        } while (2 > 1);
    }
    else
    {
        main();
    }
    return 0;
}