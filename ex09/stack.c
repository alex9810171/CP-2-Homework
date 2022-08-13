#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(struct list **mptr,int num){
	struct list *nptr=NULL;
	(nptr)=malloc(sizeof(struct list));
	(nptr)->data=num;
	(nptr)->link=*mptr;
	*mptr=nptr;
}
void pop(struct list **mptr){
	struct list *tptr=*mptr;
	*mptr=tptr->link;
	free(tptr);
}
void reverse(struct list **data){
	struct list *before=NULL;
	struct list *now=*data;
	struct list *next=(*data)->link;
	while(next!=NULL){
		now->link=before;
		before=now;
		now=next;
		next=next->link;
	}
	now->link=before;
	*data=now;
}
void show(struct list *data){
	if(data->link==NULL)printf("%d\n",data->data);
	else{
		printf("%d ",data->data);
		show(data->link);
	}
}
