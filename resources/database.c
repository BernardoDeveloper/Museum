#include "../headers/database.h"
#include "./struct.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Author:    Bernardo Gualberto
 * Created:   28.10.2023
 *
 * (c) Copyright by Museu do Presente.
 **/

#define MAX_LINE_LENGTH 8192

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
    else if (!strcmp(table, "b"))
    {
        fpt = fopen("database/bilheteria.csv", "a");
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
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    struct TemaRow data;

    // Pula a primeira linha
    if (fgets(line, sizeof(line), fpt) == NULL)
    {
        perror("Error reading CSV header");
        return NULL;
    }

    // TODO: Implementar algoritimo para busca binária
    // Le as linhas do arquivo
    while (fgets(line, sizeof(line), fpt) != NULL)
    {
        if (sscanf(line, "%d;%99[^;];%8191[^;];%d;", &data.id, data.titulo, data.texto, &data.nota) == 4)
        {
            // Compara se o ID da linha atual é igual o do parametro
            if (data.id == atoi(search))
            {
                static char buffer[MAX_LINE_LENGTH];
                snprintf(buffer, sizeof(buffer), "%i;%s;%s;%i", data.id, data.titulo, data.texto, data.nota);
                return buffer;
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