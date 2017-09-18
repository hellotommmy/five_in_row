#ifndef DISPLAY_H
#define DISPLAY_H
#include "comm.h"
/*unicode for Box Drawings are 3 bytes long
 there is one Box Drawings Horizontal ━ inserted 
 between each two pairs of consecutive Box Drawings Heavy Down and Horizontal ┳ ┳
that is why we have to add BOARD_LEN - 1 as the total number of unicode char numbers
*/
#define DISPLAY_CHAR_WIDTH ((BOARD_LEN + BOARD_LEN - 1)*3 + 1)
char init_display_board[BOARD_LEN][DISPLAY_CHAR_WIDTH] = {
		"┏━┯━┯━┯━┯━┯━┯━┯━┯━┯━┯━┯━┯━┯━┓",
		"┠─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┨",
		"┠─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┨",
		"┠─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┨",
		"┠─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┨",
		"┠─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┨",
		"┠─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┨",
		"┠─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┨",
		"┠─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┨",
		"┠─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┨",
		"┠─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┨",
		"┠─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┨",
		"┠─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┨",
		"┠─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┨",
		"┗━┷━┷━┷━┷━┷━┷━┷━┷━┷━┷━┷━┷━┷━┛"
		};
		
char display_board[BOARD_LEN][DISPLAY_CHAR_WIDTH];
/*
different playpics
full block
█
左7/8方块
▉
细阴影
░
实心圆圈
●
空心圆圈
○
*/
char Player1[4] = "●";
char Player2[4] = "○";



#endif
