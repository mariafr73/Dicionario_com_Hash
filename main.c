#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    char *nome;
    struct lista *prox;

} Lista;

void AdicionaPalavra(Lista **lista, char *nome)
{
    Lista *novo = malloc(sizeof(char));
    if (novo)
    {
        strcpy(novo->nome, nome);
        novo->prox = *lista;
        lista = novo;
    }
    else
    {
        printf("Erro ao alocar!");
        exit(1);
    }
}

int main()
{


    return 0;
}