#include <stdio.h>
#define SZ 9
void init_board(char board[SZ][SZ]);
void print_board(char board[SZ][SZ]);
void jogadas_a_zero(char board [SZ][SZ], int moves[][SZ]);
char jogador(int turno);
char oponente(char jogador);
void flanked(char board[SZ][SZ],int line, int col,char jogador);
int jogadas_validas(char board[SZ][SZ], int linha, int col, char jogador);
void play(char board[SZ][SZ], int line, int col, char player);
void temp_board(char board[SZ][SZ], char new_board[SZ][SZ]);
int not_arrayMoves(int line, int col, int moves[][SZ]);
int pontos(char player,char board[SZ][SZ]);
void fim_jogo(char board[SZ][SZ], char jogador);
void jogada_pc(char board[SZ][SZ], char jogador);