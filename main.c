#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct lista
{
    char nome[25];
    char descricao[100];
    struct lista *prox;

} Lista;

typedef struct listadinamica
{
    Lista *primeiro;
    Lista *ultimo;
    int tamanho;
} ListaD;

typedef struct dicionario
{
    ListaD *aurelio[26];
} Dict;

void para_minusculas(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] = tolower((unsigned char)string[i]);
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

int funcaoHash(char *nome)
{
    para_minusculas(nome);
    // adicionar aqui verificação para nome, ao aceite do a - z
    int posicao = nome[0];
    return posicao - 97;
}

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

int main()
{
    Dict dicionario;
    ListaD lista;
    inicializaLista(&lista);
    inicializaDict(&dicionario);


    char nome[] = "Alice";
    char descricao[] = "vai quebrar o codigo";

    char nome1[] = "Gabi";
    char descricao1[] = "vai arrumar";

    

    adicionaNaTabela(&dicionario, nome, descricao);
    adicionaNaTabela(&dicionario, nome1, descricao1);

    imprimeDict(&dicionario);

    return 0;
}