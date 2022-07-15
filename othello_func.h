#include <stdio.h>
#define SZ 8
void init_board(char board[SZ][SZ]);
void print_board(char board[SZ][SZ]);
void jogadas_a_zero(char board [SZ][SZ], int moves[][SZ]);
int oponente(char color);
int find_squares_not_valid(char board[SZ][SZ], int line, int col);
int flanked(char board[SZ][SZ], int moves[][SZ], char color);
int jogadas_validas(char board[SZ][SZ], int moves[][SZ], char color);
int play(char board[SZ][SZ], int line, int col, char player);
int count_pieces(char board[SZ][SZ], char color);
int temp_board(char board[SZ][SZ]);
int not_arrayMoves(int line, int col, int moves[][SZ]);
int jogada_melhor_pontuada(char board[SZ][SZ], int moves[][SZ], char color);
void jogada_pc(char board[SZ][SZ], int moves[][SZ], char color);
int print_num_pieces(char board[SZ][SZ]);
void input_output( char board[SZ][SZ]);