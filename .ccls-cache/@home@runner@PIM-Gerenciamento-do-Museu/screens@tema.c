#include "../headers/tema.h"
#include "../headers/database.h"
#include <stdio.h>
#include <stdlib.h>

int tema() {
  system("clear"); // Limpa a tela

  printf("📑 TEMA - Página não criada ⚠️\n");

  write_csv("u", "2;Matheus celta;3;2;");
  read_csv("u", "1");

  return 0;
}