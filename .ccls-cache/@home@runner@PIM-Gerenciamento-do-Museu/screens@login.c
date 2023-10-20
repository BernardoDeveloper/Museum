#include "../headers/login.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


typedef struct{
    char login[40]; 
    char senha[40]; 
} pessoa; pessoa p[1];  // Reduzindo o nome da string para "p" e o "[[1]" é o máximo de pessoas com logins e senhas]


int login(){

  system("clear"); // Limpa a tela

  // Cabeçalho para visualização
  printf("\n\n••••••••••••• Login •••••••••••••\n\n");

  // Criar um laço de repetição para executar enquanto o usuario for incorreto.
  
    char login[40];
    char senha[40]; 

    strcpy(p[0].login, "admin"); // Definindo o login "admin"
    strcpy(p[0].senha, "1223334444"); // Definindo a senha "1223334444"

    printf("\nUsuario: ");
    scanf("%s", login); // armazenando os dados inseridos pelo usuário para o vetor login que está dentro da função login

    printf("\nSenha: ");
    scanf("%s", senha); // armazenando os dados inseridos pelo usuário para o vetor senha que está dentro da função login

    if ((strcmp(login,p[0].login)==0) && (strcmp(senha,p[0].senha)==0)){
        printf("\n\nAdministrador logado."); 
    }else{
        printf("\n\nLogin e/ou senha incorretos."); 
    }
    return 0;
}