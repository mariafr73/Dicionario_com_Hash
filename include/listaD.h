#ifndef LISTAD_H
#define LISTAD_H
#include "lista.h"

typedef struct listadinamica
{
    Lista *primeiro;
    Lista *ultimo;
    int tamanho;
} ListaD;

void AdicionaPalavra(ListaD *lista, char *nome, char *descricao);
void inicializaLista(ListaD *lista);
void imprimeLista(ListaD *lista);
void removePalavra(ListaD *lista, char *nome);
void liberaLista(ListaD *lista);
Lista *buscaLista(ListaD *lista, char *nome);

#endif