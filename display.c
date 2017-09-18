#include "display.h"
/*
void display_board(){
	int i,j;
	for(i = 0; i < BOARD_LEN; i++){
	    if( i == 0){
	        printf_left_upper();
	        for(j = 1; j < BOARD_LEN - 1; j++){
	            print_top();
	        }
	        print_right_upper();
	    }
	    else if( i == BOARD_LEN - 1){
	        printf_left_bottom();
	        for(j = 1; j < BOARD_LEN - 1; j++){
	            print_bot();
	        }
	        print_right_bottom();	    
	    }
	    else{
	        printf_left_midd();
	        for(j = 1; j < BOARD_LEN - 1; j++){
	            print_cross();
	        }
	        print_right_midd();	    
	    }
	}
}

void print_left_upper(){
    printf("┏━
}


*/
void display_any_board(char board[BOARD_LEN][BOARD_LEN]){
    int i,j;
    char temp_display_board[BOARD_LEN][DISPLAY_CHAR_WIDTH];
    for(i = 0; i < BOARD_LEN; i++){
        for(j = 0; j < DISPLAY_CHAR_WIDTH; j++){
            temp_display_board[i][j] = init_display_board[i][j];
        }
    }
     for(i = 0; i < BOARD_LEN; i++){
        for(j = 0; j < BOARD_LEN; j++){
            if(board[i][j] == 0){
                //continue;
                temp_display_board[i][j * 6    ] = init_display_board[i][j * 6    ];
                temp_display_board[i][j * 6 + 1] = init_display_board[i][j * 6 + 1];
                temp_display_board[i][j * 6 + 2] = init_display_board[i][j * 6 + 2];
            }
            else if(board[i][j] == 1){
                temp_display_board[i][j * 6    ] = Player1[0];
                temp_display_board[i][j * 6 + 1] = Player1[1];
                temp_display_board[i][j * 6 + 2] = Player1[2];
            }
            else{
                temp_display_board[i][j * 6    ] = Player2[0];
                temp_display_board[i][j * 6 + 1] = Player2[1];
                temp_display_board[i][j * 6 + 2] = Player2[2];            
            }
         }
      }
    for(i = 0; i < BOARD_LEN; i++){
        for(j = 0; j < DISPLAY_CHAR_WIDTH; j++){
            printf("%c",temp_display_board[i][j]);
        }
        printf("\n");
    }    
}
void display_init_board(){
    int i,j;
    for(i = 0; i < BOARD_LEN; i++){
        for(j = 0; j < DISPLAY_CHAR_WIDTH; j++){
            printf("%c",init_display_board[i][j]);
        }
        printf("\n");
    }
}
void display_display_board(){
    int i,j;
    for(i = 0; i < BOARD_LEN; i++){
        for(j = 0; j < DISPLAY_CHAR_WIDTH; j++){
            printf("%c",display_board[i][j]);
        }
        printf("\n");
    }
}
void init_to_display(){
    int i,j;
    for(i = 0; i < BOARD_LEN; i++){
        for(j = 0; j < DISPLAY_CHAR_WIDTH; j++){
            display_board[i][j] = init_display_board[i][j];
        }
    }    
}
void record_to_display(){
    int i,j;
/*    for(i = 0; i < BOARD_LEN; i++){
        for(j = 0; j < BOARD_LEN; j++){
            if(RecordBoard[i][j] == 0){
                printf("%c%c%c",display_board[i][j * 6],display_board[i][j * 6 + 1],display_board[i][j * 6 + 2]);                
            }
            else if(RecordBoard[i][j] == 1){
                printf("%c%c%c",Player1[0],Player1[1],Player1[2]);
            }
        }
    }
*/
     for(i = 0; i < BOARD_LEN; i++){
        for(j = 0; j < BOARD_LEN; j++){
            if(RecordBoard[i][j] == 0){
                //continue;
                display_board[i][j * 6    ] = init_display_board[i][j * 6    ];
                display_board[i][j * 6 + 1] = init_display_board[i][j * 6 + 1];
                display_board[i][j * 6 + 2] = init_display_board[i][j * 6 + 2];
            }
            else if(RecordBoard[i][j] == 1){
                display_board[i][j * 6    ] = Player1[0];
                display_board[i][j * 6 + 1] = Player1[1];
                display_board[i][j * 6 + 2] = Player1[2];
            }
            else{
                display_board[i][j * 6    ] = Player2[0];
                display_board[i][j * 6 + 1] = Player2[1];
                display_board[i][j * 6 + 2] = Player2[2];            
            }
         }
      }
}
/*
void test_drawing_player(){
    int i , j;
    for(i = 0; i < BOARD_LEN; i++){
        for(j = 0; j < BOARD_LEN; j++){
            RecordBoard[i][j] = (i+j)%2 + 1;
        }
    }
}
*/
void fdisplay(){
    FILE * one_game;
    one_game = fopen("games.txt","a+");
    int i,j;
    for(i = 0; i < BOARD_LEN; i++){
        for(j = 0; j < DISPLAY_CHAR_WIDTH; j++){
            fprintf(one_game,"%c",display_board[i][j]);
        }
        fprintf(one_game,"\n");
    }
    fclose(one_game);    
}
void fdisplay_path(int i, int j){
    FILE * one_game;
    one_game = fopen("games.txt","a+");
}

