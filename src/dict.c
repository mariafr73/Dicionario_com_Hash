#include <stdio.h>
#include <stdlib.h>
#include "dict.h"

void adicionaNaTabela(Dict *dicionario, char *nome, char *descricao)
{
    int indice = funcaoHash(nome);
    if (indice == -1)
    {
        printf("Palavra inválida para hash!");
        return;
    }

    AdicionaPalavra(dicionario->aurelio[indice], nome, descricao);
}

void imprimeDict(Dict *dicionario)
{
    for (int i = 0; i < 26; i++)
    {
        if (dicionario->aurelio[i]->tamanho > 0)
        {
            printf("'%c':\n", i + 'A');
            imprimeLista(dicionario->aurelio[i]);
            printf("\n");
        }
    }
}

void inicializaDict(Dict *dicionario)
{
    for (int i = 0; i < 26; i++)
    {
        dicionario->aurelio[i] = malloc(sizeof(ListaD));
        if (dicionario->aurelio[i] == NULL)
        {
            printf("Erro ao alocar!");
            exit(1);
        }
        dicionario->aurelio[i]->primeiro = NULL;
        dicionario->aurelio[i]->ultimo = NULL;
        dicionario->aurelio[i]->tamanho = 0;
    }
}