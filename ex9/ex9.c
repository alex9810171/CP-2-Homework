#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(){
	int num;
	char cmd[8];
	struct list *mptr=NULL;
	while(scanf("%s",cmd)!=EOF){
		if(strcmp(cmd,"push")==0){
			scanf("%d",&num);
			push(&mptr,num);
		}
		else if(strcmp(cmd,"pop")==0){
			if(mptr==NULL){
				printf("The Stack is Empty!\n");
				return 0;
			}
			pop(&mptr);
		}
		else if(strcmp(cmd,"reverse")==0){
			reverse(&mptr);
		}
	}
	if(mptr==NULL){
		printf("The Stack is Empty!\n");
		return 0;
	}
	show(mptr);
	return 0;
}
