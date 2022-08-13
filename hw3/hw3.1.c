/* 
#Author: Sheng-Huai,Hsu 105703047 
#Date: Mar.31,2017 
#Purpose: NCCUCS 1052 CP2 Assign 3 - Stable Relationship Problem 
 */  
#include<stdio.h>  
#include<string.h>  
#include<math.h>  
int num,i,j,k,l,m,n,brk,ntemp,table[30][37]={0},like[30][16]={0},like2[30][16]={0},time[30];/*0=sex 1-20=style point 21-36=set*/  
char temp,stemp[30],name[30][11],sex[7],pre[30][3][30],style[30][20][30];  
void test(){
	printf("num=%d\n",num);
	printf("\nname:\n");
	for(i=0;i<num;i++)printf("%s\n",name[i]);
	printf("\ntable:\n");
	for(i=0;i<num;i++){
		for(j=0;j<37;j++)printf("%d ",table[i][j]);
		printf("\n");
	}
	printf("\nlike:\n");
	for(i=0;i<num;i++){
		for(j=0;j<16;j++)printf("%d ",like[i][j]);
		printf("\n");
	}
	printf("\nlike name\n");
	for(i=0;i<num;i++){
		printf("%s : ",name[i]);
		for(j=0;j<num/2;j++)printf("%s > ",name[like[i][j]]);
		printf("\n");
	}
	printf("\npre:\n");
	for(i=0;i<num;i++){
		for(j=0;j<3;j++)printf("%s ",pre[i][j]);
		printf("\n");
	}
	printf("\ntime:\n");
	for(i=0;i<30;i++)printf("%d ",time[i]);
	printf("\nstyle:\n");
	for(i=0;i<num;i++){
		for(j=0;j<20;j++)printf("%s ",style[i][j]);
		printf("\n");
	}
	printf("\n");
}
int main(){  
	scanf("%d",&num);  
	for(i=0;i<30;i++){  
		memset(name[i],'\0',11);/*clean name*/  
		for(j=0;j<3;j++)memset(pre[i][j],'\0',30);/*clean prefer*/  
		for(j=0;j<16;j++)like[i][j]=-1;/*clean like*/  
	}  
	for(i=0;i<num;i++){  
		scanf("%s %s %s %s %s",name[i],sex,pre[i][0],pre[i][1],pre[i][2]);  
		if(sex[0]=='M')table[i][0]=0;  
		else table[i][0]=1;  
		temp='\0';  
		for(j=0;j<20;j++)memset(style[i][j],'\0',30);/*clean style*/  
		for(j=0;j<20&&temp!='\n';j++)scanf("%s %d%c",style[i][j],&table[i][j+1],&temp);/*scan*/ 
	}/*input file*/
	for(i=0;i<num-1;i++)  
		for(j=0;j<num-i-1;j++)  
			if(table[j][0]>table[j+1][0]){  
				for(k=0;k<21;k++){  
					ntemp=table[j+1][k];  
					table[j+1][k]=table[j][k];  
					table[j][k]=ntemp;  
				}  
				memset(stemp,'\0',30);  
				strcpy(stemp,name[j+1]);  
				memset(name[j+1],'\0',11);  
				strcpy(name[j+1],name[j]);  
				memset(name[j],'\0',11);  
				strcpy(name[j],stemp);  
				for(n=0;n<3;n++){  
					memset(stemp,'\0',30);  
					strcpy(stemp,pre[j+1][n]);  
					memset(pre[j+1][n],'\0',30);  
					strcpy(pre[j+1][n],pre[j][n]);  
					memset(pre[j][n],'\0',30);  
					strcpy(pre[j][n],stemp);  
				}
				for(k=0;k<20;k++){
					memset(stemp,'\0',30);
					strcpy(stemp,style[j+1][k]);
					memset(style[j+1][k],'\0',11);
					strcpy(style[j+1][k],style[j][k]);
					memset(style[j][k],'\0',11);
					strcpy(style[j][k],stemp);
				}
			}/*bb sort for sex*/  
	for(i=0;i<num/2-1;i++)  
		for(j=0;j<num/2-i-1;j++){  
			brk=0;  
			for(l=0;l<11&&brk==0;l++){  
				if(name[j][l]>name[j+1][l]||(name[j][l]!='\0'&&name[j+1][l]=='\0')){  
					for(k=0;k<21;k++){  
						ntemp=table[j+1][k];  
						table[j+1][k]=table[j][k];  
						table[j][k]=ntemp;  
					}  
					memset(stemp,'\0',30);  
					strcpy(stemp,name[j+1]);  
					memset(name[j+1],'\0',11);  
					strcpy(name[j+1],name[j]);  
					memset(name[j],'\0',11);  
					strcpy(name[j],stemp);  
					for(n=0;n<3;n++){  
						memset(stemp,'\0',30);  
						strcpy(stemp,pre[j+1][n]);  
						memset(pre[j+1][n],'\0',30);  
						strcpy(pre[j+1][n],pre[j][n]);  
						memset(pre[j][n],'\0',30);  
						strcpy(pre[j][n],stemp);  
					}
					for(k=0;k<20;k++){
						memset(stemp,'\0',30);
						strcpy(stemp,style[j+1][k]);
						memset(style[j+1][k],'\0',11);
						strcpy(style[j+1][k],style[j][k]);
						memset(style[j][k],'\0',11);
						strcpy(style[j][k],stemp);
					}
					brk=1;  
				}  
				else if(name[j][l]<name[j+1][l]||(name[j][l]=='\0'&&name[j+1][l]!='\0'))brk=1;  
			}  
		}/*bb sort for men name*/  
	for(i=0;i<num/2-1;i++)  
		for(j=num/2;j<num-i-1;j++){  
			brk=0;  
			for(l=0;l<11&&brk==0;l++){  
				if(name[j][l]>name[j+1][l]||(name[j][l]!='\0'&&name[j+1][l]=='\0')){  
					for(k=0;k<21;k++){  
						ntemp=table[j+1][k];  
						table[j+1][k]=table[j][k];  
						table[j][k]=ntemp;  
					}  
					memset(stemp,'\0',30);  
					strcpy(stemp,name[j+1]);  
					memset(name[j+1],'\0',11);  
					strcpy(name[j+1],name[j]);  
					memset(name[j],'\0',11);  
					strcpy(name[j],stemp);  
					for(n=0;n<3;n++){  
						memset(stemp,'\0',30);  
						strcpy(stemp,pre[j+1][n]);  
						memset(pre[j+1][n],'\0',30);  
						strcpy(pre[j+1][n],pre[j][n]);  
						memset(pre[j][n],'\0',30);  
						strcpy(pre[j][n],stemp);  
					}
					for(k=0;k<20;k++){
						memset(stemp,'\0',30);
						strcpy(stemp,style[j+1][k]);
						memset(style[j+1][k],'\0',11);
						strcpy(style[j+1][k],style[j][k]);
						memset(style[j][k],'\0',11);
						strcpy(style[j][k],stemp);
					}
					brk=1;  
				}  
				else if(name[j][l]<name[j+1][l]||(name[j][l]=='\0'&&name[j+1][l]!='\0'))brk=1;  
			}  
		}/*bb sort for women name*/  
	for(i=0;i<num/2;i++)  
		for(j=0;j<num/2;j++)like[i][j]=j+num/2;  
	for(i=num/2;i<num;i++)  
		for(j=0;j<num/2;j++)like[i][j]=j;/*declare like*/  
	for(i=0;i<num/2;i++)/*men*/  
		for(j=num/2;j<num;j++){/*women*/  
			for(l=0;l<3;l++)  
				for(k=0;k<20;k++)  
					if(strcmp(pre[i][l],style[j][k])==0)table[i][21+j-num/2]+=table[j][1+k]*pow(1000,(2-l));/*style*/  
		}/*calculate score for men*/  
	for(i=num/2;i<num;i++)/*women*/  
		for(j=0;j<num/2;j++){/*men*/  
			for(l=0;l<3;l++)  
				for(k=0;k<20&&l<3;k++)  
					if(strcmp(pre[i][l],style[j][k])==0)table[i][21+j]+=table[j][1+k]*pow(1000,(2-l));  
		}/*calculate score for women*/  
	for(i=0;i<num;i++)/*people*/  
		for(j=0;j<num/2-1;j++)  
			for(k=0;k<num/2-1-j;k++)  
				if(table[i][k+21]<table[i][k+22]){  
					ntemp=table[i][k+22];  
					table[i][k+22]=table[i][k+21];  
					table[i][k+21]=ntemp;  
					ntemp=like[i][k+1];  
					like[i][k+1]=like[i][k];  
					like[i][k]=ntemp;  
				}/*bb sort for like*/
	for(i=0;i<num;i++)  
		for(j=0;j<num/2+1;j++)like2[i][j]=like[i][j];  
	for(i=0;i<num*num;i++){  
		for(j=0;j<30;j++)time[j]=0;/*clean time*/  
		for(j=0;j<num/2;j++)time[like[j][0]]++;/*count time*/  
		for(j=num/2;j<num;j++){  
			brk=0;  
			if(time[j]>1)for(k=0;k<num/2&&brk==0;k++)if(like[like[j][k]][0]==j){  
				brk=1; 
				for(l=0;l<num/2;l++)if(like[l][0]==j&&l!=like[j][k])for(m=0;m<15;m++)like[l][m]=like[l][m+1];/*men to women*/  
			}
		}/*many time case*/  
	}/*men*/  
	for(i=0;i<num*num;i++){  
		for(j=0;j<30;j++)time[j]=0;/*clean time*/  
		for(j=num/2;j<num;j++)time[like2[j][0]]++;/*count time*/  
		for(j=0;j<num/2;j++){  
			brk=0;  
			if(time[j]>1)for(k=0;k<num/2&&brk==0;k++)if(like2[like2[j][k]][0]==j){  
				brk=1;
				for(l=num/2;l<num;l++)if(like2[l][0]==j&&l!=like2[j][k])for(m=0;m<15;m++)like2[l][m]=like2[l][m+1];/*men to women*/  
			}  
		}/*many time case*/  
	}/*women*/ 
	for(i=0;i<30;i++)time[i]=0;/*reset time*/  
	printf("For women:\n");  
	for(i=num/2;i<num;i++)printf("%s + %s\n",name[i],name[like2[i][0]]);  
	printf("\nFor men:\n");  
	for(i=0;i<num/2;i++)printf("%s + %s\n",name[i],name[like[i][0]]);  
	return 0;  
} 
