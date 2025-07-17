#include <stdio.h>
#include <stdlib.h>
#include "../include/dict.h"

void adicionaNaTabela(Dict *dicionario, char *nome, char *descricao)
{
    int indice = funcaoHash(nome);
    if (indice == -1)
    {
        printf("Palavra inválida para hash!");
        return;
    }

    AdicionaPalavra(dicionario->aurelio[indice], nome, descricao); // erro de segmentaçaõ
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

Dict *criaDict()
{
    Dict *dicionario = malloc(sizeof(Dict));
    if (dicionario == NULL)
    {
        printf("Erro ao alocar dicionário.\n");
        exit(1);
    }

    for (int i = 0; i < 26; i++)
    {
        dicionario->aurelio[i] = malloc(sizeof(ListaD));
        if (dicionario->aurelio[i] == NULL)
        {
            printf("Erro ao alocar lista.\n");
            exit(1);
        }

        dicionario->aurelio[i]->primeiro = NULL;
        dicionario->aurelio[i]->ultimo = NULL;
        dicionario->aurelio[i]->tamanho = 0;
    }

    return dicionario;
}

void liberaDict(Dict *dicionario)
{
    for (int i = 0; i < 26; i++)
    {
        if (dicionario->aurelio[i] != NULL)
        {
            liberaLista(dicionario->aurelio[i]);
            dicionario->aurelio[i] = NULL;
        }
    }

    free(dicionario);
}

void buscaNoDicionario(Dict *dicionario, char *nome)
{
    Lista *palavraEncontrada;
    int indice = funcaoHash(nome);
    if (indice == -1)
    {
        printf("Palavra inválida para hash!");
        return;
    }

    palavraEncontrada = buscaLista(dicionario->aurelio[indice], nome);

    if (palavraEncontrada != NULL)
    {
        printf("Significado: %s\n", palavraEncontrada->descricao);
    }
    else
    {
        printf("Palavra não encontrada");
    }
}
