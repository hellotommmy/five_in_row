#include "decide.h"
#include "node.h"
/*
        for(child){
            tempv = MinMaxFIR(child, dep - 1, v, max);
            if(tempv > v){
                v = tempv;
                }
            if( v > max)
                return max;
        }
        return v;
        short version for if(){}block
*/
/*
link_t * construct(node){
    int i,j;
    link_t *list;
    list = ll_create();
    ll_init(list);
    for(i = 0; i < BOARD_LEN; i++){
        for(j = 0; j < BOARD_LEN; j++){
            if(RecordBoard[i][j] == 0){//make_child requires the state in the node
                child = make_child(node,i,j);
                if(child->score > thresh)
                    add_to_list(child, list);
            }
        }
    }
    return list;
}
*/
/*A1:(PRECONCEIVED CODE)
    if (leaf(node) || dep == 0)//split the 2 may be better, since leaf's work will be repeated in the evaluate function by absolute_lose
        return evaluate(node);
A1(END)        */
//return the points of this node and what action the next person 
//will take given this node
int absolute_lose(dnode_t *node){
    if(node->player == -1 && node->connect_5_b || node->player == 1 && node->connect_5_w)
        return 1;
    else
        return 0;
}
int almost_lose(dnode_t *node){
    return 0;
}
int almost_win(dnode_t *node){
    return 0;
}
void decide_3(int i, int j){
    dnode_t * node = board_to_dnode(RecordBoard, i , j);
    struct triple *v;
    v = MinMaxFIR(node, DEPTH, -INF, INF);
    fprintf(fp,"x:%d, y:%d\n", v->i, v->j);
    //TODO:test code
    x = v->i;
    y = v->j;
    free(v);
    free_child(node);
}
struct triple *MinMaxFIR(dnode_t *node, int dep, int min, int max){
    struct triple *v,*tempv;
    dnode_t *child;
    int i,j;
    char c;
    anode_t *iter;
    v = (struct triple *)malloc(sizeof(struct triple));
    int k;
//A1(REAL CODE)
    if(absolute_lose(node)){//the player has made a 5 run just now so 
        //current player will absolutely lose.
        v->val = (-1) * (node->player) * INF;//say, in min player's turn, found out max player has won
        return v;
    }
    //optimization: the leaf node can be found beforehead, several plies earlier
    if(almost_lose(node)){//e.g. the other player already made a living 4, 2 living 3, a 4-3, etc.
    //now place the stone that blocks the shortest path which leads to a losing play
        ;    
    }
    if(almost_win(node)){//the other side is unable to block this player from winning
    //say, it can place a stone that make a 5, living 4, 2 living 3, a 4-3, etc.
        ;
    }
    if(dep == 0){//not leaf node, but dep == 0
    //TODO: if user wants to use this heuristic evaluate function to decide which is the best place,
    //need to implement the determination mechanism of v->i and v->j
        v->val = node->score;
        return v;
    }
//A1(END) note that here we do not have an evaluate function explicitly
    if(node->player == 1){
        v->val = min;
        //construct the possible options
        //child = construct(node);
        //i,j are the positions in node with the highest score
        //need to traverse the snode queue to find children worth taking care of 
        //for(iter = node->node; iter && iter->next != node->node; iter = queue_visit(iter, &i, &j)){//this for loop might be further optimized to cut some unnecessary branches
        for(iter = node->node, iter = queue_visit(iter, &i, &j); iter && iter->next != node->node; iter = queue_visit(iter, &i, &j)){
            //fprintf(fp,"hh i:%d, j:%d\n",i,j);
            //for possible child, generate detailed child node and test the result
            RecordBoard[i][j] = 1;
            child = board_to_dnode(RecordBoard, i, j);//allocate inside this function ***************************************************
            //TODO***************************************************

            //record_to_display();
	        //display_display_board();
	        

            //RecordBoard[i][j] = 1;
            tempv =  MinMaxFIR(child, dep - 1, v->val, max);//if want to print search path, will need to store tempv->i,j here
            fprintf(fp,"child dep:%d\ti:%d,j:%d,val:%d\n",dep - 1, i, j, tempv->val);
            //child dep:2	i:10,j:7,val:8003
//            if(dep == 3 && i == 10 && j == 7 && tempv->val == 8003 && RecordBoard[11][7] == 1 && RecordBoard[10][7] == 1){
//                record_to_display();
//	            display_display_board();  
//	            RecordBoard[i][j] = 0;
//	            record_to_display();              
//            }
            //fprintf(fp,"child->player:%dpoints:%d\n",child->player,tempv->val);
            RecordBoard[i][j] = 0;
            //record_to_display();
            //sleep(2);
            //TODO***************************************************
            if(tempv->val > v->val){
                tempv->i = child->i;
                tempv->j = child->j;
                free(v);
                v = tempv;
            }
            else{
                free(tempv);
            }
            if(v->val > max){
                free_child(child);
                v->val = max;
                return v;
            }
            if(v->val == INF){
                free_child(child);
                return v;            
            }
            free_child(child);                             //free in this function ********************************************************            
        } 
        return v;
    }
    else{
        v->val = max;
        for(iter = node->node, iter = queue_visit(iter, &i, &j); iter && iter->next != node->node; iter = queue_visit(iter, &i, &j)){
            RecordBoard[i][j] = 2;
            child = board_to_dnode(RecordBoard, i, j);
            tempv =  MinMaxFIR(child, dep - 1, min, v->val);
            fprintf(fp,"child dep:%d\ti:%d,j:%d,val:%d\n",dep - 1, i, j, tempv->val);
            RecordBoard[i][j] = 0;
            if(tempv->val < v->val){
                tempv->i = child->i;
                tempv->j = child->j;
                free(v);
                v = tempv;
            }
            else{
                free(tempv);
            }
            if(v->val < min){
                free_child(child);
                v->val = min;
                return v;
            }
            if(v->val == -INF){
                free_child(child);
                return v;
            }
            free_child(child);               
        }
        return v;   
    }
}




































void decide_2(int player){
    int max_value;
    node_t *current_board;
    current_board = (node_t *)malloc(sizeof(node_t));
    board_to_node(RecordBoard, current_board);
    current_board->current_dim1 = x;
    current_board->current_dim2 = y;
/*    fprintf(fp,"player:%d,x:%d,y:%d\n",player,x,y);
    pos_t pos;
    pos.dim1 = x;
    pos.dim2 = y;
    if(five_in_row(&pos, RecordBoard))
        fprintf(fp,"yes!!!!!!!!\n");
*/       
    if(player == 1){    
        max_value = minmax(current_board, DEPTH, 1);
        x = step_taken1;
        y = step_taken2;
        fprintf(fp,"%dx:%dy:%d\n",max_value,x,y);
    }
    else{
        max_value = minmax(current_board, DEPTH, 0);
        x = step_taken1;
        y = step_taken2;
        fprintf(fp,"%d\n",max_value);
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
                        fprintf(fp,"depth:%ddim1:%d,dim2:%dv:%dcurrent dim1:%d dim2:%dv:%d\n",depth, i, j,v,child->current_dim1,child->current_dim2,v); 
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
    //fprintf(fp,"*********i%dj%dvalue%d\n",i,j,child->board[i][j]);
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
