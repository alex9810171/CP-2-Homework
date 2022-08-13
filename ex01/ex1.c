#include<stdio.h>
int main(){
	int i=0,j=0,num=0,data[5001]={0},cost[5001]={0},temp=0,total=0;
	while((scanf("%d",&num)!=EOF)&&(num!=0)){
		for(i=1;i<=num;i++)scanf("%d",&data[i]);
		for(i=0;i<=num-1;i++)
			for(j=0;j<=num-1-i;j++)
			if(data[j]>data[j+1]){
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		for(i=1;i<=num;i++)cost[i]=cost[i-1]+data[i];
		for(i=2;i<=num;i++)total=total+cost[i];
		printf("%d\n",total);
		total=0;temp=0;num=0;
	}
	return 0;
}
