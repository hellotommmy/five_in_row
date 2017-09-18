#ifndef DECIDE_H
#define DECIDE_H
#include "comm.h"
#include "node.h"
#define DEPTH 6
int step_taken1,step_taken2;
int minmax(node_t *node, int depth, int maxPlayer);
void board_to_node(char board[BOARD_LEN][BOARD_LEN], node_t *node);
node_t *child_of(node_t * parent, int i, int j);
int heuristic(node_t *node);
int out = 0;
int sensible(node_t * node, int dim1, int dim2);


struct triple *MinMaxFIR(dnode_t *node, int dep, int min, int max);
#endif
