#include <stdio.h>

#include "othello_func.h"
#define SZ 8

int main(){
    char board[SZ][SZ];
    int end = 0;
    init_board(board);
    while (end =! 1){
        print_board(board);
        printf("Faça a sua jogada!");
        scanf("%s")
    }
}