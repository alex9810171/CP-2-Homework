#include<stdio.h>
int main(){
	int i,det;
	char word,key[47]={"`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"};
	while(scanf("%c",&word)!=EOF){
		det=0;
		if(word>=65&&word<=90)word=word+32;
		for(i=0;i<2;i++)
			if(key[i]==word){
				printf("%c",key[45+i]);
				det=1;
			}
		for(i=2;i<47;i++)
			if(key[i]==word){
				printf("%c",key[i-2]);
				det=1;
			}
		if(det==0)printf("%c",word);
	}
	return 0;
}
