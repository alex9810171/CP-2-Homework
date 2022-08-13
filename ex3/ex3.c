#include <stdio.h>
#include <string.h>
int main(){
	int i=0,j=0,detect=0;/*num=num of type ; detect=0/1,true/false*/
	char type[101],word[26][11],temp[11];
	while(scanf("%s",type)!=EOF){/*input type*/
		for(i=0;i<26;i++)for(j=0;j<11;j++)word[i][j]='\0';/*reset*/
		for(i=0;type[i]!='\0';i++){
			scanf("%s",temp);/*input string*/
			if(word[type[i]-97][0]=='\0')strcpy(word[type[i]-97],temp);
			else if(strcmp(word[type[i]-97],temp)!=0)detect=1;/*compare*/
			memset(temp,'\0',11);
		}
		for(i=0;i<26;i++)for(j=i+1;j<26;j++)if(strcmp(word[i],word[j])==0&&word[i][0]!='\0'&&word[j][0]!='\0')detect=1;/*check*/
		if(detect==0)printf("True\n");
		else if(detect==1)printf("False\n");/*print answer*/
		detect=0;
		memset(type,'\0',101);/*reset*/
	}
	return 0;
}

/*
note:
printf("%s temp=%s\n",word[type[i]-97],temp);
printf("detect=%d\n",detect);
for(num=0;type[num]>=97&&type[num]<=122;num++); count num
 */
