#include "decide.h"
void decide_2(int player){
    int max_value;
    node_t *current_board;
    current_board = (node_t *)malloc(sizeof(node_t));
    board_to_node(RecordBoard, current_board);
    current_board->current_dim1 = x;
    current_board->current_dim2 = y;
/*    printf("player:%d,x:%d,y:%d\n",player,x,y);
    pos_t pos;
    pos.dim1 = x;
    pos.dim2 = y;
    if(five_in_row(&pos, RecordBoard))
        printf("yes!!!!!!!!\n");
*/       
    if(player == 1){    
        max_value = minmax(current_board, DEPTH, 1);
        x = step_taken1;
        y = step_taken2;
        printf("%dx:%dy:%d\n",max_value,x,y);
    }
    else{
        max_value = minmax(current_board, DEPTH, 0);
        x = step_taken1;
        y = step_taken2;
        printf("%d\n",max_value);
    }
    
    free(current_board);
}
void board_to_node(char board[BOARD_LEN][BOARD_LEN], node_t *node){
    int i; 
    int j;
    for(i = 0; i < BOARD_LEN; i++){
        for(j = 0; j < BOARD_LEN; j++){
            if(board[i][j] != 0){
                node->stones_count++;
            }
            node->board[i][j] = board[i][j];

        }
    }
}
int minmax(node_t *node, int depth, int maxPlayer){
    pos_t latest;
    latest.dim1 = node->current_dim1;
    latest.dim2 = node->current_dim2;
    if((node->stones_count >=9) && five_in_row(&latest, node->board)){
        //need to store this step?
        if(maxPlayer){//the opponent wins
            return -INF;          
        }
        else{ 
            return INF;
            }
    }
    if(node->stones_count == BOARD_LEN*BOARD_LEN)
        return 0;
    if(depth == 0)
        return heuristic(node);

    int bestval;
    node_t *child;
    int v;
    int i,j; //traversal vars
    if(maxPlayer){
        bestval = -INF;
        for(i = 0; i < BOARD_LEN; i++){
            for(j = 0; j < BOARD_LEN; j++){           
                if(sensible(node, i, j)){                
                    child = child_of(node, i, j);
                    
                    v = minmax(child, depth - 1, 0);
/*                    if(i == 9 && j == 5 && maxPlayer && child->stones_count == 21){
                        printf("depth:%ddim1:%d,dim2:%dv:%dcurrent dim1:%d dim2:%dv:%d\n",depth, i, j,v,child->current_dim1,child->current_dim2,v); 
                        display_any_board(child->board);
                        out = 100;
                        sleep(5);
                    }  */                   
                    if(v > bestval){
                        bestval = v;
                        step_taken1 = i;
                        step_taken2 = j;        
                    }
                    free(child);
                }
                if(v == INF)
                    return bestval;
            }
        }
        return bestval;
    }
    else{
        bestval = INF;
        for(i = 0; i < BOARD_LEN; i++){
            for(j = 0; j < BOARD_LEN; j++){
                if(sensible(node, i, j)){
                    child = child_of(node, i, j);   
                    v = minmax(child, depth - 1, 1);
                    if(v < bestval){
                        bestval = v;
                        step_taken1 = i;
                        step_taken2 = j;
                    }
                    free(child);
                }
                if(v == -INF)
                    return bestval;
            }
        } 
        return bestval;
    }      
}
int heuristic(node_t *node){
    return 0;
}
node_t *child_of(node_t * parent, int i, int j){
    node_t *child = (node_t *)malloc(sizeof(node_t));
    memcpy(child,parent,sizeof(node_t));
    child->board[i][j] = 3 - child->board[child->current_dim1][child->current_dim2];
    //printf("*********i%dj%dvalue%d\n",i,j,child->board[i][j]);
    child->stones_count++;
    child->current_dim1 = i;
    child->current_dim2 = j;
    //            display_any_board(child->board);
    return child;
}
int sensible(node_t * node, int dim1, int dim2){
    //reduce search space by eliminating branching factor
    int i,j;
    //should not place on others
    if(node->board[dim1][dim2] != 0)
        return 0; 
    //if within the range of 2 there are other stones: should not deviate from current area
    for(i = -2; i < 3; i++){
        for(j = -2; j < 3; j++){
            if(dim1 + i >= 0 && dim1 + i <= BOARD_LEN - 1 && dim2 + j >=0 && dim2 +j <= BOARD_LEN - 1){
                if(node->board[dim1 + i][dim2 + j] != 0)
                    return 1;
            }
        }
    }
    return 0;
}
/*
01 function minimax(node, depth, maximizingPlayer)
02     if depth = 0 or node is a terminal node
03         return the heuristic value of node

04     if maximizingPlayer
05         bestValue := −∞
06         for each child of node
07             v := minimax(child, depth − 1, FALSE)
08             bestValue := max(bestValue, v)
09         return bestValue

10     else    (* minimizing player *)
11         bestValue := +∞
12         for each child of node
13             v := minimax(child, depth − 1, TRUE)
14             bestValue := min(bestValue, v)
15         return bestValue

(* Initial call for maximizing player *)
minimax(origin, depth, TRUE)
*/
