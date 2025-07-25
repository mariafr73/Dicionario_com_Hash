#ifndef DICT_H
#define DICT_H
#include "listaD.h"
#include "util.h"

typedef struct dicionario
{
    ListaD *aurelio[26];
} Dict;

void adicionaNaTabela(Dict *dicionario, char *nome, char *descricao);
void imprimeDict(Dict *dicionario);
void liberaDict(Dict *dicionario);
Dict *criaDict();
void buscaNoDicionario(Dict *dicionario, char *nome);

#endif
