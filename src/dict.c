#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dict.h"

void adicionaNaTabela(Dict *dicionario, char *nome, char *descricao)
{
    int indice = funcaoHash(nome);
    if (indice == -1)
    {
        printf("Palavra inválida para hash!");
        return;
    }

    int verificaPalavra;
    int verificaDescricao;

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

void salvarEmArquivo(Dict *dicionario, const char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "w");
    if (!fp) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < 26; i++) {
        Lista *atual = dicionario->aurelio[i]->primeiro;
        while (atual != NULL) {
            fprintf(fp, "Nome: %s;\nSignificado: %s.\n\n", atual->nome, atual->descricao);
            atual = atual->prox;
        }
    }

    fclose(fp);
}

void carregarDeArquivo(Dict *dicionario, const char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (!fp) return;

    char linha[200];
    while (fgets(linha, sizeof(linha), fp)) {
        char *nome = strtok(linha, ";");
        char *desc = strtok(NULL, "\n");

        if (nome && desc) {
            adicionaNaTabela(dicionario, nome, desc);
        }
    }

    fclose(fp);
}
