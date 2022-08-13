#include <stdio.h>
int main(){
	int num=0,i=0,score[100]={0},candy[100]={1},total=0;
	while(scanf("%d",&num)!=EOF){
		for(i=0;i<100;i++)candy[i]=1;
		total=0;/*all zero*/
		for(i=0;i<num;i++)scanf("%d",&score[i]);/*scan score*/
		for(i=0;i<num-1;i++){
			if(score[i]<score[i+1])candy[i+1]=candy[i]+1;
			else if(score[i]==score[i+1])candy[i+1]=candy[i];/*compare to right*/
		}/*to right*/
		for(i=num-1;i>0;i--){
			if((score[i-1]>score[i])&&(candy[i-1]<=candy[i]))candy[i-1]=candy[i]+1;
			else if(score[i]==score[i-1])candy[i-1]=candy[i];
		}/*to left & compare to left*/
		for(i=0;i<num;i++)total+=candy[i];
		printf("%d\n",total);/*print total*/
	}
	return 0;
}

/*
test:
for(i=0;i<num;i++)printf("score[%d]=%d candy[%d]=%d\n",i,score[i],i,candy[i]);
 */
