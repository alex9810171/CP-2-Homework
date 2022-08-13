#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void createNode(struct Node **lptr,int amount){
	int tmp;
	for(tmp=amount;tmp>0;tmp--)enqueue(lptr,tmp);
}
void enqueue(struct Node **lptr,int num){
	struct Node *ptr=NULL;
	(ptr)=malloc(sizeof(struct Node));
	(ptr)->data=num;
	(ptr)->link=*lptr;
	*lptr=ptr;
}
void dequeue(struct Node **lptr,int prt){
	struct Node *tptr=*lptr;
	*lptr=tptr->link;
	if(prt==1){
		if(((*lptr)->link)==NULL) printf(" %d\nRemaining card: %d\n",tptr->data,(*lptr)->data);
		else printf(" %d,",tptr->data);
	}
	free(tptr);
}
void move(struct Node *lptr,int num){
	if(lptr->link!=NULL)move(lptr->link,num);
	else{
		struct Node *ptr=NULL;
		(ptr)=malloc(sizeof(struct Node));
		lptr->link=ptr;
		(ptr)->data=num;
		(ptr)->link=NULL;
	}
}
