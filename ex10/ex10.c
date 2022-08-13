#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
	int amount,num;
	struct Node *lptr=NULL;
	while(scanf("%d",&amount)&&amount!=0){
		createNode(&lptr,amount);
		printf("Discarded cards:");
		while((lptr)->link!=NULL){
			dequeue(&lptr,1);
			num=lptr->data;
			move(lptr,num);
			dequeue(&lptr,0);
		}
		lptr=NULL;
	}
	return 0;
}
