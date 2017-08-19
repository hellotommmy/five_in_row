#include "judge.h"
int consecutive(pos_t * latest_position){
    return 0;
}
int five_in_row(pos_t * latest_position, char board[BOARD_LEN][BOARD_LEN]){
    if(horizontal_five_in_row(latest_position,board))
        return 1;
    if(vertical_five_in_row(latest_position,board))
        return 1;
    if(skew_left_upper_five_in_row(latest_position,board))
        return 1;
    if(skew_right_upper_five_in_row(latest_position,board))
        return 1;
    return 0;
}
int horizontal_five_in_row(pos_t * latest_position, char board[BOARD_LEN][BOARD_LEN]){
    int i;
    int dim1 = latest_position->dim1;
    int dim2 = latest_position->dim2;
    int player = board[dim1][dim2];
    int cons = 0;
    for(i = dim2; i >= 0; i--){
        if(board[dim1][i]== player){
            cons++;
            if(cons == 5)
                return 1;
        }
        else{
            cons = 0;
            break;
        }
    }
    for(i = dim2; i <= BOARD_LEN - 1; i++){
        if(board[dim1][i] == player){
            cons++;
            if(cons == 5)
                return 1;
        }
        else{
            cons = 0;
            break;
        }
    }
    return 0;    
}
int vertical_five_in_row(pos_t * latest_position, char board[BOARD_LEN][BOARD_LEN]){
    int i;
    int dim1 = latest_position->dim1;
    int dim2 = latest_position->dim2;
    int player = board[dim1][dim2];
    int cons = 0;
    for(i = dim1; i >= 0; i--){
        if(board[i][dim2]== player){
            cons++;
            if(cons == 5)
                return 1;
        }
        else{
            cons = 0;
            break;
        }
    }
    for(i = dim1; i <= BOARD_LEN - 1; i++){
        if(board[i][dim2] == player){
            cons++;
            if(cons == 5)
                return 1;
        }
        else{
            cons = 0;
            break;
        }
    }
    return 0;    
}
int skew_left_upper_five_in_row(pos_t * latest_position, char board[BOARD_LEN][BOARD_LEN]){
    int i,j;
    int dim1 = latest_position->dim1;
    int dim2 = latest_position->dim2;
    int player = board[dim1][dim2];
    int cons = 0;
    for(i = dim1,j = dim2; i >= 0 && j >= 0; ){
        if(board[i][j]== player){
            cons++;
            if(cons == 5)
                return 1;
        }
        else{
            cons = 0;
            break;
        }
        i--;
        j--;
    }
    for(i = dim1,j = dim2; i <= BOARD_LEN - 1 && j <= BOARD_LEN - 1; ){
        if(board[i][j]== player){
            cons++;
            if(cons == 5)
                return 1;
        }
        else{
            cons = 0;
            break;
        }
        i++;
        j++;
    }
    return 0;   
}
int skew_right_upper_five_in_row(pos_t * latest_position, char board[BOARD_LEN][BOARD_LEN]){
    int i,j;
    int dim1 = latest_position->dim1;
    int dim2 = latest_position->dim2;
    int player = board[dim1][dim2];
    int cons = 0;
    for(i = dim1,j = dim2; i >= 0 && j <= BOARD_LEN - 1; ){
        if(board[i][j]== player){
            cons++;
            if(cons == 5)
                return 1;
        }
        else{
            cons = 0;
            break;
        }
        i--;
        j++;
    }
    for(i = dim1,j = dim2; i <= BOARD_LEN - 1 && j >= 0; ){
        if(board[i][j]== player){
            cons++;
            if(cons == 5)
                return 1;
        }
        else{
            cons = 0;
            break;
        }
        i++;
        j--;
    }
    return 0;   
}
