#include "othello_func.h"
#include <stdio.h>

void init_board(char board[SZ][SZ]){    //INICIALIZA O TABULEIRO 
	for(int i = 0; i<SZ; i++){              //COM AS POSIÇÕES DE ACORDO COM 
		for(int j = 0; j<SZ; j++){            //O PEDIDO NO ENUNCIADO 
                board[i][j] = '.';
		}
	}

	board[4][4] = board[5][5] = 'o';
	board[5][4] = board[4][5] = 'x';

}

void print_board(char board[SZ][SZ]){                                 //PRINT O TABULEIRO COM A
    for (int line = 0; line < 9; line++){
        for (int col = 0; col < 9; col++) {
            printf("%c ", board[line][col]);
        }
        printf("\n");
    }
    printf("\n");

}

char player(int turno){
    if(turno % 2 ==0){
        return 'x';
    }
    else
        return 'o';
}

char oponente(char jogador){                          //FUNÇÃO PARA VER QUAL É O OPONENTE.
    if(jogador == 'x'){
        return 'o';
    }
    else
        return 'x';

}


void flanked(char board[SZ][SZ],int line, int col,char jogador)          //VIRA PEÇAS A PARTIR DO PONTO ONDE FOI EFETUADA A JOGADA
{
    int delta_line = 1, delta_col = 1, n_movimentos;
    char jogador1 = oponente(jogador);

    board[line][col] = jogador;

    while (board[line + delta_line][col + delta_col] == jogador1){
        board[line + delta_line][col + delta_col];
        delta_line++;
        delta_col++;
        line *= delta_line;
        col *= delta_col;
    }
}

int jogadas_validas(char board[SZ][SZ], int line, int col, char jogador)
{
    char jogador2 = oponente(jogador);
    int delta_line = 1, delta_col = 1, pontos = 0;

    while (board[line + 1][col + 1] == jogador2){
        delta_col++;
        delta_line++;
        pontos++;
        line*= delta_line;
        col*= delta_col;
        if(line > 9 || col > 9){
            break;
        }
    }
    if(board[line + delta_line][col + delta_col] == jogador){
        return pontos;
    }
    else
        return 0;


}


void play(char board[SZ][SZ], int line, int col, char jogador)
{
   char jogador2 = oponente(jogador);

    for (int l = -1; l <= 1 ; l++) {
        for (int c = -1; c <=1; c++){
            if(board[line][col] == '.' && board[line + l][col + c] == jogador2){
                if(jogadas_validas(board,line,col, jogador) != 0){
                    flanked(board,line,col, jogador);
                }
            }
        }

    }
}

void temp_board(char board[SZ][SZ], char new_board[SZ][SZ]){
  int i;
  int j;
  for(i = 0 ; i<SZ ; i++){
         for(j = 0 ; j<SZ ; j++){
           new_board[i][j] = board[i][j];   //CRAÇÃO DE UM TABULEIRO TEMPORÁRIO PARA ARMAZENAR AS JOGADAS DO COMPUTADOR
      }
  }
}

int pontos(char jogador,char board[SZ][SZ]){
    int contador=0;
    for (int i = 0; i < SZ; i++)
        for ( int j = 0; j < SZ; j++)
            if (board[i][j]== jogador) contador++;

    return contador;
}

void fim_jogo(char board[SZ][SZ], char jogador){
    int pontos_a, pontos_b;
    char count = oponente(jogador);

    pontos_a = pontos('o', board);
    pontos_b = pontos('x', board);
    printf("Fim do jogo\n Pretas: %d\n Brancas: %d\n",pontos_a,pontos_b);

    if(pontos(jogador,board) < pontos(count,board)){
        printf("Perdeste\n");
    }
    else if( pontos(jogador,board) > pontos(count,board)){
        printf("Ganhaste!\n");
    }
    else{
        printf("É um empate\n");
    }
}

void input_output( char board[SZ][SZ],int turn){
  int line, col, player = 0;
  char t_col;

       print_board(board);

       if (turn%2 == 0){
        player = 0;
        }else{
          player = 1;
        }

        printf("Indique a jogada: ");
        scanf("%d",&line);
        scanf("%c",&t_col);
        col = 'a' - t_col;
        while (jogadas_validas(board,line,col,player)){
        printf("Indique a sua jogada como por exemplo 5D!");
        scanf("%d",&line);
        scanf("%c",&t_col);
        col = 'a' - t_col;
        }
}