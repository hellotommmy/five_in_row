#ifndef DECIDE_H
#define DECIDE_H
#include "comm.h"
#define DEPTH 4
int step_taken1,step_taken2;
int minmax(node_t *node, int depth, int maxPlayer);
void board_to_node(char board[BOARD_LEN][BOARD_LEN], node_t *node);
node_t *child_of(node_t * parent, int i, int j);
int heuristic(node_t *node);
int out = 0;
int sensible(node_t * node, int dim1, int dim2);
#endif
