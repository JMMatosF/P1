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
int temp_board(char board[SZ][SZ]);
int not_arrayMoves(int line, int col, int moves[][SZ]);
int jogada_melhor_pontuada(char board[SZ][SZ], int moves[][SZ], char color);
void jogada_pc(char board[SZ][SZ], int moves[][SZ], char color);
int print_num_pieces(char board[SZ][SZ]);



//cleaned*******
void input_output( char board[SZ][SZ],int turn);
int girate(char board[SZ][SZ],int linha,int col,int player,int gx,int gy);