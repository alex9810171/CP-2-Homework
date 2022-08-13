#include <stdio.h>
#include <string.h>
int main(){
	int detect1=1,detect2=1,detect3=1,i=0;/*0=false 1=true*/
	char word[10];
	memset(word,'\0',10);
	while(scanf("%s",word)!=EOF){
		for(i=0;i<10&&word[i]!='\0'&&detect1==1;i++)if(word[i]<65||word[i]>90)detect1=0;/*detect1 upper*/
		for(i=0;i<10&&word[i]!='\0'&&detect2==1;i++)if(word[i]<97||word[i]>122)detect2=0;/*detect2 lower*/
		if(word[0]>=65&&word[0]<=90){
			for(i=1;i<10 && word[i]!='\0' && detect3==1;i++){
				if(word[i]<97||word[i]>122)detect3=0;
			}
		}
		else detect3=0;/*detect3*/
		if(detect1==1||detect2==1||detect3==1)printf("True\n");
		else printf("False\n");
		memset(word,'\0',10);
		detect1=1;detect2=1;detect3=1;
	}
	return 0;
}
