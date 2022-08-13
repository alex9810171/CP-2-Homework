/*
#Author:Sheng-Huai,Hsu 105703047
#Date:Mar.23.2017
#Purpose: NCCUCS 1052 CP2 Assign 2 - Tower of Hanoi
*/
#include <curses.h>
int dcnum,i,j,k,det=0,det1=0,plr[3][20],time;
char stop[1000],disc[1000],temp[1000];
void hanoi(int n,char A,char B,char C){
	if(n==1){
		clear();
		//		mvprintw(3,0,"n=%d A=%c B=%c C=%c\n",n,A,B,C);
		for(i=0;i<126;i++){
			mvprintw(0,i,"=");
			mvprintw(35,i,"=");
		}
		mvprintw(1,0,"Step%d: Move the %dst disc from %c to %c",++time,n,A,C);
		for(i=19;i>=0&&plr[A-65][i-1]!=0;i--);
		for(j=19;j>=0;j--)
			if(plr[C-65][j]==0){
				plr[C-65][j]=plr[A-65][i];
				j=-1;
			}
		plr[A-65][i]=0;/*move matrix*/
		for(j=7;j<12;j++){
			mvprintw(j,20,"|");
			mvprintw(j,62,"|");
			mvprintw(j,104,"|");
		}/*pillar*/
		for(i=0;i<126;i++)if(i!=41&&i!=83&&i!=125){
			mvprintw(32,i,"T");
			mvprintw(33,i,"T");
		}/*table*/
		for(j=12;j<32;j++)
			for(i=20;i<=104;i+=42){
				if(plr[(i-20)/42][j-12]==0)mvprintw(j,i,"|");
				else{
					mvprintw(j,i,"%d",plr[(i-20)/42][j-12]);
					for(k=1;k<=plr[(i-20)/42][j-12];k++){
						mvprintw(j,i+k,"-");
						mvprintw(j,i-k,"-");
					}
				}
			}/*circle*/
		mvprintw(2,0,"Press any key to continue.");
		scanw("%s",temp);
		for(i=0;i<1000;i++)temp[i]='\0';
	}
	else{
		hanoi(n-1,A,C,B);
		clear();
		for(i=0;i<126;i++){
			mvprintw(0,i,"=");
			mvprintw(35,i,"=");

		}
		mvprintw(1,0,"Step%d: Move the %dst disc from %c to %c",++time,n,A,C);
		for(i=19;i>=0&&plr[A-65][i-1]!=0;i--);
		for(j=19;j>=0;j--)
			if(plr[C-65][j]==0){
				plr[C-65][j]=plr[A-65][i];
				j=-1;
			}
		plr[A-65][i]=0;
		for(j=7;j<12;j++){
			mvprintw(j,20,"|");
			mvprintw(j,62,"|");
			mvprintw(j,104,"|");
		}/*pillar*/
		for(i=0;i<126;i++)if(i!=41&&i!=83&&i!=125){
			mvprintw(32,i,"T");
			mvprintw(33,i,"T");
		}/*table*/
		for(j=12;j<32;j++)
			for(i=20;i<=104;i+=42){
				if(plr[(i-20)/42][j-12]==0)mvprintw(j,i,"|");
				else{
					mvprintw(j,i,"%d",plr[(i-20)/42][j-12]);
					for(k=1;k<=plr[(i-20)/42][j-12];k++){
						mvprintw(j,i+k,"-");
						mvprintw(j,i-k,"-");
					}
				}
			}/*circle*/
		mvprintw(2,0,"Press any key to continue.");
		scanw("%s",temp);
		hanoi(n-1,B,A,C);
	}
}
int main(){
	stop[0]='y';
	initscr();
	while(stop[0]=='y'){
		time=0;
		det1=0;
		clear();
		printw("How many discs do you want to move?(1-6)\n");
		for(i=0;i<1000;i++)disc[i]='\0';
		scanw("%s",disc);/*scan input*/
		if(disc[0]<49||disc[0]>54||disc[1]!='\0')det=-1;
		else {
			dcnum=disc[0]-48;/*input dcnum*/
			for(i=0;i<3;i++)for(j=0;j<20;j++)plr[i][j]=0;/*clean pillar*/
			for(i=0;i<20&&(dcnum-i)>0;i++)plr[0][19-i]=dcnum-i;/*input pillar*/
			for(j=7;j<12;j++){
				mvprintw(j,20,"|");
				mvprintw(j,62,"|");
				mvprintw(j,104,"|");
			}/*pillar*/
			for(i=0;i<126;i++)if(i!=41&&i!=83&&i!=125){
				mvprintw(32,i,"T");
				mvprintw(33,i,"T");
			}/*table*/
			for(j=12;j<32;j++)
				for(i=20;i<=104;i+=42){
					if(plr[(i-20)/42][j-12]==0)mvprintw(j,i,"|");
					else{
						mvprintw(j,i,"%d",plr[(i-20)/42][j-12]);
						for(k=1;k<=plr[(i-20)/42][j-12];k++){
							mvprintw(j,i+k,"-");
							mvprintw(j,i-k,"-");
						}
					}
				}/*circle*/
			mvprintw(2,0,"Press any key to continue.");
			scanw("%s",temp);
			hanoi(dcnum,'A','B','C');/*recursive*/
			clear();
		}/*hanoi*/
		if(det==-1){
			printw("Because system detected a wrong input,it will stop.\n");
			det=0;
		}
		while(det1==0){
			printw("Again?(press enter or y/n):");
			scanw("%s",stop);
			det1=1;
			clear();
			if((stop[0]!='y'&&stop[0]!='n')||(stop[1]!='\0')){
				printw("Please enter 'y' or 'n'.\n");
				det1=0;
				for(i=0;i<1000;i++)stop[i]='\0';
			}
		}/*again or not*/
	}
	endwin();
	return 0;
}
//function will add: 1.break option while painting 2.advance mode(1-20)
// bug : enter will again.
/*
   for(i=0;i<3;i++){
   printw("plr[%d]= ",i);
   for(j=0;j<20;j++)printw("%d|",plr[i][j]);
   printw("\n");
   }
 */
