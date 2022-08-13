#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*prototype declare*/
struct traindata {
	int stop,price[10][10],col,row;
	char site[10];
};
struct peopledata {
	int price,buy,from,to,far,dir,seat[2],car;
	char name[30];
};
struct seatdata {
	int price,from,to,buy;
};

/*variable declare*/
struct traindata tr;
struct peopledata pdat[10002];
struct seatdata sdat[10][2][100][100][9],fakesdat[10][2][100][100][9];
int pnum=0,trnum=0,ticket,maxtotal[3],tempmax=0,row,col,mcar;
char want;

/*function*/
int sitenum(char);
int detect(char,int,int,int);
int spdetect(char,int,int,int);
void core(int,int,int);
void core2(int,int,int,int,int);
int total();
int overlap(int,int,int,int,int,int);
void getseat(int,int,int,int,int,int);
void test();
int main(){
	int i=0,j=0,k=0;
	char ctemp,ctemp1,ctemp2;
	memset(pdat[10001].name,'\0',30);
	pdat[10001].from=0;
	pdat[10001].to=0;
	/*step 1 : scan train data*/
	scanf("%d\n%c",&tr.stop,&ctemp);
	for(i=0;i<tr.stop;i++)scanf("%s",&tr.site[i]);
	for(i=0;i<tr.stop;i++){
		scanf("%s",&ctemp);
		for(j=0;j<tr.stop;j++)scanf("%d",&tr.price[i][j]);
	}
	scanf("%d\n%d %d\n%d\n",&trnum,&tr.col,&tr.row,&pnum);
	/*step 1-2 : scan preson data*/
	for(i=0;i<pnum;i++){
		scanf("%s %c %c %c%d\n",pdat[i].name,&ctemp1,&ctemp2,&want,&ticket);
		for(j=0;j<ticket;j++){
			strcpy(pdat[i+j].name,pdat[i].name);
			pdat[i+j].from=sitenum(ctemp1);
			pdat[i+j].to=sitenum(ctemp2);
			pdat[i+j].far=pdat[i+j].to-pdat[i+j].from;
			pdat[i+j].price=tr.price[pdat[i+j].from][pdat[i+j].to];
			if(pdat[i+j].far<0){
				pdat[i+j].far=(pdat[i+j].far)*(-1);
				pdat[i+j].dir=1;
			}
		}
		/*step 2 : decide >> (1) canseat (2) seat*/
		if(want=='*'){
			if(spdetect(want,i,ticket,pdat[i].dir)==1)for(j=0;j<ticket;j++)core2(mcar,col,row+j,i+j,pdat[i].dir);
		}
		else{
			if(detect(want,i,ticket,pdat[i].dir)==ticket)core(i,ticket,pdat[i].dir);
		}
		/*step 3 : ouput*/
		for(j=0;j<ticket;j++){
			if(pdat[i].buy==1)printf("%s %d %d-%d %d\n",pdat[i+j].name,pdat[i+j].car,pdat[i+j].seat[0],pdat[i+j].seat[1],pdat[i+j].price);
			else{
				printf("We don't want to sell you.\n");
				break;
			}
		}
		i=i+ticket-1;
		pnum=pnum+ticket-1;
	}
	printf("Total Money: %d\n",total());
	return 0;
}
int sitenum(char station){
	int i;
	for(i=0;i<tr.stop;i++)if(tr.site[i]==station)break;
	return i;
}
int detect(char want,int peo,int ticket,int dir){
	int i,j,k,l,m,p,car,time=0,fakeoverlap=0;
	for(i=0;i<10;i++)
		for(j=0;j<2;j++)
			for(k=0;k<100;k++)
				for(l=0;l<100;l++)
					for(m=0;m<9;m++)fakesdat[i][j][k][l][m]=sdat[i][j][k][l][m];
	for(j=0;j<tr.row;j++)
		for(car=0;car<trnum;car++)
			for(i=0;i<tr.col;i++)

				for(p=peo;p<peo+ticket;p++){/*people*/
					if(fakesdat[car][dir][i][j][0].buy==0&&pdat[p].buy==0){
						fakesdat[car][dir][i][j][0].price=pdat[p].price;
						fakesdat[car][dir][i][j][0].from=pdat[p].from;
						fakesdat[car][dir][i][j][0].to=pdat[p].to;
						fakesdat[car][dir][i][j][0].buy=1;
						time++;/*blankseat*/
						pdat[p].buy=1;
					}
					else if(pdat[p].buy==0){
						for(k=0;k<9;k++){/*seat*/
							/*check seat,if wrong:*/
							if(dir==0&&fakesdat[car][dir][i][j][k].to<=pdat[p].from)fakeoverlap=0;
							else if(dir==0&&fakesdat[car][dir][i][j][k].from>=pdat[p].to)fakeoverlap=0;
							else if(dir==1&&fakesdat[car][dir][i][j][k].from<=pdat[p].to)fakeoverlap=0;
							else if(dir==1&&fakesdat[car][dir][i][j][k].to>=pdat[p].from)fakeoverlap=0;
							else fakeoverlap=1;

							if(fakesdat[car][dir][i][j][k].buy==1&&fakeoverlap==1)break;
							else if(fakesdat[car][dir][i][j][k].buy==0){/*if all pass:*/
								fakesdat[car][dir][i][j][k].price=pdat[p].price;
								fakesdat[car][dir][i][j][k].from=pdat[p].from;
								fakesdat[car][dir][i][j][k].to=pdat[p].to;
								fakesdat[car][dir][i][j][k].buy=1;
								time++;
								pdat[p].buy=1;
								break;
							}
						}
					}
				}
	for(p=peo;p<peo+ticket;p++)pdat[p].buy=0;
	for(i=0;i<10;i++)
		for(j=0;j<2;j++)
			for(k=0;k<100;k++)
				for(l=0;l<100;l++)
					for(m=0;m<9;m++){
						fakesdat[i][j][k][l][m].price=0;
						fakesdat[i][j][k][l][m].from=0;
						fakesdat[i][j][k][l][m].to=0;
						fakesdat[i][j][k][l][m].buy=0;
					}
	return time;
}
int spdetect(char want,int peo,int ticket,int dir){
	int i,j,k,l,m,car,p,check=0,fakeoverlap=0,time=0;
	for(i=0;i<10;i++)
		for(j=0;j<2;j++)
			for(k=0;k<100;k++)
				for(l=0;l<100;l++)
					for(m=0;m<9;m++)fakesdat[i][j][k][l][m]=sdat[i][j][k][l][m];
	for(car=0;car<trnum&&check==0;car++)
		for(i=0;i<tr.col&&check==0;i++)
			for(j=0;j<tr.row-ticket+1&&check==0;j++){
				time=0;
				for(l=0;l<ticket&&check==0;l++)
					for(p=peo;p<peo+ticket&&check==0;p++){/*people*/
						if(fakesdat[car][dir][i][j+l][0].buy==0&&pdat[p].buy==0){
							fakesdat[car][dir][i][j+l][0].price=pdat[p].price;
							fakesdat[car][dir][i][j+l][0].from=pdat[p].from;
							fakesdat[car][dir][i][j+l][0].to=pdat[p].to;
							fakesdat[car][dir][i][j+l][0].buy=1;
							/*blankseat*/
							pdat[p].buy=1;
							time++;
							if(time==ticket)check=1;
						}
						else if(pdat[p].buy==0){
							for(k=0;k<9&&check==0;k++){/*seat*/
								/*check seat,if wrong:*/
								if(dir==0&&fakesdat[car][dir][i][j+l][k].to<=pdat[p].from)fakeoverlap=0;
								else if(dir==0&&fakesdat[car][dir][i][j+l][k].from>=pdat[p].to)fakeoverlap=0;
								else if(dir==1&&fakesdat[car][dir][i][j+l][k].from<=pdat[p].to)fakeoverlap=0;
								else if(dir==1&&fakesdat[car][dir][i][j+l][k].to>=pdat[p].from)fakeoverlap=0;
								else fakeoverlap=1;

								if(fakesdat[car][dir][i][j+l][k].buy==1&&fakeoverlap==1)break;
								else if(fakesdat[car][dir][i][j+l][k].buy==0){/*if all pass:*/
									fakesdat[car][dir][i][j+l][k].price=pdat[p].price;
									fakesdat[car][dir][i][j+l][k].from=pdat[p].from;
									fakesdat[car][dir][i][j+l][k].to=pdat[p].to;
									fakesdat[car][dir][i][j+l][k].buy=1;
									pdat[p].buy=1;
									time++;
									if(time==ticket)check=1;
									break;
								}
							}
						}
					}
				for(p=peo;p<peo+ticket;p++)pdat[p].buy=0;
				if(check==1){
					mcar=car;
					col=i;
					row=j;
				}
			}
	for(p=peo;p<peo+ticket;p++)pdat[p].buy=0;
	for(i=0;i<10;i++)
		for(j=0;j<2;j++)
			for(k=0;k<100;k++)
				for(l=0;l<100;l++)
					for(m=0;m<9;m++){
						fakesdat[i][j][k][l][m].price=0;
						fakesdat[i][j][k][l][m].from=0;
						fakesdat[i][j][k][l][m].to=0;
						fakesdat[i][j][k][l][m].buy=0;
					}
	return check;
}
void core(int peo,int ticket,int dir){
	int i,j,k,p,car,time=0;
	for(j=0;j<tr.row;j++)
		for(car=0;car<trnum;car++)
			for(i=0;i<tr.col;i++)

				for(p=peo;p<peo+ticket;p++){/*people*/
					if(sdat[car][dir][i][j][0].buy==0&&pdat[p].buy==0){
						getseat(car,i,j,dir,0,p);/*blankseat*/
					}
					else if(pdat[p].buy==0){
						for(k=0;k<9;k++){/*seat*/
							/*check seat,if wrong:*/
							if(sdat[car][dir][i][j][k].buy==1&&overlap(car,dir,i,j,k,p)==1)break;
							else if(sdat[car][dir][i][j][k].buy==0){/*if all pass:*/
								getseat(car,i,j,dir,k,p);
								break;
							}
						}
					}
				}
}
void core2(int mcar,int col,int row,int p,int dir){
	int i,j,k,car,time=0;
	if(sdat[mcar][dir][col][row][0].buy==0&&pdat[p].buy==0){
		getseat(mcar,col,row,dir,0,p);/*blankseat*/
	}
	else if(pdat[p].buy==0){
		for(k=0;k<9;k++){/*seat*/
			/*check seat,if wrong:*/
			if(sdat[mcar][dir][col][row][k].buy==1&&overlap(mcar,dir,col,row,k,p)==1)break;
			else if(sdat[mcar][dir][col][row][k].buy==0){/*if all pass:*/
				getseat(mcar,col,row,dir,k,p);
				break;
			}
		}
	}
}
int total(){
	int i,sum=0;
	for(i=0;i<pnum;i++)if(pdat[i].buy==1)sum=sum+pdat[i].price;
	return sum;
}
int overlap(int car,int d,int i,int j,int k,int p){
	if(d==0&&sdat[car][d][i][j][k].to<=pdat[p].from)return 0;
	else if(d==0&&sdat[car][d][i][j][k].from>=pdat[p].to)return 0;
	else if(d==1&&sdat[car][d][i][j][k].from<=pdat[p].to)return 0;
	else if(d==1&&sdat[car][d][i][j][k].to>=pdat[p].from)return 0;
	else return 1;
}
void getseat(int car,int i,int j,int dir,int k,int p){
	/*input preson data*/
	pdat[p].car=car+1;
	pdat[p].buy=1;
	pdat[p].seat[0]=i+1;
	pdat[p].seat[1]=j+1;
	/*input seat data*/
	sdat[car][dir][i][j][k].price=pdat[p].price;
	sdat[car][dir][i][j][k].from=pdat[p].from;
	sdat[car][dir][i][j][k].to=pdat[p].to;
	sdat[car][dir][i][j][k].buy=1;
}
void test(){
	int i,j,k;
	for(i=0;i<3;i++)printf("maxtotal[%d]=%d\n",i,maxtotal[i]);
	printf("person number = %d\n",pnum);
	/*traindata*/
	printf("traindata:\nstop = %d ,col = %d ,row = %d\n-",tr.stop,tr.col,tr.row);
	for(i=0;i<tr.stop;i++)printf(" %c",tr.site[i]);
	printf("\n");
	for(i=0;i<tr.stop;i++){
		printf("%c",tr.site[i]);
		for(j=0;j<tr.stop;j++)printf(" %d",tr.price[i][j]);
		printf("\n");
	}
	/*peopledata[10002]*/
	for(i=0;i<pnum;i++)
		printf("peopledata[%d]:\nname = %s ,price = %d ,buy = %d ,from = %d,to = %d ,far = %d ,seat = %d %d\n",i,pdat[i].name,pdat[i].price,pdat[i].buy,pdat[i].from,pdat[i].to,pdat[i].far,pdat[i].seat[0],pdat[i].seat[1]);
}
