#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/dict.h"
/*o que falta: adicionar verificações: não aceitar números e símbolos (e outras aí..rs :p),
estrutura CRUD, funcao para liberar dicionario, função para remover palavra E significado (tente aproveitar a que ja tem)
*/

/*seria legal adicionar(opcional): salvar as listas em um arquivo.txt*/

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

    // criar funcao para liberar dicionario

    return 0;
}