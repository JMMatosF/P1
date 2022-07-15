
#include <stdio.h>

#include "othello_func.h"
#define SZ 8


int main(int argc, char*argv[])
{
  char board [SZ][SZ];
  int moves[SZ][SZ];
  int x= 0;
  char y;                 
  int no_of_games = 0;             
  int n_movimentos = 0;                                                                         
  int player = 0; 
  int linhas_ficheiro[64];
  char colunas_ficheiro[64];
  int file = 0;
  init_board(board);
  int invalid_moves = 0;
  FILE *ficheiro = NULL;  //CONSOANTE O QUE SE ESCREVE NO TERMINAL, ELE JOGA INTERATIVAMENTE OU ATRAVES DE UM FICHEIRO DE TEXTO
   if(argc < 2){
  printf("VAI SER MOSTRADO O TABULEIRO INICIAL: \n");
     
    player = ++no_of_games % 1;   
    n_movimentos = 4;                
     
    printf("O COMPUTADOR JOGA PRIMEIRO\n");
     
    input_output(board);  //CHAMADA DAS FUNCOES
    print_board(board);         
     
  }
   else if(argc == 2){
   ficheiro = fopen (/*argv[1]*/"jogadas.txt", "r"); //ABERTURA PARA LEITURA DO FICHEIRO
   
     
    while(fscanf(ficheiro, "%d%c", &linhas_ficheiro[file], &colunas_ficheiro[file]) != EOF){ // LEITURA DO FICHEIRO
   
    printf("%d%c\n", linhas_ficheiro[file], colunas_ficheiro[file]); //PRINT CONTEUDO DO FICHEIRO
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
