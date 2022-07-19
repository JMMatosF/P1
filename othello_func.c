#include "othello_func.h"

void init_board(char board[SZ][SZ]){    //INICIALIZA O TABULEIRO 
	for(int i = 0; i<SZ; i++){              //COM AS POSIÇÕES DE ACORDO COM 
		for(int j = 0; j<SZ; j++){            //O PEDIDO NO ENUNCIADO 
                board[i][j] = '.';
		}
	}

	board[3][3] = board[4][4] = 'o';
	board[4][3] = board[3][4] = 'x';

}

void print_board(char board[SZ][SZ]){                                 //PRINT O TABULEIRO COM A
	char coluna = 'a'; 
  int i, j, letra_da_coluna;                                          //RESPETIVA LINHA E COLUNA DE LETRAS E NUMEROS
	printf("   ");
	for(letra_da_coluna =0; letra_da_coluna<SZ; letra_da_coluna++){
		printf("%c ", coluna + letra_da_coluna);
	}
	printf("\n");
	for(i = 0; i<SZ; i++){
		printf("%d  ", i+1);
		for(j = 0; j<SZ; j++){
			printf("%c ", board[i][j]);
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

int flanked(char board[SZ][SZ], int moves[][SZ], char color)          //ENCONTRA CASA VALIDAS PARA AS JOGADAS
{
   int line, col;
   int delta_line, delta_col;              
   int i, j;            
   int n_movimentos = 0; 
   
   for(line = 0; line < SZ; line++)
     for(col = 0; col < SZ; col++)
     {
       find_squares_not_valid(board, line, col);                 
       for(delta_line = -1; delta_line <= 1; delta_line++)                      //PROCURA NAS DIAGONAIS 
         for(delta_col = -1; delta_col <= 1; delta_col++)
         { 
           if(line + delta_line < 0 || line + delta_line >= SZ|| col + delta_col < 0 || col + delta_col >= SZ || (delta_line==0 && delta_col==0))
             continue;                                                     //NÃO ULTRAPASSA OS LIMITES E REFERE-SE SEMPRE À PEÇA EM QUESTÃO

           if(board[line + delta_line][col + delta_col] == oponente(color))
           {

             i = line + delta_line;         //MOVE-SE EM DELTA DIREÇÃO ENQUANTO A PEÇA FOR DO OPONENTE   
             j = col + delta_col;                
             
             while(1)                   //LOOP INFINITO, SEMPRE EXECUTADO
             {
               i = i + delta_line;                  
               j = j + delta_col;  
               if(i < 0 || i >= SZ || j < 0 || j >= SZ || board[i][j] == '.' ) // PARA QUANDO ENCONTRA UMA CASA VAZIA
                 break;
                
               if(board[i][j] == color)
               {
                 moves[line][col] = 1;    //TUDO SE CONCRETIZOU, JOGADA VÁLIDA, ARRAY MOVES = 1
                 n_movimentos++;         
                 break;                 
               }                
             }
           }
         }     
     }
   return n_movimentos; 
}

/*int jogadas_validas(char board[SZ][SZ], int linha, int col, int player)   //CHAMA AS FUNÇÕES QUE FAZEM PARTE DA VERIFICAÇÃO DA JOGADA
{
   oponente(color);
   jogadas_a_zero(board, moves);
   flanked(board, moves, color);

    return 1;
}
*/

int play(char board[SZ][SZ], int line, int col, char color) // RACIOCINIO IDENTICO ÀS FUNÇÕES QUE VERIFICAM SE A JOGADA É VALIDA
{
   int delta_line;                   
   int delta_col;                   
   int i;                          
   int j;                            
   oponente(color);
   board[line][col] = color;           

   for(delta_line = -1; delta_line <= 1; delta_line++)
     for(delta_col = -1; delta_col <= 1; delta_col++)
     { 
       
       if(line + delta_line < 0 || line + delta_line >= SZ|| col + delta_col < 0 || col + delta_col >= SZ || (delta_line==0 && delta_col==0))
             continue;

       if(board[line + delta_line][col + delta_col] == oponente(color))
       {
         i = line + delta_line;        
         j = col + delta_col;        
         while(1)
         {
           i = i + delta_line;          
           j = j + delta_col;           

           if(i < 0 || j < 0 || i >= SZ)
             break;
           
           if(board[i][j] == '.')
             break;

           if(board[i][j] == color)
           {                                   // FAZ A TROCA DAS PEÇAS, PASSANSO A ASSIM A PERTENCEREM AO OUTRO JOGADOR
             while(board[i = i - delta_line][j = j - delta_col]== oponente(color))
               board[i][j] = color;    
             break;                    
           } 
         }
       }
     }
   return 0;
}

int count_pieces(char board[SZ][SZ], char color)
{
   int pecas = 0;      
   int line;             // O COMPUTADOR COMEÇA COM 100 PEÇAS "int pecas = 100;"
   int col;
  oponente(color);

   for(line = 0; line < SZ; line++) 
     for(col = 0; col < SZ; col++)
   { 
     pecas = pecas - board[line][col] == oponente(color);  //DECREMENTA O NUMERO DE PEÇAS DO COMPUTADOR
     pecas = pecas + board[line][col] == color;         //AUMENTA O NUMERO DE PEÇAS DO JOGADOR
   }
   return pecas;     
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

       atualizar_pecas= count_pieces(new_board, color);  //ATUALIZA A FUNÇÃO QUE CONTA O NUMERO DE PEÇAS DE CADA UM

       
     }
   return pecas;                   
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