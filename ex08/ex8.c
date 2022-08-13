#include <stdio.h>
#include "tree.h"
int main(){
	int num,i=0;
	struct list *sr=NULL;
	while(scanf("%d",&num)!=EOF){
		ctree(&sr,num);
		i++;
	}
	inorder(sr,&i);
	printf("\n");
	eman(sr);
	return 0;
}
/*
scan
create tree()
print tree(inorder)
free(eman)
 */
