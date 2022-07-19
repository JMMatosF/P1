#include <stdio.h>
#include "othello_func.h"
#define SZ 8

void input_output( char board[SZ][SZ],int turn){
  int line, col, player = 0;
  char t_col;

       print_board(board);

       if (turn%2 == 0){
        player = 0;
        }else{ 
          player = 1;
        } 

        printf("Indique a sua jogada como exemplo 5D!");
        scanf("%d",&line);
        scanf("%c",&t_col);
        col = 'a' - t_col;
        while (check(board,line,col,player)){
        printf("Indique a sua jogada como exemplo 5D!");
        scanf("%d",&line);
        scanf("%c",&t_col);
        col = 'a' - t_col;
        }
        

}

int check(char board[SZ][SZ], int linha, int col, int player){
  int check1,check2,gx,gy,check3;
  check1 = check2 = check3 = 0;
  if (board[linha][col] =! "."){
    check1++;
  }
  if (check1 =! 0)
    return 1;

  check2 = girate(board,linha,col,player,gx,gy);
  if (check2 =! 0)
    return 1;

  
  
}

int girate(char board[SZ][SZ],int linha,int col,int player,int gx,int gy){
  char piece,piece2;
  int good = 0;

  if ( player%2== 0){
    piece = "x";
    piece2 = "o";
  }else{
    piece = "o";
    piece2 = "x";
  }

  for (int x = -1; x <= 1;x++){
    for (int y = -1; y <= 1; y++){
      if (board[linha + x][col + y] == piece2){
        good++;
        
      }
    }
  }
  if (good =! 0){
    return 1;
  }else{
    return 0;
  }  
  
}