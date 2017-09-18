#include "comm.h"

void read_in(){
FILE *fp;
int i;
char dim2;
fp = fopen("state2.txt","r+");
sign = 1;
while(fscanf(fp,"%d %c", &i, &dim2) != EOF){
    if( i == 16)
        break;
    x = 15 - i;
    y = dim2 - 'A';
    RecordBoard[x][y] = sign;
    sign = 3 - sign;
    record_to_display();
    fdisplay();
	//display_display_board();
}
    //printf("player%d i%d j%d\n",player,i,j);
    //x = i;
    //y = j;
    record_to_display();
	display_display_board();
    fclose(fp);
}
    
