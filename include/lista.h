#ifndef LISTA_H
#define LISTA_H

typedef struct lista
{
    char nome[25];
    char descricao[100];
    struct lista *prox;

} Lista;


#endif