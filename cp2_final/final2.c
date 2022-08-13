#include <stdio.h>
#include <stdlib.h>

int main(){
	int seq[10000],i,j,k,l,tnum,time=1,two=0,len=1;
	char tmp;
	while(scanf("%d%c",&seq[0],&tmp)!=EOF){
		for(i=1;i<10000;i++)seq[i]=0;
		len=1;/*clean*/
		for(i=1;tmp!='\n';i++){
			scanf("%d%c",&seq[i],&tmp);
			len++;
		}/*scan*/
		for(i=0;i<len-1;i++)
			for(j=0;j<len-1;j++)
				if(seq[j]>seq[j+1]){
					tnum=seq[j];
					seq[j]=seq[j+1];
					seq[j+1]=tnum;
				}/*sort*/
//		for(k=0;k<len;k++)printf("%d ",seq[k]);
		for(i=0;i<len;i++){
			for(k=0;k<len;k++)printf("%d ",seq[k]);
			if(seq[i]==seq[i+1]){
				for(j=i;j<len;j++)seq[j]=seq[j+1];
				two=1;
				i--;
				len--;
				
			}
			else if(two==1){
				for(j=i;j<len;j++)seq[j]=seq[j+1];
				two=0;
				i--;
				len--;
			}
//			for(k=0;k<len;k++)printf("%d ",seq[k]);
			printf("\ntwo=%d i=%d\n",two,i+1);
		}
		//		for(i=0;i<10;i++)printf("%d ",seq[i]);
		//		if(seq[0]==0&&seq[1]!=0)spe=1;
		//		for(i=0;seq[i]!=0;i++){
		//			time=1;
		//			tnum=seq[i];
		//			for(j=i+1;seq[j]==tnum;j++)time++;
		//			if(time!=1){
		//				for(k=0;k<time;k++)for(l=i;l<9999;l++)seq[l]=seq[l+1];
		//				i--;
		//			}
		//		}/*cut*/
		//		printf("\n");
		//		for(i=0;i<10;i++)printf("%d ",seq[i]);
		if(len>0){
			i=0;
			for(i=0;i<len-1;i++)printf("%d ",seq[i]);
			printf("%d\n",seq[i]);
		}
		else printf("Empty!\n");
		//		else{
		//			for(i=0;seq[i+1]!=0;i++){
		//				if(seq[i]!=0)printf("%d ",seq[i]);
		//			}
		//			if(seq[i]!=0)printf("%d",seq[i]);
		//			if(i==0&&seq[i]==0)printf("Empty!");
		//			printf("\n");
		//		}
	}
	return 0;
	}

