#include "../headers/database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct CSVRow {
  int id;
  char *name;
  int tema;
  int pontuacao;
};

// Ponteiro para referenciar o local do arquivo
FILE *fpt;

char *write_csv(char table[], char text[]);
char *read_csv(char table[], char search[]);

// Escreve os dados no arquivo .csv
char *write_csv(char table[], char text[]) {
  if (!strcmp(table, "u")) {
    fpt = fopen("database/usuarios.csv", "a");
  } else if (!strcmp(table, "t")) {
    fpt = fopen("database/temas.csv", "a");
  } else {
    printf("[ERRO]: Valor inválido passado na função");
    return "1";
  }

  if (fpt == NULL) {
    printf("[ERRO]: para abrir o arquivo\n");
    exit(EXIT_FAILURE);
  }

  fprintf(fpt, "%s\n", text);
  fclose(fpt);
  return "0";
}

// Lê os dados do arquivo .csv
char *read_csv(char table[], char search[]) {
  if (!strcmp(table, "u")) {
    fpt = fopen("database/usuarios.csv", "r");
  } else if (!strcmp(table, "t")) {
    fpt = fopen("database/temas.csv", "r");
  } else {
    printf("[ERRO]: Valor inválido passado na função");
    return "1";
  }

  char line[MAX_LINE_LENGTH];
  struct CSVRow data;

  // Pula a primeira linha - cabecalho
  if (fgets(line, sizeof(line), fpt) == NULL) {
    perror("Error reading CSV header");
    return "1";
  }

  // Lê todas as linhas do arquivo - um laco de repeticao
  while (fgets(line, sizeof(line), fpt) != NULL) {
    if (sscanf(line, "%d;%99[^;\n];%d;%d;", &data.id, data.name, &data.tema,
               &data.pontuacao) == 4) {

      // Compara se o id da linha eh igual o informado
      if (data.id == atoi(search)) {
        printf("ID: %d\nName: %s\nTema: %i\nPontuacao: %i\n", data.id,
               data.name, data.tema, data.pontuacao);
      }
    } else {
      fprintf(stderr, "Error parsing CSV line: %s\n", line);
    }
  }

  fclose(fpt);
  return "0";
}