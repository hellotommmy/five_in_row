#include "comm.h"
void is0();//is0()用于判断是否处于棋盘正中
void is1();//用于判断对方只下了一个子，周围空空荡荡的情况
void is2();//用于判断对方形成两连的情况
void is3();//对方形成三连
void is4();//对方形成四连
void is5();//再下一个子己方形成三连
void is6();//再下一个子己方形成有封堵四连
void is7();//再下一个子己方形成五连
void is8();//再下一个子己方形成无封堵四连
void is9();//己方 敌方 空白格局
void is10();//还没开始设计
void is11();//还没开始设计
int value(int);//计算每个点的价值的函数
#define TEST 12	
int i,j,k;
int Value[BOARD_LEN][BOARD_LEN][TEST];//记录每个点的连子信息的盘，用三维数组
int valueofpoint[BOARD_LEN][BOARD_LEN];//记录每个点的综合价值
int maxpt;

void is0(){//希望开始棋子位于棋盘正中。给分10
if(i==7&&j==7)
	Value[i][j][0]++;
}
void is1(){//早期设计的比较奇怪的判断，要求敌方落了一颗子，己方一颗子不落，且敌方周围空荡荡的。给分10
if(2<=i&&i<=13&&1<=j&&j<=13&&RecordBoard[i-1][j]==(3-sign)&&RecordBoard[i-2][j]==0&&RecordBoard[i-2][j-1]==0&&RecordBoard[i-2][j+1]==0&&RecordBoard[i-1][j-1]==0&&RecordBoard[i-1][j+1]==0&&RecordBoard[i][j-1]==0&&RecordBoard[i][j+1]==0&&RecordBoard[i+1][j-1]==0&&RecordBoard[i+1][j]==0&&RecordBoard[i+1][j-1]==0)
	Value[i][j][1]++;
if(1<=i&&i<=13&&2<=j&&j<=13&&RecordBoard[i-1][j-2]==0&&RecordBoard[i-1][j-1]==0&&RecordBoard[i-1][j]==0&&RecordBoard[i-2][j+1]==0&&RecordBoard[i][j-2]==0&&RecordBoard[i][j-1]==(3-sign)&&RecordBoard[i][j+1]==0&&RecordBoard[i+1][j+1]==0&&RecordBoard[i+1][j-2]==0&&RecordBoard[i+1][j-1]==0&&RecordBoard[i+1][j]==0)
	Value[i][j][1]++;
if(1<=i&&i<=12&&1<=j&&j<=13&&RecordBoard[i-1][j-1]==0&&RecordBoard[i-1][j]==0&&RecordBoard[i-1][j+1]==0&&RecordBoard[i][j-1]==0&&RecordBoard[i][j+1]==0&&RecordBoard[i+1][j-1]==0&&RecordBoard[i+1][j]==(3-sign)&&RecordBoard[i+1][j+1]==0&&RecordBoard[i+2][j-1]==0&&RecordBoard[i+2][j]==0&&RecordBoard[i+2][j+1]==0)
	Value[i][j][1]++;
if(1<=i&&i<=13&&1<=j&&j<=12&&RecordBoard[i-1][j-1]==0&&RecordBoard[i-1][j]==0&&RecordBoard[i-1][j+1]==0&&RecordBoard[i-1][j+2]==0&&RecordBoard[i][j-1]==0&&RecordBoard[i][j+1]==(3-sign)&&RecordBoard[i][j+2]==0&&RecordBoard[i+1][j-1]==0&&RecordBoard[i+1][j]==0&&RecordBoard[i+1][j+1]==0&&RecordBoard[i+1][j+2]==0)
	Value[i][j][1]++;
if(2<=i&&i<=13&&2<=j&&j<=13&&RecordBoard[i-1][j-1]==(3-sign)&&RecordBoard[i-2][j-2]==0&&RecordBoard[i-2][j-1]==0&&RecordBoard[i-2][j]==0&&RecordBoard[i-1][j-2]==0&&RecordBoard[i-1][j]==0&&RecordBoard[i-1][j+1]==0&&RecordBoard[i][j-2]==0&&RecordBoard[i][j-1]==0&&RecordBoard[i][j+1]==0&&RecordBoard[i+1][j-1]==0&&RecordBoard[i+1][j]==0&&RecordBoard[i+1][j+1]==0)
	Value[i][j][1]++;
if(2<=i&&i<=13&&1<=j&&j<=12&&RecordBoard[i-1][j+1]==(3-sign)&&RecordBoard[i-2][j]==0&&RecordBoard[i-2][j+1]==0&&RecordBoard[i-2][j+2]==0&&RecordBoard[i-1][j-1]==0&&RecordBoard[i-1][j]==0&&RecordBoard[i-1][j+2]==0&&RecordBoard[i][j-1]==0&&RecordBoard[i][j+1]==0&&RecordBoard[i][j+2]==0&&RecordBoard[i+1][j-1]==0&&RecordBoard[i+1][j]==0&&RecordBoard[i+1][j+1]==0)
	Value[i][j][1]++;
if(1<=i&&i<=12&&1<=j&&j<=12&&RecordBoard[i+1][j+1]==(3-sign)&&RecordBoard[i-1][j-1]==0&&RecordBoard[i-1][j]==0&&RecordBoard[i-1][j+1]==0&&RecordBoard[i][j-1]==0&&RecordBoard[i][j+1]==0&&RecordBoard[i][j+2]==0&&RecordBoard[i+1][j-1]==0&&RecordBoard[i+1][j]==0&&RecordBoard[i+1][j+2]==0&&RecordBoard[i+2][j]==0&&RecordBoard[i+2][j+1]==0&&RecordBoard[i+2][j+2]==0)
	Value[i][j][1]++;
if(1<=i&&i<=12&&2<=j&&j<=13&&RecordBoard[i+1][j-1]==(3-sign)&&RecordBoard[i-1][j-1]==0&&RecordBoard[i-1][j]==0&&RecordBoard[i-1][j+1]==0&&RecordBoard[i][j-2]==0&&RecordBoard[i][j-1]==0&&RecordBoard[i][j+1]==0&&RecordBoard[i+1][j-2]==0&&RecordBoard[i+1][j]==0&&RecordBoard[i+1][j+1]==0&&RecordBoard[i+2][j-2]==0&&RecordBoard[i+2][j-1]==0&&RecordBoard[i+2][j]==0)
	Value[i][j][1]++;
}

void is2(){//敌方成二，包括连着的二和中间隔着一个的二。给分10
//前八个是连着的二
if(j<=11&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==(3-sign)&&RecordBoard[i][j+2]==(3-sign)&&RecordBoard[i][j+3]==0)
	Value[i][j][2]++;
if(3<=j&&RecordBoard[i][j]==0&&RecordBoard[i][j-1]==(3-sign)&&RecordBoard[i][j-2]==(3-sign)&&RecordBoard[i][j-3]==0)
	Value[i][j][2]++;
if(i<=11&&RecordBoard[i][j]==0&&RecordBoard[i+1][j]==(3-sign)&&RecordBoard[i+2][j]==(3-sign)&&RecordBoard[i+3][j]==0)
	Value[i][j][2]++;
if(i>=3&&RecordBoard[i][j]==0&&RecordBoard[i-1][j]==(3-sign)&&RecordBoard[i-2][j]==(3-sign)&&RecordBoard[i-3][j]==0)
	Value[i][j][2]++;	
if(i>=3&&j>=3&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==(3-sign)&&RecordBoard[i-2][j-2]==(3-sign)&&RecordBoard[i-3][j-3]==0)
	Value[i][j][2]++;	
if(i>=3&&j<=11&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==(3-sign)&&RecordBoard[i-2][j+2]==(3-sign)&&RecordBoard[i-3][j+3]==0)
	Value[i][j][2]++;	
if(i<=11&&j<=11&&RecordBoard[i][j]==0&&RecordBoard[i+1][j+1]==(3-sign)&&RecordBoard[i+2][j+2]==(3-sign)&&RecordBoard[i+3][j+3]==0)
	Value[i][j][2]++;
if(i<=11&&j>=3&&RecordBoard[i][j]==0&&RecordBoard[i+1][j-1]==(3-sign)&&RecordBoard[i+2][j-2]==(3-sign)&&RecordBoard[i+3][j-3]==0)
	Value[i][j][2]++;

//后四个是中间空了的二
if(i>=1&&i<=13&&RecordBoard[i][j]==0&&RecordBoard[i-1][j]==(3-sign)&&RecordBoard[i+1][j]==(3-sign))
	Value[i][j][2]++;
if(j>=1&&j<=13&&RecordBoard[i][j]==0&&RecordBoard[i][j-1]==(3-sign)&&RecordBoard[i][j+1]==(3-sign))
	Value[i][j][2]++;
if(i>=1&&i<=13&&j>=1&&j<=13&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==(3-sign)&&RecordBoard[i+1][j+1]==(3-sign))
	Value[i][j][2]++;	
if(i>=1&&i<=13&&j>=1&&j<=13&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==(3-sign)&&RecordBoard[i+1][j-1]==(3-sign))
	Value[i][j][2]++;	
}

void is3(){//对方已成三。给分100
//连活三
if(4<=i&&i<=13&&RecordBoard[i-1][j]==(3-sign)&&RecordBoard[i-2][j]==(3-sign)&&RecordBoard[i-3][j]==(3-sign)&&RecordBoard[i-4][j]==0&&RecordBoard[i+1][j]==0)
	Value[i][j][3]++;
if(0<=i&&i<=10&&RecordBoard[i+1][j]==(3-sign)&&RecordBoard[i+2][j]==(3-sign)&&RecordBoard[i+3][j]==(3-sign)&&RecordBoard[i+4][j]==0&&RecordBoard[i-1][j]==0)
	Value[i][j][3]++;
if(1<=j&&i<=10&&RecordBoard[i][j+1]==(3-sign)&&RecordBoard[i][j+2]==(3-sign)&&RecordBoard[i][j+3]==(3-sign)&&RecordBoard[i][j+4]==0&&RecordBoard[i][j-1]==0)
	Value[i][j][3]++;
if(4<=j&&i<=13&&RecordBoard[i][j-3]==(3-sign)&&RecordBoard[i][j-2]==(3-sign)&&RecordBoard[i][j-1]==(3-sign)&&RecordBoard[i][j-4]==0&&RecordBoard[i][j+1]==0)
	Value[i][j][3]++;
if(4<=i&&i<=13&&4<=j&&j<=13&&RecordBoard[i-4][j-4]==0&&RecordBoard[i-3][j-3]==(3-sign)&&RecordBoard[i-2][j-2]==(3-sign)&&RecordBoard[i-1][j-1]==(3-sign)&&RecordBoard[i+1][j+1]==0)
	Value[i][j][3]++;
if(1<=i&&i<=10&&4<=j&&j<=13&&RecordBoard[i+4][j-4]==0&&RecordBoard[i+3][j-3]==(3-sign)&&RecordBoard[i+2][j-2]==(3-sign)&&RecordBoard[i+1][j-1]==(3-sign)&&RecordBoard[i-1][j+1]==0)
	Value[i][j][3]++;
if(1<=i&&i<=10&&1<=j&&j<=10&&RecordBoard[i+4][j+4]==0&&RecordBoard[i+3][j+3]==(3-sign)&&RecordBoard[i+2][j+2]==(3-sign)&&RecordBoard[i+1][j+1]==(3-sign)&&RecordBoard[i-1][j-1]==0)
	Value[i][j][3]++;
if(4<=i&&i<=13&&1<=j&&j<=10&&RecordBoard[i-4][j+4]==0&&RecordBoard[i-3][j+3]==(3-sign)&&RecordBoard[i-2][j+2]==(3-sign)&&RecordBoard[i-1][j+1]==(3-sign)&&RecordBoard[i+1][j-1]==0)
	Value[i][j][3]++;

//跳活三
if(j>=2&&j<=11&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==(3-sign)&&RecordBoard[i][j+2]==(3-sign)&&RecordBoard[i][j+3]==0&&RecordBoard[i][j-1]==(3-sign)&&RecordBoard[i][j-2]==0)	
	Value[i][j][3]++;
if(j>=3&&j<=12&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==(3-sign)&&RecordBoard[i][j+2]==0&&RecordBoard[i][j-1]==(3-sign)&&RecordBoard[i][j-2]==(3-sign)&&RecordBoard[i][j-3]==0)	
	Value[i][j][3]++;
if(i>=2&&i<=11&&RecordBoard[i][j]==0&&RecordBoard[i-1][j]==(3-sign)&&RecordBoard[i-2][j]==0&&RecordBoard[i+1][j]==(3-sign)&&RecordBoard[i+2][j]==(3-sign)&&RecordBoard[i+3][j]==0)	
	Value[i][j][3]++;
if(i>=3&&i<=12&&RecordBoard[i][j]==0&&RecordBoard[i-1][j]==(3-sign)&&RecordBoard[i-2][j]==(3-sign)&&RecordBoard[i-3][j]==0&&RecordBoard[i+1][j]==(3-sign)&&RecordBoard[i+2][j]==0)	
	Value[i][j][3]++;
if(j>=2&&j<=11&&i>=2&&i<=11&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==(3-sign)&&RecordBoard[i-2][j-2]==0&&RecordBoard[i+1][j+1]==(3-sign)&&RecordBoard[i+2][j+2]==(3-sign)&&RecordBoard[i+3][j+3]==0)
	Value[i][j][3]++;
if(i>=3&&i<=12&&j>=3&&j<=12&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==(3-sign)&&RecordBoard[i-2][j-2]==(3-sign)&&RecordBoard[i-3][j-3]==0&&RecordBoard[i+1][j+1]==(3-sign)&&RecordBoard[i+2][j+2]==0)	
	Value[i][j][3]++;	
if(i>=2&&i<=11&&j>=3&&j<=12&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==(3-sign)&&RecordBoard[i-2][j+2]==0&&RecordBoard[i+1][j-1]==(3-sign)&&RecordBoard[i+2][j-2]==(3-sign)&&RecordBoard[i+3][j-3]==0)
	Value[i][j][3]++;
if(i>=3&&i<=12&&j>=2&&j<=11&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==(3-sign)&&RecordBoard[i-2][j+2]==(3-sign)&&RecordBoard[i-3][j+3]==0&&RecordBoard[i+1][j-1]==(3-sign)&&RecordBoard[i+2][j-2]==0)	
	Value[i][j][3]++;
}

void is4(){//对方已成四，如果不堵，下一次电脑自己就输了。给分1000
//前八个if是连在一起的四
if(i<=9&&RecordBoard[i][j]==0&&RecordBoard[i+1][j]==(3-sign)&&RecordBoard[i+2][j]==(3-sign)&&RecordBoard[i+3][j]==(3-sign)&&RecordBoard[i+4][j]==(3-sign)&&RecordBoard[i+5][j]==sign)
	Value[i][j][4]++;
if(5<=i&&RecordBoard[i][j]==0&&RecordBoard[i-1][j]==(3-sign)&&RecordBoard[i-2][j]==(3-sign)&&RecordBoard[i-3][j]==(3-sign)&&RecordBoard[i-4][j]==(3-sign)&&RecordBoard[i-5][j]==sign)
	Value[i][j][4]++;
if(5<=j&&RecordBoard[i][j]==0&&RecordBoard[i][j-1]==(3-sign)&&RecordBoard[i][j-2]==(3-sign)&&RecordBoard[i][j-3]==(3-sign)&&RecordBoard[i][j-4]==(3-sign)&&RecordBoard[i][j-5]==sign)
	Value[i][j][4]++;
if(j<=9&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==(3-sign)&&RecordBoard[i][j+2]==(3-sign)&&RecordBoard[i][j+3]==(3-sign)&&RecordBoard[i][j+4]==(3-sign)&&RecordBoard[i][j+5]==sign)
	Value[i][j][4]++;
if(5<=j&&5<=i&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==(3-sign)&&RecordBoard[i-2][j-2]==(3-sign)&&RecordBoard[i-3][j-3]==(3-sign)&&RecordBoard[i-4][j-4]==(3-sign)&&RecordBoard[i-5][j-5]==sign)
	Value[i][j][4]++;
if(i<=9&&j<=9&&RecordBoard[i][j]==0&&RecordBoard[i+1][j+1]==(3-sign)&&RecordBoard[i+2][j+2]==(3-sign)&&RecordBoard[i+3][j+3]==(3-sign)&&RecordBoard[i+4][j+4]==(3-sign)&&RecordBoard[i+5][j+5]==sign)
	Value[i][j][4]++;
if(j<=9&&5<=i&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==(3-sign)&&RecordBoard[i-2][j+2]==(3-sign)&&RecordBoard[i-3][j+3]==(3-sign)&&RecordBoard[i-4][j+4]==(3-sign)&&RecordBoard[i-5][j+5]==sign)
	Value[i][j][4]++;	
if(i<=9&&5<=j&&RecordBoard[i][j]==0&&RecordBoard[i+1][j-1]==(3-sign)&&RecordBoard[i+2][j-2]==(3-sign)&&RecordBoard[i+3][j-3]==(3-sign)&&RecordBoard[i+4][j-4]==(3-sign)&&RecordBoard[i+5][j-5]==sign)
	Value[i][j][4]++;
//后十二个if是没有连在一起的跳四
if(	i<=11 && i>=1 && RecordBoard[i-1][j]==3-sign && RecordBoard[i][j]==0 && RecordBoard[i+1][j]==3-sign &&
                   											RecordBoard[i+2][j]==3-sign &&
                   											RecordBoard[i+3][j]==3-sign)
                   											Value[i][j][4]++;
if(   i<=13 &&	i>=3 &&   RecordBoard[i-3][j]==3-sign &&
				   										RecordBoard[i-2][j]==3-sign &&
				   										RecordBoard[i-1][j]==3-sign &&
				   										RecordBoard[i][j]==0 &&
				   										RecordBoard[i+1][j]==3-sign)
				   										Value[i][j][4]++;										
if(i<=12 &&	i>=2 && 									RecordBoard[i-2][j]==3-sign &&
				   										RecordBoard[i-1][j]==3-sign &&
				   										RecordBoard[i][j]==0 &&
				   										RecordBoard[i+1][j]==3-sign &&
                   										RecordBoard[i+2][j]==3-sign)
                   										Value[i][j][4]++;
if(   j<=13 &&	j>=3  && RecordBoard[i][j-3]==3-sign && RecordBoard[i][j-2]==3-sign &&RecordBoard[i][j-1]==3-sign && RecordBoard[i][j]==0 && RecordBoard[i][j+1]==3-sign)
														Value[i][j][4]++;
if(   j<=11 &&	j>=1  && RecordBoard[i][j-1]==3-sign && RecordBoard[i][j+1]==3-sign &&RecordBoard[i][j+2]==3-sign && RecordBoard[i][j]==0 && RecordBoard[i][j+3]==3-sign)
														Value[i][j][4]++;
if (j<=12 && j>=2 && RecordBoard[i][j-2]==3-sign && RecordBoard[i][j-1]==3-sign && RecordBoard[i][j]==0 && RecordBoard[i][j+1]==3-sign && RecordBoard[i][j+2]==3-sign)	
														Value[i][j][4]++;
if(i>=2&&i<=12&&j>=2&&j<=12&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==(3-sign)&&RecordBoard[i+1][j+1]==(3-sign)&&RecordBoard[i-2][j-2]==(3-sign)&&RecordBoard[i+2][j+2]==(3-sign))
	Value[i][j][4]++;	
if(i>=2&&i<=12&&j>=2&&j<=12&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==(3-sign)&&RecordBoard[i+1][j-1]==(3-sign)&&RecordBoard[i-2][j+2]==(3-sign)&&RecordBoard[i+2][j-2]==(3-sign))
	Value[i][j][4]++;																												
if(i>=1&&i<=11&&j>=1&&j<=11&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==(3-sign)&&RecordBoard[i+1][j+1]==(3-sign)&&RecordBoard[i+2][j+2]==(3-sign)&&RecordBoard[i+3][j+3]==(3-sign))
	Value[i][j][4]++;
if(i>=1&&i<=11&&j>=3&&j<=13&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==(3-sign)&&RecordBoard[i+1][j-1]==(3-sign)&&RecordBoard[i+2][j-2]==(3-sign)&&RecordBoard[i+3][j-3]==(3-sign))
	Value[i][j][4]++;                    										                    										
if(i>=3&&i<=13&&j>=3&&j<=13&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==(3-sign)&&RecordBoard[i+1][j+1]==(3-sign)&&RecordBoard[i-2][j-2]==(3-sign)&&RecordBoard[i-3][j-3]==(3-sign))
	Value[i][j][4]++;
if(i>=3&&i<=13&&j>=1&&j<=11&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==(3-sign)&&RecordBoard[i+1][j-1]==(3-sign)&&RecordBoard[i-2][j+2]==(3-sign)&&RecordBoard[i-3][j+3]==(3-sign))
	Value[i][j][4]++;
}

void is5(){//下了这个子，己方就能成3.给分40
//这八个对应连三
if(j<=11&&j>=1&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==sign&&RecordBoard[i][j+2]==sign&&RecordBoard[i][j+3]==0&&RecordBoard[i][j-1]==0)
	Value[i][j][5]++;
if(3<=j&&j<=13&&RecordBoard[i][j+1]==0&&RecordBoard[i][j]==0&&RecordBoard[i][j-1]==sign&&RecordBoard[i][j-2]==sign&&RecordBoard[i][j-3]==0)
	Value[i][j][5]++;
if(i<=11&&i>=1&&RecordBoard[i-1][j]==0&&RecordBoard[i][j]==0&&RecordBoard[i+1][j]==sign&&RecordBoard[i+2][j]==sign&&RecordBoard[i+3][j]==0)
	Value[i][j][5]++;
if(i>=3&&i<=13&&RecordBoard[i+1][j]==0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j]==sign&&RecordBoard[i-2][j]==sign&&RecordBoard[i-3][j]==0)
	Value[i][j][5]++;	
if(i>=3&&j>=3&&i<=13&&j<=13&&RecordBoard[i+1][j+1]==0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==sign&&RecordBoard[i-2][j-2]==sign&&RecordBoard[i-3][j-3]==0)
	Value[i][j][5]++;	
if(i>=3&&i<=13&&j>=1&&j<=11&&RecordBoard[i+1][j-1]==0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==sign&&RecordBoard[i-2][j+2]==sign&&RecordBoard[i-3][j+3]==0)
	Value[i][j][5]++;	
if(i<=11&&j<=11&&i>=1&&j>=1&&RecordBoard[i-1][j-1]==0&&RecordBoard[i][j]==0&&RecordBoard[i+1][j+1]==sign&&RecordBoard[i+2][j+2]==sign&&RecordBoard[i+3][j+3]==0)
	Value[i][j][5]++;
if(i<=11&&j>=3&&i>=1&&j<=13&&RecordBoard[i-1][j+1]==0&&RecordBoard[i][j]==0&&RecordBoard[i+1][j-1]==sign&&RecordBoard[i+2][j-2]==sign&&RecordBoard[i+3][j-3]==0)
	Value[i][j][5]++;
//连上中间就成连三
if(j+2<=14&&j-2>=0&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==sign&&RecordBoard[i][j+2]==0&&RecordBoard[i][j-1]==sign&&RecordBoard[i][j-2]==0)
	Value[i][j][5]++;
if(i+2<=14&&i-2>=0&&RecordBoard[i][j]==0&&RecordBoard[i+1][j]==sign&&RecordBoard[i+2][j]==0&&RecordBoard[i-1][j]==sign&&RecordBoard[i-2][j]==0)
	Value[i][j][5]++;
if(i+2<=14&&i-2>=0&&j+2<=14&&j-2>=0&&RecordBoard[i][j]==0&&RecordBoard[i-2][j-2]==0&&RecordBoard[i-1][j-1]==sign&&RecordBoard[i+1][j+1]==sign&&RecordBoard[i+2][j+2]==0)
	Value[i][j][5]++;
if(i+2<=14&&i-2>=0&&j+2<=14&&j-2>=0&&RecordBoard[i][j]==0&&RecordBoard[i+2][j-2]==0&&RecordBoard[i+1][j-1]==sign&&RecordBoard[i-1][j+1]==sign&&RecordBoard[i-2][j+2]==0)
	Value[i][j][5]++;
}
void is6(){//下了这个子，己方就能成四，但是有一端是被封住的，给分101
//这八个对应连四
if(4<=i&&i<=13&&RecordBoard[i-1][j]==sign&&RecordBoard[i-2][j]==sign&&RecordBoard[i-3][j]==sign&&RecordBoard[i-4][j]==(3-sign)&&RecordBoard[i+1][j]==0)
	Value[i][j][6]++;
if(1<=i&&i<=10&&RecordBoard[i+1][j]==sign&&RecordBoard[i+2][j]==sign&&RecordBoard[i+3][j]==sign&&RecordBoard[i+4][j]==(3-sign)&&RecordBoard[i-1][j]==0)
	Value[i][j][6]++;
if(1<=j&&j<=10&&RecordBoard[i][j+1]==sign&&RecordBoard[i][j+2]==sign&&RecordBoard[i][j+3]==sign&&RecordBoard[i][j+4]==(3-sign)&&RecordBoard[i][j-1]==0)
	Value[i][j][6]++;
if(4<=j&&j<=13&&RecordBoard[i][j-3]==sign&&RecordBoard[i][j-2]==sign&&RecordBoard[i][j-1]==sign&&RecordBoard[i][j-4]==(3-sign)&&RecordBoard[i][j+1]==0)
	Value[i][j][6]++;
if(4<=i&&i<=13&&4<=j&&j<=13&&RecordBoard[i-4][j-4]==(3-sign)&&RecordBoard[i-3][j-3]==sign&&RecordBoard[i-2][j-2]==sign&&RecordBoard[i-1][j-1]==sign&&RecordBoard[i+1][j+1]==0)
	Value[i][j][6]++;
if(1<=i&&i<=10&&4<=j&&j<=13&&RecordBoard[i+4][j-4]==(3-sign)&&RecordBoard[i+3][j-3]==sign&&RecordBoard[i+2][j-2]==sign&&RecordBoard[i+1][j-1]==sign&&RecordBoard[i-1][j+1]==0)
	Value[i][j][6]++;
if(1<=i&&i<=10&&1<=j&&j<=10&&RecordBoard[i+4][j+4]==(3-sign)&&RecordBoard[i+3][j+3]==sign&&RecordBoard[i+2][j+2]==sign&&RecordBoard[i+1][j+1]==sign&&RecordBoard[i-1][j-1]==0)
	Value[i][j][6]++;
if(4<=i&&i<=13&&1<=j&&j<=10&&RecordBoard[i-4][j+4]==(3-sign)&&RecordBoard[i-3][j+3]==sign&&RecordBoard[i-2][j+2]==sign&&RecordBoard[i-1][j+1]==sign&&RecordBoard[i+1][j-1]==0)
	Value[i][j][6]++;
}
void is7(){
//己方已成四，下了这一步就赢了。给分最高，10000
if(i<=10&&RecordBoard[i][j]==0&&RecordBoard[i+1][j]==sign&&RecordBoard[i+2][j]==sign&&RecordBoard[i+3][j]==sign&&RecordBoard[i+4][j]==sign)
	Value[i][j][7]++;
if(4<=i&&RecordBoard[i][j]==0&&RecordBoard[i-1][j]==sign&&RecordBoard[i-2][j]==sign&&RecordBoard[i-3][j]==sign&&RecordBoard[i-4][j]==sign)
	Value[i][j][7]++;
if(4<=j&&RecordBoard[i][j]==0&&RecordBoard[i][j-1]==sign&&RecordBoard[i][j-2]==sign&&RecordBoard[i][j-3]==sign&&RecordBoard[i][j-4]==sign)
	Value[i][j][7]++;
if(j<=10&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==sign&&RecordBoard[i][j+2]==sign&&RecordBoard[i][j+3]==sign&&RecordBoard[i][j+4]==sign)
	Value[i][j][7]++;
if(4<=j&&5<=i&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==sign&&RecordBoard[i-2][j-2]==sign&&RecordBoard[i-3][j-3]==sign&&RecordBoard[i-4][j-4]==sign)
	Value[i][j][7]++;
if(i<=10&&j<=10&&RecordBoard[i][j]==0&&RecordBoard[i+1][j+1]==sign&&RecordBoard[i+2][j+2]==sign&&RecordBoard[i+3][j+3]==sign&&RecordBoard[i+4][j+4]==sign)
	Value[i][j][7]++;
if(j<=10&&4<=i&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==sign&&RecordBoard[i-2][j+2]==sign&&RecordBoard[i-3][j+3]==sign&&RecordBoard[i-4][j+4]==sign)
	Value[i][j][7]++;	
if(i<=10&&4<=j&&RecordBoard[i][j]==0&&RecordBoard[i+1][j-1]==sign&&RecordBoard[i+2][j-2]==sign&&RecordBoard[i+3][j-3]==sign&&RecordBoard[i+4][j-4]==sign)
	Value[i][j][7]++;
if(i>=2&&i<=12&&RecordBoard[i][j]==0&&RecordBoard[i-2][j]==sign&&RecordBoard[i-1][j]==sign&&RecordBoard[i+1][j]==sign&&RecordBoard[i+2][j]==sign)
	Value[i][j][7]++;
if(j>=2&&j<=12&&RecordBoard[i][j]==0&&RecordBoard[i][j-2]==sign&&RecordBoard[i][j-1]==sign&&RecordBoard[i][j+1]==sign&&RecordBoard[i][j+2]==sign)
	Value[i][j][7]++;
if(j>=2&&j<=12&&i>=2&&i<=12&&RecordBoard[i][j]==0&&RecordBoard[i-2][j-2]==sign&&RecordBoard[i-1][j-1]==sign&&RecordBoard[i+1][j+1]==sign&&RecordBoard[i+2][j+2]==sign)
	Value[i][j][7]++;
if(j>=2&&j<=12&&i>=2&&i<=12&&RecordBoard[i][j]==0&&RecordBoard[i+2][j-2]==sign&&RecordBoard[i+1][j-1]==sign&&RecordBoard[i-1][j+1]==sign&&RecordBoard[i-2][j+2]==sign)
	Value[i][j][7]++;
//横竖方向1+3型
if(i-1>=0&&i+3<=14&&RecordBoard[i][j]==0&&RecordBoard[i-1][j]==sign&&RecordBoard[i+1][j]==sign&&RecordBoard[i+2][j]==sign&&RecordBoard[i+3][j]==sign)
	Value[i][j][7]++;
if(i-3>=0&&i+1<=14&&RecordBoard[i][j]==0&&RecordBoard[i-1][j]==sign&&RecordBoard[i-2][j]==sign&&RecordBoard[i-3][j]==sign&&RecordBoard[i+1][j]==sign)
	Value[i][j][7]++;
if(j-1>=0&&j+3<=14&&RecordBoard[i][j]==0&&RecordBoard[i][j-1]==sign&&RecordBoard[i][j+1]==sign&&RecordBoard[i][j+2]==sign&&RecordBoard[i][j+3]==sign)
	Value[i][j][7]++;
if(j-3>=0&&j+1<=14&&RecordBoard[i][j]==0&&RecordBoard[i][j-1]==sign&&RecordBoard[i][j-2]==sign&&RecordBoard[i][j-3]==sign&&RecordBoard[i][j+1]==sign)
	Value[i][j][7]++;
//斜方向1+3型
if(j-3>=0&&j+1<=14&&i-3>=0&&i+1<=14&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==sign&&RecordBoard[i-2][j-2]==sign&&RecordBoard[i-3][j-3]==sign&&RecordBoard[i+1][j+1]==sign)
	Value[i][j][7]++;
if(i+3<=14&&i-1>=0&&j+3<=14&&j-1>=0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==sign&&RecordBoard[i+1][j+1]==sign&&RecordBoard[i+2][j+2]==sign&&RecordBoard[i+3][j+3]==sign)
	Value[i][j][7]++;
if(i+3<=14&&i-1>=0&&j+1<=14&&j-3>=0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==sign&&RecordBoard[i+1][j-1]==sign&&RecordBoard[i+2][j-2]==sign&&RecordBoard[i+3][j-3]==sign)
	Value[i][j][7]++;
if(j+3<=14&&j-1>=0&&i+1<=14&&i-3>=0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==sign&&RecordBoard[i+1][j-1]==sign&&RecordBoard[i-2][j+2]==sign&&RecordBoard[i-3][j+3]==sign)
	Value[i][j][7]++;
		}
void is8(){//再下这一步己方就能成活四，给分450
//这八种对应于连三所成的活四
if(4<=i&&i<=13&&RecordBoard[i-1][j]==sign&&RecordBoard[i-2][j]==sign&&RecordBoard[i-3][j]==sign&&RecordBoard[i-4][j]==0&&RecordBoard[i+1][j]==0)
	Value[i][j][8]++;
if(1<=i&&i<=10&&RecordBoard[i+1][j]==sign&&RecordBoard[i+2][j]==sign&&RecordBoard[i+3][j]==sign&&RecordBoard[i+4][j]==0&&RecordBoard[i-1][j]==0)
	Value[i][j][8]++;
if(1<=j&&j<=10&&RecordBoard[i][j+1]==sign&&RecordBoard[i][j+2]==sign&&RecordBoard[i][j+3]==sign&&RecordBoard[i][j+4]==0&&RecordBoard[i][j-1]==0)
	Value[i][j][8]++;
if(4<=j&&j<=13&&RecordBoard[i][j-3]==sign&&RecordBoard[i][j-2]==sign&&RecordBoard[i][j-1]==sign&&RecordBoard[i][j-4]==0&&RecordBoard[i][j+1]==0)
	Value[i][j][8]++;
if(4<=i&&i<=13&&4<=j&&j<=13&&RecordBoard[i-4][j-4]==0&&RecordBoard[i-3][j-3]==sign&&RecordBoard[i-2][j-2]==sign&&RecordBoard[i-1][j-1]==sign&&RecordBoard[i+1][j+1]==0)
	Value[i][j][8]++;
if(1<=i&&i<=10&&4<=j&&j<=13&&RecordBoard[i+4][j-4]==0&&RecordBoard[i+3][j-3]==sign&&RecordBoard[i+2][j-2]==sign&&RecordBoard[i+1][j-1]==sign&&RecordBoard[i-1][j+1]==0)
	Value[i][j][8]++;
if(1<=i&&i<=10&&1<=j&&j<=10&&RecordBoard[i+4][j+4]==0&&RecordBoard[i+3][j+3]==sign&&RecordBoard[i+2][j+2]==sign&&RecordBoard[i+1][j+1]==sign&&RecordBoard[i-1][j-1]==0)
	Value[i][j][8]++;
if(4<=i&&i<=13&&1<=j&&j<=10&&RecordBoard[i-4][j+4]==0&&RecordBoard[i-3][j+3]==sign&&RecordBoard[i-2][j+2]==sign&&RecordBoard[i-1][j+1]==sign&&RecordBoard[i+1][j-1]==0)
	Value[i][j][8]++;	
//这八种对应跳三形成的活四
if(3<=i&&i<=12&&RecordBoard[i][j]==0&&RecordBoard[i-1][j]==sign&&RecordBoard[i-2][j]==sign&&RecordBoard[i-3][j]==0&&RecordBoard[i+1][j]==sign&&RecordBoard[i+2][j]==0)
	Value[i][j][8]++;
if(2<=i&&i<=11&&RecordBoard[i][j]==0&&RecordBoard[i+1][j]==sign&&RecordBoard[i+2][j]==sign&&RecordBoard[i+3][j]==0&&RecordBoard[i-1][j]==sign&&RecordBoard[i-2][j]==0)
	Value[i][j][8]++;
if(0<=j-3&&j+2<=14&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==sign&&RecordBoard[i][j+2]==0&&RecordBoard[i][j-1]==sign&&RecordBoard[i][j-2]==sign&&RecordBoard[i][j-3]==0)
	Value[i][j][8]++;
if(0<=j-2&&j+3<=14&&RecordBoard[i][j-2]==0&&RecordBoard[i][j-1]==sign&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==sign&&RecordBoard[i][j+2]==sign&&RecordBoard[i][j+3]==0)
	Value[i][j][8]++;
if(3<=i&&i<=12&&3<=j&&j<=12&&RecordBoard[i-3][j-3]==0&&RecordBoard[i-2][j-2]==sign&&RecordBoard[i-1][j-1]==sign&&RecordBoard[i][j]==0&&RecordBoard[i+1][j+1]==sign&&RecordBoard[i+2][j+2]==0)
	Value[i][j][8]++;
if(2<=i&&i<=11&&2<=j&&j<=11&&RecordBoard[i-2][j-2]==0&&RecordBoard[i-1][j-1]==sign&&RecordBoard[i][j]==0&&RecordBoard[i+1][j+1]==sign&&RecordBoard[i+2][j+2]==sign&&RecordBoard[i+3][j+3]==0)
	Value[i][j][8]++;
if(3<=i&&i<=12&&2<=j&&j<=11&&RecordBoard[i-3][j+3]==0&&RecordBoard[i-2][j+2]==sign&&RecordBoard[i-1][j+1]==sign&&RecordBoard[i][j]==0&&RecordBoard[i+1][j-1]==sign&&RecordBoard[i+2][j-2]==0)
	Value[i][j][8]++;
if(2<=i&&i<=11&&3<=j&&j<=12&&RecordBoard[i+3][j-3]==0&&RecordBoard[i+2][j-2]==sign&&RecordBoard[i+1][j-1]==sign&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==sign&&RecordBoard[i-2][j+2]==0)
	Value[i][j][8]++;	

}
void is9(){//己方成二
if(j+3<=14&&j-3>=0&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==sign&&RecordBoard[i][j+2]==0&&RecordBoard[i][j+3]==0&&RecordBoard[i][j-1]==0&&RecordBoard[i][j-2]==0&&RecordBoard[i][j-3]==0)
	Value[i][j][9]++;
if(j+2<=14&&j-4>=0&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==0&&RecordBoard[i][j+2]==0&&RecordBoard[i][j-4]==0&&RecordBoard[i][j-1]==sign&&RecordBoard[i][j-2]==0&&RecordBoard[i][j-3]==0)
	Value[i][j][9]++;
if(i+4<=14&&i-2>=0&&RecordBoard[i][j]==0&&RecordBoard[i+1][j]==sign&&RecordBoard[i+2][j]==0&&RecordBoard[i+3][j]==0&&RecordBoard[i+4][j]==0&&RecordBoard[i-1][j]==0&&RecordBoard[i-2][j]==0)
	Value[i][j][9]++;
if(i+3<=14&&i-3>=0&&RecordBoard[i][j]==0&&RecordBoard[i-3][j]==0&&RecordBoard[i-2][j]==0&&RecordBoard[i-1][j]==sign&&RecordBoard[i+1][j]==0&&RecordBoard[i+2][j]==0&&RecordBoard[i+3][j]==0)
	Value[i][j][9]++;
if(j+3<=14&&j-3>=0&&i+3<=14&&i-3>=0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==sign&&RecordBoard[i-2][j-2]==0&&RecordBoard[i-3][j-3]==0&&RecordBoard[i+1][j+1]==0&&RecordBoard[i+2][j+2]==0&&RecordBoard[i+3][j+3]==0)
	Value[i][j][9]++;
if(j+3<=14&&j-3>=0&&i+3<=14&&i-3>=0&&RecordBoard[i][j]==0&&RecordBoard[i+1][j+1]==sign&&RecordBoard[i-2][j-2]==0&&RecordBoard[i-3][j-3]==0&&RecordBoard[i-1][j-1]==0&&RecordBoard[i+2][j+2]==0&&RecordBoard[i+3][j+3]==0)
	Value[i][j][9]++;
if(j+3<=14&&j-3>=0&&i+3<=14&&i-3>=0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==sign&&RecordBoard[i-2][j+2]==0&&RecordBoard[i-3][j+3]==0&&RecordBoard[i+1][j-1]==0&&RecordBoard[i+2][j-2]==0&&RecordBoard[i+3][j-3]==0)
	Value[i][j][9]++;
if(j+3<=14&&j-3>=0&&i+3<=14&&i-3>=0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==0&&RecordBoard[i-2][j+2]==0&&RecordBoard[i-3][j+3]==0&&RecordBoard[i+1][j-1]==sign&&RecordBoard[i+2][j-2]==0&&RecordBoard[i+3][j-3]==0)
	Value[i][j][9]++;
}
void is10(){//再下一步就能形成跳四，给分100
//这八个对应跳四1+3版本
if(4<=i&&RecordBoard[i-1][j]==0&&RecordBoard[i-2][j]==sign&&RecordBoard[i-3][j]==sign&&RecordBoard[i-4][j]==sign&&RecordBoard[i][j]==0)
	Value[i][j][10]++;
if(i<=10&&RecordBoard[i+1][j]==0&&RecordBoard[i+2][j]==sign&&RecordBoard[i+3][j]==sign&&RecordBoard[i+4][j]==sign&&RecordBoard[i][j]==0)
	Value[i][j][10]++;
if(j<=10&&RecordBoard[i][j+1]==0&&RecordBoard[i][j+2]==sign&&RecordBoard[i][j+3]==sign&&RecordBoard[i][j+4]==sign&&RecordBoard[i][j]==0)
	Value[i][j][10]++;
if(4<=j&&RecordBoard[i][j-3]==sign&&RecordBoard[i][j-2]==sign&&RecordBoard[i][j-1]==0&&RecordBoard[i][j-4]==sign&&RecordBoard[i][j]==0)
	Value[i][j][10]++;
if(4<=i&&4<=j&&RecordBoard[i-4][j-4]==sign&&RecordBoard[i-3][j-3]==sign&&RecordBoard[i-2][j-2]==sign&&RecordBoard[i-1][j-1]==0&&RecordBoard[i][j]==0)
	Value[i][j][10]++;
if(i<=10&&4<=j&&RecordBoard[i+4][j-4]==sign&&RecordBoard[i+3][j-3]==sign&&RecordBoard[i+2][j-2]==sign&&RecordBoard[i+1][j-1]==0&&RecordBoard[i][j]==0)
	Value[i][j][10]++;
if(i<=10&&j<=10&&RecordBoard[i+4][j+4]==sign&&RecordBoard[i+3][j+3]==sign&&RecordBoard[i+2][j+2]==sign&&RecordBoard[i+1][j+1]==0&&RecordBoard[i][j]==0)
	Value[i][j][10]++;
if(4<=i&&j<=10&&RecordBoard[i-4][j+4]==sign&&RecordBoard[i-3][j+3]==sign&&RecordBoard[i-2][j+2]==sign&&RecordBoard[i-1][j+1]==0&&RecordBoard[i][j]==0)
	Value[i][j][10]++;
//这四个对应2+2版本

}
void is11(){
//这二十四个对应活跳三
//纵向
if(i>=4&&i<=13&&RecordBoard[i][j]==0&&RecordBoard[i-1][j]==0&&RecordBoard[i-2][j]==sign&&RecordBoard[i-3][j]==sign&&RecordBoard[i-4][j]==0&&RecordBoard[i+1][j]==0)
	Value[i][j][11]++;
if(i>=4&&i<=13&&RecordBoard[i][j]==0&&RecordBoard[i-1][j]==sign&&RecordBoard[i-2][j]==0&&RecordBoard[i-3][j]==sign&&RecordBoard[i+1][j]==0&&RecordBoard[i-4][j]==0)
	Value[i][j][11]++;
if(i>=3&&i<=12&&RecordBoard[i-3][j]==0&&RecordBoard[i+2][j]==0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j]==0&&RecordBoard[i-2][j]==sign&&RecordBoard[i+1][j]==sign)
	Value[i][j][11]++;
if(i<=11&&i>=2&&RecordBoard[i-2][j]==0&&RecordBoard[i+3][j]==0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j]==sign&&RecordBoard[i+1][j]==0&&RecordBoard[i+2][j]==sign)
	Value[i][j][11]++;
if(i<=10&&i>=1&&RecordBoard[i-1][j]==0&&RecordBoard[i+4][j]==0&&RecordBoard[i][j]==0&&RecordBoard[i+1][j]==0&&RecordBoard[i+2][j]==sign&&RecordBoard[i+3][j]==sign)
	Value[i][j][11]++;
if(i<=10&&i>=1&&RecordBoard[i-1][j]==0&&RecordBoard[i+4][j]==0&&RecordBoard[i][j]==0&&RecordBoard[i+1][j]==sign&&RecordBoard[i+2][j]==0&&RecordBoard[i+3][j]==sign)
	Value[i][j][11]++;
//横向
if(j>=4&&j<=13&&RecordBoard[i][j-4]==0&&RecordBoard[i][j+1]==0&&RecordBoard[i][j-3]==sign&&RecordBoard[i][j-2]==sign&&RecordBoard[i][j-1]==0&&RecordBoard[i][j]==0)
	Value[i][j][11]++;
if(j>=4&&j<=13&&RecordBoard[i][j-4]==0&&RecordBoard[i][j+1]==0&&RecordBoard[i][j-3]==sign&&RecordBoard[i][j-2]==0&&RecordBoard[i][j-1]==sign&&RecordBoard[i][j]==0)
	Value[i][j][11]++;
if(j>=3&&j<=12&&RecordBoard[i][j-3]==0&&RecordBoard[i][j+2]==0&&RecordBoard[i][j-2]==sign&&RecordBoard[i][j-1]==0&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==sign)
	Value[i][j][11]++;
if(j>=2&&j<=11&&RecordBoard[i][j-2]==0&&RecordBoard[i][j+3]==0&&RecordBoard[i][j-1]==sign&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==0&&RecordBoard[i][j+2]==sign)
	Value[i][j][11]++;
if(j<=10&&j>=1&&RecordBoard[i][j+4]==0&&RecordBoard[i][j-1]==0&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==0&&RecordBoard[i][j+2]==sign&&RecordBoard[i][j+3]==sign)
	Value[i][j][11]++;
if(j<=10&&j>=1&&RecordBoard[i][j+4]==0&&RecordBoard[i][j-1]==0&&RecordBoard[i][j]==0&&RecordBoard[i][j+1]==sign&&RecordBoard[i][j+2]==0&&RecordBoard[i][j+3]==sign)
	Value[i][j][11]++;
//左上到右下方向
if(i>=4&&j>=4&&i<=13&&j<=13&&RecordBoard[i+1][j+1]==0&&RecordBoard[i-4][j-4]==0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==0&&RecordBoard[i-2][j-2]==sign&&RecordBoard[i-3][j-3]==sign)
	Value[i][j][11]++;
if(i>=4&&j>=4&&i<=13&&j<=13&&RecordBoard[i+1][j+1]==0&&RecordBoard[i-4][j-4]==0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j-1]==sign&&RecordBoard[i-2][j-2]==0&&RecordBoard[i-3][j-3]==sign)
	Value[i][j][11]++;
if(i>=3&&j>=3&&i<=12&&j<=12&&RecordBoard[i-3][j-3]==0&&RecordBoard[i+2][j+2]==0&&RecordBoard[i][j]==0&&RecordBoard[i+1][j+1]==sign&&RecordBoard[i-1][j-1]==0&&RecordBoard[i-2][j-2]==sign)
	Value[i][j][11]++;
if(i>=2&&j>=2&&i<=11&&j<=11&&RecordBoard[i-2][j-2]==0&&RecordBoard[i+3][j+3]==0&&RecordBoard[i-1][j-1]==sign&&RecordBoard[i][j]==0&&RecordBoard[i+1][j+1]==0&&RecordBoard[i+2][j+2]==sign)
	Value[i][j][11]++;
if(i<=10&&j<=10&&i>=1&&j>=1&&RecordBoard[i-1][j-1]==0&&RecordBoard[i+4][j+4]==0&&RecordBoard[i][j]==0&&RecordBoard[i+1][j+1]==0&&RecordBoard[i+2][j+2]==sign&&RecordBoard[i+3][j+3]==sign)
	Value[i][j][11]++;
if(i<=10&&j<=10&&i>=1&&j>=1&&RecordBoard[i-1][j-1]==0&&RecordBoard[i+4][j+4]==0&&RecordBoard[i][j]==0&&RecordBoard[i+1][j+1]==sign&&RecordBoard[i+2][j+2]==0&&RecordBoard[i+3][j+3]==sign)
	Value[i][j][11]++;
//左下到右上
if(i>=4&&j<=10&&i<=13&&j>=1&&RecordBoard[i+1][j-1]==0&&RecordBoard[i-4][j+4]==0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==0&&RecordBoard[i-2][j+2]==sign&&RecordBoard[i-3][j+3]==sign)
	Value[i][j][11]++;
if(i>=4&&j<=10&&i<=13&&j>=1&&RecordBoard[i+1][j-1]==0&&RecordBoard[i-4][j+4]==0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==sign&&RecordBoard[i-2][j+2]==0&&RecordBoard[i-3][j+3]==sign)
	Value[i][j][11]++;
if(i>=3&&i<=12&&j>=2&&j<=11&&RecordBoard[i+2][j-2]==0&&RecordBoard[i-3][j+3]==sign&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==0&&RecordBoard[i-2][j+2]==sign&&RecordBoard[i+1][j-1]==sign)
	Value[i][j][11]++;
if(i>=2&&i<=11&&j>=3&&j<=12&&RecordBoard[i-2][j+2]==0&&RecordBoard[i+3][j-3]==0&&RecordBoard[i][j]==0&&RecordBoard[i-1][j+1]==sign&&RecordBoard[i+1][j-1]==0&&RecordBoard[i+2][j-2]==sign)
	Value[i][j][11]++;
if(i<=10&&j>=4&&i>=1&&j<=13&&RecordBoard[i-1][j+1]==0&&RecordBoard[i+4][j-4]==0&&RecordBoard[i][j]==0&&RecordBoard[i+1][j-1]==0&&RecordBoard[i+2][j-2]==sign&&RecordBoard[i+3][j-3]==sign)
	Value[i][j][11]++;
if(i<=10&&j>=4&&i>=1&&j<=13&&RecordBoard[i-1][j+1]==0&&RecordBoard[i+4][j-4]==0&&RecordBoard[i][j]==0&&RecordBoard[i+1][j-1]==sign&&RecordBoard[i+2][j-2]==0&&RecordBoard[i+3][j-3]==sign)
	Value[i][j][11]++;
}
	void decide_1(){//电脑决定落子的函数
	for(i=0;i<BOARD_LEN;i++){
		for(j=0;j<BOARD_LEN;j++){   
    		valueofpoint[i][j]=0;
		}
	}
	
	for(i=0;i<BOARD_LEN;i++){
		for(j=0;j<BOARD_LEN;j++){   
    		for(k=0;k<TEST;k++)
				Value[i][j][k]=0;
		}
	}
	for(i=0;i<BOARD_LEN;i++){
		for(j=0;j<BOARD_LEN;j++){ 
			if(RecordBoard[i][j]==0){
				is0();
				is1();
				is2();
				is3();
				is4();
				is5();
				is6();
				is7();
				is8();
				is9();
				is10();
				is11();
				valueofpoint[i][j]=10*Value[i][j][0]+10*Value[i][j][1]+20*Value[i][j][2]+200*Value[i][j][3]+2000*Value[i][j][4]+50*Value[i][j][5]+301*Value[i][j][6]+10000*Value[i][j][7]+450*Value[i][j][8]+5*Value[i][j][9]+300*Value[i][j][10]+35*Value[i][j][11];
				if(Value[i][j][5]!=0&&Value[i][j][6]!=0||Value[i][j][5]!=0&&Value[i][j][10]!=0||Value[i][j][6]!=0&&Value[i][j][11]!=0||Value[i][j][10]!=0&&Value[i][j][11]!=0)
					valueofpoint[i][j]+=500;
				}
				else
				    valueofpoint[i][j]-=1000;
				//valueofpoint[i][j]==-1000;
				
		}
	}
	int maxvalue=-1;
	for(i=0;i<=14;i++){//遍历棋盘，寻找最大分数
		for(j=0;j<=14;j++){
			if(valueofpoint[i][j]>maxvalue){
				maxvalue=valueofpoint[i][j];
			}
		}
	}
	
	struct maxpoint{//记录价值最大的点的坐标的结构
		int c;
		int d;
	}p1,p2,p3,p4,p5,p6,p7,p8;
	p1.c=0;p1.d=0;//初始化这些点的坐标
	p2.c=0;p2.d=0;
	p3.c=0;p3.d=0;
	p4.c=0;p4.d=0;
	p5.c=0;p5.d=0;
	p6.c=0;p6.d=0;
	p7.c=0;p7.d=0;
	p8.c=0;p8.d=0;

	
		for(i=0;i<=14;i++){
			for(j=0;j<=14;j++){//把最大值点存入结构中，最多存放8个。最大值点一般也不太多，超过八个情况较少。
				if(valueofpoint[i][j]==maxvalue&&maxpt==0){
					p1.c=i;
					p1.d=j;
				}
				if(valueofpoint[i][j]==maxvalue&&maxpt==1){
					p2.c=i;
					p2.d=j;
				}
				if(valueofpoint[i][j]==maxvalue&&maxpt==2){
					p3.c=i;
					p3.d=j;
				}
				if(valueofpoint[i][j]==maxvalue&&maxpt==3){
					p4.c=i;
					p4.d=j;
				}
				if(valueofpoint[i][j]==maxvalue&&maxpt==4){
					p5.c=i;
					p5.d=j;
				}
				if(valueofpoint[i][j]==maxvalue&&maxpt==5){
					p6.c=i;
					p6.d=j;
				}
				if(valueofpoint[i][j]==maxvalue&&maxpt==6){
					p7.c=i;
					p7.d=j;
				}
				if(valueofpoint[i][j]==maxvalue&&maxpt==7){
					p8.c=i;
					p8.d=j;
				}
				if(valueofpoint[i][j]==maxvalue){
					maxpt++;
				}
			}
		}
		switch(maxpt){//根据最大值点个数的不同，随机选取其中某点落子。这主要是为了增强对战时的不确定度，让游戏更有趣
		case 1://只有一个最大值，直接赋值
			x=p1.c;
			y=p1.d;
			break;
		case 2:
			srand((unsigned)time(NULL));//初始化随机数
			switch(rand()%2){//生成随机数
			case 0:
				x=p1.c;
				y=p1.d;
				break;
			case 1:
				x=p2.c;
				y=p2.d;
				break;
				}
			break;
		case 3:
			srand((unsigned)time(NULL));//初始化随机数
			switch(rand()%3){//生成随机数
			case 0:
				x=p1.c;
				y=p1.d;
				break;
			case 1:
				x=p2.c;
				y=p2.d;
				break;
			case 2:
				x=p3.c;
				y=p3.d;
				break;
				}
			break;
		case 4:
			srand((unsigned)time(NULL));//初始化随机数
			switch(rand()%4){//生成随机数
			case 0:
				x=p1.c;
				y=p1.d;
				break;
			case 1:
				x=p2.c;
				y=p2.d;
				break;
			case 2:
				x=p3.c;
				y=p3.d;
				break;
			case 3:
				x=p4.c;
				y=p4.d;
				break;
				}
			break;
		case 5:
			srand((unsigned)time(NULL));//初始化随机数
			switch(rand()%5){//生成随机数
			case 0:
				x=p1.c;
				y=p1.d;
				break;
			case 1:
				x=p2.c;
				y=p2.d;
				break;
			case 2:
				x=p3.c;
				y=p3.d;
				break;
			case 3:
				x=p4.c;
				y=p4.d;
				break;
			case 4:
				x=p5.c;
				y=p5.d;
				break;
				}
			break;
		case 6:
			srand((unsigned)time(NULL));//初始化随机数
			switch(rand()%6){//生成随机数
			case 0:
				x=p1.c;
				y=p1.d;
				break;
			case 1:
				x=p2.c;
				y=p2.d;
				break;
			case 2:
				x=p3.c;
				y=p3.d;
				break;
			case 3:
				x=p4.c;
				y=p4.d;
				break;
			case 4:
				x=p5.c;
				y=p5.d;
				break;
			case 5:
				x=p6.c;
				y=p6.d;
				break;
				}
			break;
		case 7:
			srand((unsigned)time(NULL));//初始化随机数
			switch(rand()%7){//生成随机数
			case 0:
				x=p1.c;
				y=p1.d;
				break;
			case 1:
				x=p2.c;
				y=p2.d;
				break;
			case 2:
				x=p3.c;
				y=p3.d;
				break;
			case 3:
				x=p4.c;
				y=p4.d;
				break;
			case 4:
				x=p5.c;
				y=p5.d;
				break;
			case 5:
				x=p6.c;
				y=p6.d;
				break;
			case 6:
				x=p7.c;
				y=p7.d;
				break;
				}
			break;
		case 8:
			srand((unsigned)time(NULL));//初始化随机数
			switch(rand()%8){//生成随机数
			case 0:
				x=p1.c;
				y=p1.d;
				break;
			case 1:
				x=p2.c;
				y=p2.d;
				break;
			case 2:
				x=p3.c;
				y=p3.d;
				break;
			case 3:
				x=p4.c;
				y=p4.d;
				break;
			case 4:
				x=p5.c;
				y=p5.d;
				break;
			case 5:
				x=p6.c;
				y=p6.d;
				break;
			case 6:
				x=p7.c;
				y=p7.d;
				break;
			case 7:
				x=p8.c;
				y=p8.d;
				break;
				}
		break;
		}
		maxpt=0;//maxpt是全局变量，用完之后要初始化成零以方便下一次使用。
		}
