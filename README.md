# PIM - Gerenciamento de MUSEU

## Estrtura de pastas:
- _screens:_ Pasta que terá as telas para acesso;
- _models:_ Arquivos com as estruturas para escrever no banco de dados;
- _database:_ Arquivos que contém as estruturas do banco;
- _headers:_ Headers para fazer a refêrencia de outros arquivos;

## Arquivo de Banco de dados:
Estrutura de arquivos em csv, separando as colunas por `;`

**Usuário:**
```csv
id;nome;votacao;tema;
1;test;8;3;
```

**Temas:**
```csv
id;titulo;texto;
1;"100 anos da arte moderna";"Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n Sed placerat tellus non ligula vestibulum, eu condimentum elit auctor. Mauris pellentesque convallis urna eu ornare.";
```

---

### Recursos:
[Artigo explicando como escrever em arquivos CSV](https://dev.to/arepp23/how-to-write-to-a-csv-file-in-c-1l5b)