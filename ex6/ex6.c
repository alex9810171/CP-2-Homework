/*
#Author:Sheng-Huai,Hsu 105703047
#Date:Mar.30,2017
#Purpose: NCCUCS 1052 CP2 Exercise 6 - Sum of Hamming Distance
*/
#include<stdio.h>
int main(){
	int total,num,ham[10000][30],list[30],temp,time,i,j,k,x,y;
	while(scanf("%d",&total)!=EOF){
		for(i=0;i<total;i++){
			scanf("%d",&num);
			for(j=0;j<30&&num!=0;j++){
				ham[i][j]=num%2;
				num=num/2;
			}
			for(k=j;k<30;k++)ham[i][k]=0;
		}/*convert 10 to 2*/
		time=0;
		for(j=0;j<30;j++){
			x=0;
			y=0;
			for(i=0;i<total;i++){
				if(ham[i][j]==0)x++;
				else y++;
			}
			time=time+x*y;
		}
		printf("%d\n",time);
	}
	return 0; 
}
