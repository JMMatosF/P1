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



void jogadas_a_zero(char board[SZ][SZ], int moves[][SZ]){
  int line;                                                      //FUNÇÃO AUXILIAR QUE
  int col;                                                      //INICIALIZA O ARRAY MOVES A 0, 
                                                                //PARA CASO HAJA UMA JOGADA VÁLIDA ESTE "MARCA-LA"
    for(line = 0; line < SZ; line++){
      for(col = 0; col < SZ; col++){
       moves[line][col] = 0;
      }
    }

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

int temp_board(char board[SZ][SZ]){
  int i;
  int j;
  char new_board[SZ][SZ];
  for(i = 0 ; i<SZ ; i++){
         for(j = 0 ; j<SZ ; j++){
           new_board[i][j] = board[i][j];   //CRAÇÃO DE UM TABULEIRO TEMPORÁRIO PARA ARMAZENAR AS JOGADAS DO COMPUTADOR
      }
  }
return 0;
}

int not_arrayMoves(int line, int col, int moves[][SZ]){
  for(line = 0 ; line<SZ ; line++)
     for(col = 0 ; col<SZ ; col++)
     {
       if(!moves[line][col])            
         continue;             //JOGADA VÁLIDA? NÃ0? ENTÃO CONTINUA A PROCURAR
     }
    return 0;
}

int jogada_melhor_pontuada(char board[SZ][SZ], int moves[][SZ], char color)
{
   int line, col;    
  oponente(color);
   char new_board[SZ][SZ];  
   int pecas= 0;                       
   int atualizar_pecas = 0;                  
 
       
   
   for(line = 0 ; line < SZ ; line++)
     for(col = 0 ; col<SZ ; col++)
     {           
        if(pecas<atualizar_pecas) {       
               pecas = atualizar_pecas; 
        }
        
        not_arrayMoves(line, col, moves);
        temp_board(board);                                 //CHAMADA DAS FUNÇÕES

       play(new_board, line, col, color);

       
     }
   return 0;
}

void jogada_pc(char board[SZ][SZ], int moves[][SZ], char color)
{
   
   int line;                          
   int col;   
   char temporario_board[SZ][SZ];  
   int temp_moves[SZ][SZ];                      
   int linha_com_mais_turns;                     
   int coluna_com_mais_turns;                          
   int atualizar_pecas = 0;                    
   int pecas = 100;                                       
   
   oponente(color);
   
   for(line = 0; line< SZ; line++)
     for(col = 0; col < SZ; col++)
     {
       if(moves[line][col] == 0)
         continue;
       
      if(atualizar_pecas < pecas)    
       {                      
         pecas = atualizar_pecas;      //O JOGADOR FICA COM MENOS PEÇAS NO TABULEIRO DO QUE AQUELAS QUE TINHA ANTES? 
         linha_com_mais_turns = line;  // SIM, ENTÃO GUARDA ESSA COORDENADA E O NOVO NUMERO DE PEÇAS
         coluna_com_mais_turns = col;  
       }

       temp_board(board);

       play(temporario_board, line, col, color);              //CHAMADA MAS FUNÇÕES
       //jogadas_validas(temporario_board, temp_moves, oponente(color));
       atualizar_pecas = jogada_melhor_pontuada(temporario_board, temp_moves, oponente(color));
      
     }
  
   play(board, linha_com_mais_turns, coluna_com_mais_turns, color); 
}

int print_num_pieces(char board[SZ][SZ]){
  char player = 0;
  int pc_pieces = 0;               
  int jogador_pieces = 0;    
  int line = 0;                      
  int col = 0;  

  for(line = 0; line < SZ; line++)
       for(col = 0; col < SZ; col++)
       {
         pc_pieces = pc_pieces + board[line][col] ==  oponente(player);
         jogador_pieces = jogador_pieces + board[line][col] == oponente(player);
       }
     printf("Pontuação do computador: %d \n", pc_pieces);
     printf("Pontuação do jogador: %d \n", jogador_pieces);
     return 0;
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
        printf("Indique a sua jogada como exemplo 5D!");
        scanf("%d",&line);
        scanf("%c",&t_col);
        col = 'a' - t_col;
        }
        

}

int check(char board[SZ][SZ], int linha, int col, int player){
  int check1,check2,gx,gy,check3;
  check1 = check2 = check3 = 0;
  if (board[linha][col] != '.'){
    check1++;
  }
  if (check1 != 0){
    return check1;
  }

  check2 = girate(board,linha,col,player,linha,col);
  if (check2 != 0){
    return check2;
  }
}

int girate(char board[SZ][SZ],int linha,int col,int player,int gx,int gy){
  char piece,piece2;
  int good = 0;

  if ( player%2== 0){
    piece = 'x';
    piece2 = 'x';
  }else{
    piece = 'x';
    piece2 = 'x';
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