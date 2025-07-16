#include "../include/util.h"
#include <ctype.h>

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

//void verificaPalavra(char *palavra);
