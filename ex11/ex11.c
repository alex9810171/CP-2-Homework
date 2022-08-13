#include <stdio.h>
#include <stdlib.h>

int main(){
	int seq[10000],i,j,k,l,tnum,time=1;
	char tmp;
	while(scanf("%d%c",&seq[0],&tmp)!=EOF){
		for(i=1;i<10000;i++)seq[i]=0;/*clean*/
		for(i=1;tmp!='\n';i++)scanf("%d%c",&seq[i],&tmp);/*scan*/
		for(i=1;seq[i]!=0;i++){
			tnum=seq[i];
			for (j=i-1;j>=0&&seq[j]>tnum;j--)seq[j+1]=seq[j];
			seq[j+1]=tnum;
		}/*sort*/
		for(i=0;seq[i]!=0;i++){
			time=1;
			tnum=seq[i];
			for(j=i+1;seq[j]==tnum;j++)time++;
			if(time!=1){
				for(k=0;k<time;k++)for(l=i;l<9999;l++)seq[l]=seq[l+1];
				i--;
			}
		}/*cut*/
		for(i=0;seq[i+1]!=0;i++)printf("%d ",seq[i]);
		printf("%d\n",seq[i]);
	}
	return 0;
}
