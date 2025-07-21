#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/dict.h"

int main()
{
    Dict *dicionario = criaDict();

    int opcao;
    char nome[10];
    char descricao[100];
    int verificaPalavra;
    int verificaDescricao;
    int verificador;

    do
    {
        menu_opcoes();
        scanf("%d", &opcao);
        getchar();
        limpa_tela();

        switch (opcao)
        {
        case 1:
            do
            {
                printf("Insira a palavra: ");
                scanf("%[^\n]", nome);
                getchar();
                verificaPalavra = palavraValida(nome);

                printf("Insira o significado: ");
                scanf("%[^\n]", descricao);
                getchar();
                verificaDescricao = descricaoValida(descricao);
            } while (!verificaPalavra || !verificaDescricao);

            adicionaNaTabela(dicionario, nome, descricao);

            break;

        case 2:
            do
            {
                printf("Insira a palavra: ");
                scanf("%[^\n]", nome);
                getchar();
                verificador = retornaNomeValido(nome);
            } while (!verificador);
            buscaNoDicionario(dicionario, nome);

            break;

        case 3:

            imprimeDict(dicionario);

            break;

        case 4:
            do
            {
                printf("Insira a palavra que deseja remover: ");
                scanf("%[^\n]", nome);
                getchar();
                verificador = retornaNomeValido(nome);
            } while (!verificador);
            removePalavra(dicionario->aurelio[funcaoHash(nome)], nome);
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 0);

    liberaDict(dicionario);

    return 0;
}
