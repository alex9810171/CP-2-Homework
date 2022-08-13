#include <stdio.h>
#include <string.h>
int i,j,brk=0,len,typelen=0;
char type[200],str[11],string[100][11];
void test(){
	int i,j;
	for(i=0;i<len*2;i+=2)printf("%d%c\n",type[i],type[i+1]);
	printf("len=%d typelen=%d\n",len,typelen);
}
int main(){
	while(scanf("%s",type)!=EOF){
		for(i=0;type[i]!='\0';i=i+2){
			type[i]=type[i]-48;
			typelen+=type[i];
		}
		len=i/2;
		for(i=0;i<len;i++){
			if(string[type[i*2+1]-97][0]=='\0')scanf("%s",string[type[i*2+1]-97]);
			else{
				scanf("%s",str);
				if(strcmp(str,string[type[i*2+1]-97])!=0){
					printf("False\n");
					brk=1;
				}
			}
			for(j=1;j<type[2*i];j++){
				scanf("%s",str);
				if(strcmp(str,string[type[i*2+1]-97])!=0&&brk==0){
					printf("False\n");
					brk=1;
				}
			}
		}
		if(brk==0)printf("True\n");
		for(i=0;i<100;i++){
			for(j=0;j<11;j++)string[i][j]='\0';
			type[i]=0;
		}
		typelen=0;
		brk=0;
	}
	return 0;
}
