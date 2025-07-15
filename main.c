#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "include/dict.h"
/*o que falta: adicionar verificações: não aceitar números e símbolos (e outras aí..rs :p),
estrutura CRUD, funcao para liberar dicionario, função para remover palavra E significado (tente aproveitar a que ja tem)
*/

/*seria legal adicionar(opcional): salvar as listas em um arquivo.txt, adicionar make*/

int main()
{
    Dict *dicionario = criaDict();
    int opcao;
    char nome[10];
    char descricao[100];
    do
    {
        printf("========================\n");
        printf("[1] - Adicionar palavra\n");
        printf("[2] - Buscar palavra\n");
        printf("[3] - Imprimir\n");
        printf("[4] - Remover palavra\n");
        printf("[0] - Sair\n");
        printf("========================\n");
        printf("-> ");
        scanf("%d", &opcao);
        getchar();

        // funcao para verificar se é numero

        switch (opcao)
        {
        case 1:
            printf("Insira a palavra: ");
            scanf("%[^\n]", nome);
            getchar();
            // funcao de nao aceitar numeros e simbolos
            printf("Insira o significado: ");
            scanf("%[^\n]", descricao);
            getchar();
            // funcao de nao aceitar numeros e simbolos
            adicionaNaTabela(dicionario, nome, descricao);

            break;

        case 3:
            imprimeDict(dicionario);

        default:
            printf("Opcao invalida");
            break;
        }
    } while (opcao != 0);
    // criar funcao para liberar dicionario

    return 0;
}