/*	comm.h

	Common definitions and types.
	Best viewed with tabs set to 4 spaces.
*/

#ifndef COMM_H
#define COMM_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define BOARD_LEN 15
#define INF 2147483647
#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)
char RecordBoard[BOARD_LEN][BOARD_LEN];
FILE *fp;
typedef struct pos {
    int dim1;
    int dim2;
} pos_t;
typedef struct node {
    int current_dim1;
    int current_dim2;
    char board[BOARD_LEN][BOARD_LEN];
    unsigned short stones_count;
    
} node_t;
pos_t latest;
int sign;
int x,y;
//decide if a player wins after he places a stone
int five_in_row(pos_t * latest_position, char (*board)[]);
//int consecutive(pos_t * latest_position, int len);
void decide_1(void);//AI-1
void decide_2(int player);
void decide_3(int i, int j);
void read_in();
void display_any_board(char board[BOARD_LEN][BOARD_LEN]);
void record_to_display();
void display_display_board();
#endif
