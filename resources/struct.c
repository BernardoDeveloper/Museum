struct UsuarioRow
{
    int id;
    char *nome;
    int tema;
    int pontuacao;
};

struct TemaRow
{
    int id;
    char titulo[100];
    char texto[100];
    int nota;
};