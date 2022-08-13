#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
void ctree(struct list **sr,int num){
	if(*sr==NULL){
		(*sr)=malloc(sizeof(struct list));
		if(*sr!=NULL){
			(*sr)->data=num;
			(*sr)->leftchild=NULL;
			(*sr)->rightchild=NULL;
		}
	}
	else{
		if(num <= (*sr)->data)ctree(&((*sr)->leftchild),num);
		else if(num > (*sr)->data)ctree(&((*sr)->rightchild),num);
	}
}
void inorder(struct list *sr,int *i){
	if (sr!= NULL){
		inorder(sr -> rightchild,i);
		if(*i>1){
			printf("%d ",sr -> data);
			(*i)--;
		}
		else printf("%d",sr -> data);
		inorder(sr -> leftchild,i);
	}
}
void eman(struct list *sr){
	if(sr==NULL)return;
	eman(sr -> leftchild);
	eman(sr -> rightchild);
	free(sr);
}
