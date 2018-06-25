typedef struct MassaDeDados{
    int cod;
    char nome[40];
    int idade;
    char empresa[40];
    char departamento[40];
    float sal;
    int qtd;
}massa;

int preenche_massa(massa *li);

massa *cria_lista_massa();

void strreplace(char *s, char chr, char repl_chr);

void ordena_quicksort(massa *v, int inicio, int fim);

int particiona(massa *v, int inicio, int fim);


