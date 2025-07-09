#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    char nome[25];
    struct lista *prox;

} Lista;

typedef struct listadinamica
{
    Lista *primeiro;
    Lista *ultimo;
    int tamanho;
} ListaD;

void AdicionaPalavra(ListaD *lista, char *nome)
{
    Lista *novo = malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("erro ao alocar!");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (lista->primeiro == NULL)
    {
        lista->primeiro = novo;
        lista->ultimo = novo;
    }
    else
    {
        lista->ultimo->prox = novo;
        lista->ultimo = novo;
    }

    lista->tamanho++;
}

void inicializaLista(ListaD *lista)
{
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

void imprimeLista(ListaD *lista)
{
    Lista *cont = lista->primeiro;
    while (cont != NULL)
    {
        printf("nome: %s\n", cont->nome);
        cont = cont->prox;
    }
}

void removePalavra(ListaD *lista, char *nome)
{
    if (lista->primeiro == NULL)
    {
        return;
    }
    Lista *atual = lista->primeiro;
    Lista *anterior = NULL;
    while (atual != NULL)
    {
        if (strcmp(atual->nome, nome) == 0)
        {
            if (anterior == NULL)
            {
                lista->primeiro = atual->prox;
                if (lista->ultimo == atual)
                {
                    lista->ultimo = NULL;
                }
            }
            else
            {
                anterior->prox = atual->prox;
                if ((lista->ultimo = atual))
                {
                    lista->ultimo = anterior;
                }
            }
            free(atual);
            lista->tamanho--;
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

int main()
{
    ListaD lista;
    inicializaLista(&lista);

    AdicionaPalavra(&lista, "alice");
    AdicionaPalavra(&lista, "caroline");
    AdicionaPalavra(&lista, "felipe");
    AdicionaPalavra(&lista, "peter");
    AdicionaPalavra(&lista, "manolo");

    imprimeLista(&lista);

    removePalavra(&lista, "caroline");
    removePalavra(&lista, "alice");
    removePalavra(&lista, "manolo");

    imprimeLista(&lista);
    return 0;
}