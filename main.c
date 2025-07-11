#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/dict.h"


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

    //criar funcao para liberar dicionario

    return 0;
}