#include "comm.h"

void read_in(){
FILE *fp;
int ret;
int i,j,player;
char dim2;
fp = fopen("state2.txt","r+");
player = 1;
while(fscanf(fp,"%d %c", &i, &dim2) != EOF){
    i = 15 - i;
    j = dim2 - 'A';
    RecordBoard[i][j] = player;
    player = 3 - player;
    record_to_display();
	display_display_board();
	//sleep(0.1);
}
    sign = player;
    printf("player%d i%d j%d\n",player,i,j);
    x = i;
    y = j;
    fclose(fp);
}
    
