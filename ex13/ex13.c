/*
ex13_0.0.1 beta
   */
#include <stdio.h>
int node,line,linedata[20000][3],mtree[10000],ttree[9999],mtreelong=1,tlong=1,space=1,decide,check1,check2;
void test(){
	int i,j;
	printf("node = %d ; line = %d\n",node,line);
	for(i=0;i<line;i++)printf("linedata[%d] : %d | %d | %d |\n",i,linedata[i][0],linedata[i][1],linedata[i][2]);
	for(i=0;i<=mtreelong;i++)printf("mtree[%d] : %d\n",i,mtree[i]);
	printf("mtreelong = %d ,space = %d , decide = %d , check1 = %d , check2 = %d\n",mtreelong,space,decide,check1,check2);
}
int main(){
	int i,j,k,a,b;
	scanf("%d %d",&node,&line);
	for(i=0;i<line;i++){
		scanf("%d %d",&linedata[i][0],&linedata[i][1]);
		if(linedata[i][0]>linedata[i][1]){
			a=linedata[i][0];
			linedata[i][0]=linedata[i][1];
			linedata[i][1]=a;
		}
	}
	for(i=0;i<line-1;i++)
		for(j=0;j<line-1;j++){
			if(linedata[j][0]==linedata[j+1][0]&&linedata[j][1]>linedata[j+1][1]){
				a=linedata[j][0];
				b=linedata[j][1];
				linedata[j][0]=linedata[j+1][0];
				linedata[j][1]=linedata[j+1][1];
				linedata[j+1][0]=a;
				linedata[j+1][1]=b;
			}
			else if(linedata[j][0]>linedata[j+1][0]){
				a=linedata[j][0];
				b=linedata[j][1];
				linedata[j][0]=linedata[j+1][0];
				linedata[j][1]=linedata[j+1][1];
				linedata[j+1][0]=a;
				linedata[j+1][1]=b;
			}
		}
	mtree[0]=linedata[0][0];
	mtree[1]=linedata[0][1];
	linedata[0][2]=1;
	for(i=1;i<line;i++){/*mtree : find the same point*/
		if(linedata[i][0]==mtree[mtreelong]){
			mtree[mtreelong+1]=linedata[i][1];
			linedata[i][2]=1;
			mtreelong++;
		}
	}
	while(space<line&&decide==0){/*branch : find the same point*/
		for(i=1;i<line&&linedata[i][2]==1;i++);
		ttree[0]=linedata[i][0];
		ttree[1]=linedata[i][1];
		linedata[i][2]=1;
		space=i+1;
		if(i==line){
			space=line;
			break;
		}
		for(i=0;i<=mtreelong;i++)if(mtree[i]==ttree[0])check1=1;
		for(i=0;i<=mtreelong;i++)if(mtree[i]==ttree[1])check2=1;
		if(check1==1&&check2==1){
			printf("NO\n");
			decide=1;
			break;
		}
		for(i=space;i<line&&decide==0;i++){
			if(linedata[i][0]==ttree[tlong]&&linedata[i][2]==0){
				tlong++;
				ttree[tlong]=linedata[i][1];
				linedata[i][2]=1;
				for(i=0;i<=mtreelong;i++)if(mtree[i]==ttree[tlong])check2=1;
				if(check1==1&&check2==1){
					printf("NO\n");
					decide=1;
					break;
				}
			}
		}
		if(check1==check2){
			printf("NO\n");
			decide=1;
			break;
		}
		else{
			for(i=0;i<=tlong;i++){
				for(j=0;j<=mtreelong&&mtree[j]!=ttree[i];j++);
				if(j==mtreelong+1){
					mtree[mtreelong+1]=ttree[i];
					mtreelong++;
				}
			}
		}
		for(i=0;i<=tlong;i++)ttree[i]=0;
		tlong=1;
	}
	if(decide==0)printf("YES\n");
	return 0;
}
/*
   0<node<=10000 0<=line<=20000
 */
