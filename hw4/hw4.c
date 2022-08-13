#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*prototype declare*/
struct traindata {
	int stop,price[10][10],col,row;
	char site[10];
};
struct peopledata {
	int price,buy,from,to,far,dir,seat[2];
	char name[30];
};
struct seatdata {
	int price,from,to,buy;
};

/*variable declare*/
struct traindata tr;
struct peopledata pdat[10002];
struct seatdata sdat[2][100][100][9];
int pnum=0,maxtotal[3],tempmax=0;

/*function*/
void long_price_sort();
void long_near_sort();
void short_near_sort();
void namesort();
void exchange(int);
int sitenum(char);
void greedycore();
int total();
void clean();
void decideseat(int,int);
int overlap(int,int,int,int,int);
void getseat(int,int,int,int,int);
void test();
int main(){
	int i=0,j=0,k=0;
	char ctemp,ctemp1,ctemp2;
	memset(pdat[10001].name,'\0',30);
	pdat[10001].from=0;
	pdat[10001].to=0;
	/*step 1 : scan*/
	scanf("%d\n%c",&tr.stop,&ctemp);
	for(i=0;i<tr.stop;i++)scanf("%s",&tr.site[i]);
	for(i=0;i<tr.stop;i++){
		scanf("%s",&ctemp);
		for(j=0;j<tr.stop;j++)scanf("%d",&tr.price[i][j]);
	}
	scanf("%d %d\n%d\n",&tr.col,&tr.row,&pnum);
	for(i=0;i<pnum;i++){
		scanf("%s %c %c\n",pdat[i].name,&ctemp1,&ctemp2);
		pdat[i].from=sitenum(ctemp1);
		pdat[i].to=sitenum(ctemp2);
		pdat[i].far=pdat[i].to-pdat[i].from;
		pdat[i].price=tr.price[pdat[i].from][pdat[i].to];
		if(pdat[i].far<0){
			pdat[i].far=(pdat[i].far)*(-1);
			pdat[i].dir=1;
		}
	}
	/*step 2 : decide*/
	long_price_sort();/*case 1*/
	greedycore();
	maxtotal[0]=total();
	clean();
	long_near_sort();/*case 2*/
	greedycore();
	maxtotal[1]=total();
	clean();
	short_near_sort();/*case 3*/
	greedycore();
	maxtotal[2]=total();
	clean();
	for(i=1;i<3;i++)if(maxtotal[i]>maxtotal[tempmax])tempmax=i;/*decide who is the best*/
	if(tempmax==0){
		long_price_sort();
		greedycore();
	}
	else if(tempmax==1){
		long_near_sort();
		greedycore();
	}
	else{
		short_near_sort();
		greedycore();
	}
	/*step 3 : output*/
	namesort();
	for(i=0;i<pnum;i++){
		if(pdat[i].buy==1)printf("%s %c %c %d %d %d\n",pdat[i].name,tr.site[pdat[i].from],tr.site[pdat[i].to],pdat[i].seat[0],pdat[i].seat[1],pdat[i].price);
		else printf("%s - - - - -\n",pdat[i].name);
	}
	return 0;
}
int sitenum(char station){
	int i;
	for(i=0;i<tr.stop;i++)if(tr.site[i]==station)break;
	return i;
}
void long_price_sort(){/* -> top; <- buttom */
	int i,j,pt=1;
	for(i=0;i<pnum-1;i++)
		for(j=0;j<pnum-1;j++){
			if(pdat[j].dir>pdat[j+1].dir)exchange(j);
			else if((pdat[j].dir==pdat[j+1].dir)&&(pdat[j].far<pdat[j+1].far))exchange(j);
			else if((pdat[j].dir==pdat[j+1].dir)&&(pdat[j].far==pdat[j+1].far)&&(pdat[j].price<pdat[j+1].price))exchange(j);
		}
}
void long_near_sort(){
	int i,j,pt=1;
	for(i=0;i<pnum-1;i++)
		for(j=0;j<pnum-1;j++){
			if(pdat[j].dir>pdat[j+1].dir)exchange(j);
			else if((pdat[j].dir==pdat[j+1].dir)&&(pdat[j].far<pdat[j+1].far))exchange(j);
			else if((pdat[j].dir==pdat[j+1].dir)&&(pdat[j].far==pdat[j+1].far)&&(pdat[j].from>pdat[j+1].from))exchange(j);
		}
}
void short_near_sort(){
	int i,j,pt=1;
	for(i=0;i<pnum-1;i++)
		for(j=0;j<pnum-1;j++){
			if(pdat[j].dir>pdat[j+1].dir)exchange(j);
			else if((pdat[j].dir==pdat[j+1].dir)&&(pdat[j].far>pdat[j+1].far))exchange(j);
			else if((pdat[j].dir==pdat[j+1].dir)&&(pdat[j].far==pdat[j+1].far)&&(pdat[j].from>pdat[j+1].from))exchange(j);
		}
}
void namesort(){
	int i,j,k,brk;
	for(i=0;i<pnum-1;i++)
		for(j=0;j<pnum-i-1;j++){
			brk=0;
			for(k=0;k<30&&brk==0;k++){
				if(pdat[j].name[k]>pdat[j+1].name[k]){
					exchange(j);
					brk=1;
				}
				else if(pdat[j].name[k]<pdat[j+1].name[k])brk=1;
			}
		}
}
void exchange(int j){
	pdat[10000]=pdat[10001];
	pdat[10000]=pdat[j+1];
	pdat[j+1]=pdat[10001];
	pdat[j+1]=pdat[j];
	pdat[j]=pdat[10001];
	pdat[j]=pdat[10000];	
}
void greedycore(){
	int i,j,k,p,p1,d;
	for(d=0;d<2;d++)
		for(i=0;i<tr.col;i++)
			for(j=0;j<tr.row;j++){
				if(d==0){
					for(p=0;p<pnum&&pdat[p].dir==0;p++){/*people*/
						if(sdat[d][i][j][0].buy==0&&pdat[p].buy==0){
							getseat(i,j,d,0,p);/*blankseat*/
							continue;
						}
						else if(pdat[p].buy==0){
							for(k=0;k<9;k++){/*seat*/
								/*check seat,if wrong:*/
								if(sdat[d][i][j][k].buy==1&&overlap(d,i,j,k,p)==1)break;
								else if(sdat[d][i][j][k].buy==0){/*if all pass:*/
									getseat(i,j,d,k,p);
									break;
								}						
							}
						}
					}
				}
				else{
					for(p1=p;p1<pnum;p1++){/*people*/
						if(sdat[d][i][j][0].buy==0&&pdat[p1].buy==0){/*blank seat*/
							getseat(i,j,d,0,p1);
							continue;
						}
						else if(pdat[p1].buy==0){	
							for(k=0;k<9;k++){/*seat*/
								/*check seat,if wrong:*/
								if(sdat[d][i][j][k].buy==1&&overlap(d,i,j,k,p1)==1)break;
								else if(sdat[d][i][j][k].buy==0){/*if all pass:*/
									getseat(i,j,d,k,p1);
									break;
								}
							}
						}
					}
				}
			}
}
int total(){
	int i,sum=0;
	for(i=0;i<pnum;i++)if(pdat[i].buy==1)sum=sum+pdat[i].price;
	return sum;
}
void clean(){
	int i,j,k,l;
	for(i=0;i<2;i++)
		for(j=0;j<tr.col;j++)
			for(k=0;k<tr.row;k++)
				for(l=0;l<9;l++){
					sdat[i][j][k][l].price=0;
					sdat[i][j][k][l].from=0;
					sdat[i][j][k][l].to=0;
					sdat[i][j][k][l].buy=0;
				}
	for(i=0;i<pnum;i++){
		pdat[i].buy=0;
		pdat[i].seat[0]=0;
		pdat[i].seat[1]=0;
	}
}
void decideseat(int p,int dir){
	int i,j,k,brk=0;
	/*normal seat:seat until full -> greedy long*/
	//	for(i=1;i<=tr.col&&brk==0;i++)
	//		for(j=1;j<=tr.row&&brk==0;j++){
	//			for(k=0;k<9&&brk==0;k++){
	//				if(sdat[dir][i][j][k].buy==0){/*seat blank,range,price*/
	//					getseat(i,j,dir,k,p);
	//					brk=1;
	//				}
	//				else if(sdat[dir][i][j][k].buy==1){
	//
	//				}
	//			}
	//		}
	/*advance seat:full condition & kick seat -> greedy cp*/
	//	if(pdat[]==0){
	//
	//	}
}
int overlap(int d,int i,int j,int k,int p){
	if(d==0&&sdat[d][i][j][k].to<=pdat[p].from)return 0;
	else if(d==0&&sdat[d][i][j][k].from>=pdat[p].to)return 0;
	else if(d==1&&sdat[d][i][j][k].from<=pdat[p].to)return 0;
	else if(d==1&&sdat[d][i][j][k].to>=pdat[p].from)return 0;
	else return 1;
}
void getseat(int i,int j,int dir,int k,int p){
	/*input preson data*/
	pdat[p].buy=1;
	pdat[p].seat[0]=i+1;
	pdat[p].seat[1]=j+1;
	/*	if(sdat[dir][i][j][k].buy=1){

		}
	 */
	/*input seat data*/
	sdat[dir][i][j][k].price=pdat[p].price;
	sdat[dir][i][j][k].from=pdat[p].from;
	sdat[dir][i][j][k].to=pdat[p].to;
	sdat[dir][i][j][k].buy=1;
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
/*
   1.scan all data
   2.decide
   (1)bbsort
   (2)seat
   normal seat : seat blank->just seat
   advance seat : not blank->decide range(2 dir divide)->base on price to decide
   3.output

   2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 -> node = 17 = 8+9
   ^ ^ ^ ^ ^ ^ ^ ^ ^
   ab,ac,ad,bc,bd,cd
   ad,ac,ab,bd,bc,cd
   odd,even
   long_price
   long_near
   short_price
*/
