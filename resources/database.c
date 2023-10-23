#include "../headers/database.h"
#include "./struct.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct CSVRow
{
    int id;
    char titulo[100];
    char texto[100];
    int nota;
};

// Ponteiro para referenciar o local do arquivo
FILE *fpt;

char *write_csv(char table[], char text[]);
char *read_csv(char table[], char search[]);

// Escreve os dados no arquivo `.csv`
char *write_csv(char table[], char text[])
{
    if (!strcmp(table, "u"))
    {
        fpt = fopen("database/usuarios.csv", "a");
    }
    else if (!strcmp(table, "t"))
    {
        fpt = fopen("database/temas.csv", "a");
    }
    else
    {
        printf("[ERRO]: Valor inválido passado na função");
        return "1";
    }

    if (fpt == NULL)
    {
        printf("[ERRO]: para abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fpt, "%s\n", text);
    fclose(fpt);
    return "0";
}

// Lê os dados do arquivo `.csv`
char *read_csv(char table[], char search[])
{
    if (!strcmp(table, "u"))
    {
        fpt = fopen("database/usuarios.csv", "r");
        printf("Chegou aqui - usuário");
    }
    else if (!strcmp(table, "t"))
    {
        fpt = fopen("database/temas.csv", "r");
    }
    else
    {
        printf("[ERRO]: Valor inválido passado na função");
        return "1";
    }

    char line[MAX_LINE_LENGTH];
    struct CSVRow data;

    // Pula a primeira linha
    if (fgets(line, sizeof(line), fpt) == NULL)
    {
        perror("Error reading CSV header");
        return "1";
    }

    // TODO: Implementar algoritimo para busca binária
    // Le as linhas do arquivo
    while (fgets(line, sizeof(line), fpt) != NULL)
    {
        if (sscanf(line, "%d;%99[^;];%99[^;];%d;", &data.id, data.titulo, data.texto, &data.nota) == 4)
        {
            // Compara se o ID da linha atual é igual o do parametro
            if (data.id == atoi(search))
            {
                // TODO: fix the return of the function
                /* char function_return[2048];
                snprintf(function_return, sizeof(function_return), "%i;%s;%s;%i", data.id, data.titulo, data.texto, data.nota);
                return function_return; */
                printf("%i;%s;%s;%i", data.id, data.titulo, data.texto, data.nota);
            }
        }
        else
        {
            fprintf(stderr, "Error parsing CSV line: %s\n", line);
        }
    }

    fclose(fpt);
    return "0";
}