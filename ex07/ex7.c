#include<stdio.h>
#include<stdlib.h>
typedef struct link lptr;
typedef lptr *num;
struct link{
	int list1;
	struct link *num;
};
int main(){
	int i,num2,array1[100],array2[100],has;
	lptr* first=NULL;
	first=malloc(sizeof(lptr));
	first->num=NULL;
	scanf("%d",&first->list1);
	for(i=0;i<first->list1;i++)scanf("%d",&array1[i]);
	has=0;
	for(i=first->list1-1;i>0;i--){
		if(array1[i]!=0&&has==0){
			printf("%dX^%d",array1[i],i);
			has=1;
		}
		else if(array1[i]!=0&&has==1)printf("+%dX^%d",array1[i],i);
	}
	if(array1[i]!=0&&has==0)printf("%d",array1[i]);
	else if(array1[i]!=0&&has==1)printf("+%d",array1[i]);
	printf("\n");/* part1*/
	scanf("%d",&num2);
	for(i=0;i<num2;i++)scanf("%d",&array2[i]);
	has=0;
	for(i=num2-1;i>0;i--){
		if(array2[i]!=0&&has==0){
			printf("%dX^%d",array2[i],i);
			has=1;
		}
		else if(array2[i]!=0&&has==1)printf("+%dX^%d",array2[i],i);
	}
	if(array2[i]!=0&&has==0)printf("%d",array2[i]);
	else if(array2[i]!=0&&has==1)printf("+%d",array2[i]);
	printf("\n");/*part2*/
	has=0;
	if(first->list1>=num2){
		for(i=0;i<num2;i++)array1[i]+=array2[i];
		for(i=first->list1-1;i>0;i--){
			if(array1[i]!=0&&has==0){
				printf("%dX^%d",array1[i],i);
				has=1;
			}
			else if(array1[i]!=0&&has==1)printf("+%dX^%d",array1[i],i);
		}
		if(array1[i]!=0&&has==0)printf("%d",array1[i]);
		else if(array1[i]!=0&&has==1)printf("+%d",array1[i]);
		printf("\n");
	}
	else{
		for(i=0;i<first->list1;i++)array2[i]+=array1[i];
		for(i=num2-1;i>0;i--){
			if(array2[i]!=0&&has==0){
				printf("%dX^%d",array2[i],i);
				has=1;
			}
			else if(array2[i]!=0&&has==1)printf("+%dX^%d",array2[i],i);
		}
		if(array2[i]!=0&&has==0)printf("%d",array2[i]);
		else if(array2[i]!=0&&has==1)printf("+%d",array2[i]);
		printf("\n");
	}
	return 0;
}
