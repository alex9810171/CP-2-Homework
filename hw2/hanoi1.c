#include<stdio.h>
int conf[1000];
void move(int d,int t){
	/*move disk d to peg t*/
	conf[d]=t;
	//printf("conf[%d]=%d\n",d,t);
}
void hanoi(int h,int t){
	if(h>0){
		int f=conf[h-1];
		//printf("%d=conf[%d]\n",f,h-1);
		if(f!=t){
			int r=3-f-t;
			//printf("r(%d)=3-f(%d)-t(%d)\n",r,f,t);
			hanoi(h-1,r);
			move(h-1,t);
			printf("move\n");
		}
		hanoi(h-1,t);
	}
}
int main(){
	int h,t;
	scanf("%d %d",&h,&t);
	hanoi(h,t);
//	printf("h=%d t=%d\n",h,t);
	return 0;
}
