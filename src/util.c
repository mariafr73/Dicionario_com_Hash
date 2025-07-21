#include "../include/util.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void para_minusculas(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] = tolower((unsigned char)string[i]);
    }
}

int funcaoHash(char *nome)
{
    para_minusculas(nome);
    // adicionar aqui verificação para nome, ao aceite do a - z
    int posicao = nome[0];
    return posicao - 97;
}

int descricaoValida(char *palavra)
{
    for (int i = 0; palavra[i] != '\0'; i++)
    {
        if (!isalpha(palavra[i]) && !isspace(palavra[i]))
        {
            printf("Caracter inválido!\n\n");
            return 0;
        }
    }
    return 1;
}

int palavraValida(char *palavra)
{
    for (int i = 0; palavra[i] != '\0'; i++)
    {
        if (!isalpha(palavra[i]))
        {
            printf("Caracter inválido!\n\n");
            return 0;
        }
    }
    return 1;
}

void menu_opcoes()
{
    printf("========================\n");
    printf("[1] - Adicionar palavra\n");
    printf("[2] - Buscar palavra\n");
    printf("[3] - Imprimir\n");
    printf("[4] - Remover palavra\n");
    printf("[0] - Sair\n");
    printf("========================\n");
    printf("-> ");
}

void limpa_tela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int retornaNomeValido(char *nome)
{
    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (!isalpha(nome[i]))
        {
            printf("Caracter inválido!\n\n");
            return 0;
        }
    }
    return 1;
}