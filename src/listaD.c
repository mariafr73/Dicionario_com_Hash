#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dict.h"

void AdicionaPalavra(ListaD *lista, char *nome, char *descricao)
{
    Lista *novo = malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("erro ao alocar!");
        exit(1);
    }
    strcpy(novo->nome, nome);
    strcpy(novo->descricao, descricao);
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
        printf("Descricao: %s", cont->descricao);
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
                if ((lista->ultimo == atual))
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

void liberaLista(ListaD *lista)
{
    Lista *atual = lista->primeiro;
    Lista *prox;

    while (atual != NULL)
    {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    free(lista);
}

Lista *buscaLista(ListaD *lista, char *nome)
{
    if (lista == NULL || lista->primeiro == NULL)
    {
        return NULL;
    }

    Lista *auxiliar;
    for (auxiliar = lista->primeiro; auxiliar != NULL; auxiliar = auxiliar->prox)
    {
        if (strcmp(auxiliar->nome, nome) == 0)
        {
            return auxiliar;
        }
    }
    return NULL;
}