#include "othello_func.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char** argv){
    char board [SZ][SZ], colunas_ficheiro[64], y, linhas_ficheiro[64];
    int player = 0, file = 0;

    init_board(board);
    int end = 0;
    int turn = 0;
    init_board(board);
    FILE *ficheiro = NULL;  //CONSOANTE O QUE SE ESCREVE NO TERMINAL, ELE JOGA INTERATIVAMENTE OU ATRAVES DE UM FICHEIRO DE TEXTO
    if(argc < 2){
        printf("VAI SER MOSTRADO O TABULEIRO INICIAL: \n");

        oponente(player);

        printf("O COMPUTADOR JOGA PRIMEIRO\n");

        input_output(board,turn);  //CHAMADA DAS FUNCOES
        print_board(board);

    }

    else if(argc == 2){
        ficheiro = fopen (/*argv[1]*/"jogadas.txt", "r"); //ABERTURA PARA LEITURA DO FICHEIRO


        while(fscanf(ficheiro, "%d%c", &linhas_ficheiro[file], &colunas_ficheiro[file]) != EOF){ // LEITURA DO FICHEIRO

            printf("%d%c\n", linhas_ficheiro[file], colunas_ficheiro[file]); ///PRINTA CONTEUDO DO FICHEIRO
        }
        if(!ficheiro){
            printf("Ficheiro  %s não  encontrado", argv[1]);
            return 1;
        }

        else if(argc > 2){
            printf("Impossivel abrir  %s ficheiro", argv[1] );
        }
        fclose(ficheiro);
    }
    return 0;

}
