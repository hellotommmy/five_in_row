#ifndef KERNEL_H
#define KERNEL_H
#include "comm.h"
int horizontal_five_in_row(pos_t * latest_position, char board[BOARD_LEN][BOARD_LEN]);
int vertical_five_in_row(pos_t * latest_position, char board[BOARD_LEN][BOARD_LEN]);
int skew_left_upper_five_in_row(pos_t * latest_position, char board[BOARD_LEN][BOARD_LEN]);
int skew_right_upper_five_in_row(pos_t * latest_position, char board[BOARD_LEN][BOARD_LEN]);
#endif
