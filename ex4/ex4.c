#include <stdio.h>
int main(){
	int a=0,b=0,big=0,i=0,j=0,k=0,q[100]={0},matrix[2][2],matrix1[2][2],matrix2[2][2],det=0,temp=0;
	while(scanf("%d %d",&a,&b)!=EOF){
		if(a>b){
			temp=a;
			a=b;
			b=temp;
			big=1;
		}
		for(i=0;a!=0&&b!=0;i=i+2){
			q[i]=a/b;
			a%=b;
			if(a!=0){
				q[i+1]=b/a;
				b%=a;
			}
		}/*GDC & get q[100]*/
		for(i=0;i<2;i++)
			for(j=0;j<2;j++){
				if(i!=j){
					matrix[i][j]=1;
					matrix2[i][j]=1;
				}
				else{
					matrix[i][j]=0;
					matrix2[i][j]=0;
				}
			}/*clean matrix*/
		matrix1[0][0]=q[0];
		for(k=1;q[k]!=0;k++){
			for(i=0;i<2;i++)
				for(j=0;j<2;j++)matrix1[i][j]=matrix[i][j];/*matrix1=matrix*/
			matrix2[0][0]=q[k];
			matrix[0][0]=matrix1[0][0]*matrix2[0][0]+matrix1[0][1]*matrix2[1][0];
			matrix[0][1]=matrix1[0][0]*matrix2[0][1]+matrix1[0][1]*matrix2[1][1];
			matrix[1][0]=matrix1[1][0]*matrix2[0][0]+matrix1[1][1]*matrix2[1][0];
			matrix[1][1]=matrix1[1][0]*matrix2[0][1]+matrix1[1][1]*matrix2[1][1];
		}/*calculate matrix*/
		det=matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
		matrix[0][0]=matrix[1][1]/det;
		matrix[0][1]=matrix[0][1]*(-1)/det;
		/*calculate inverse*/
		if(big==1){
			temp=matrix[0][0];
			matrix[0][0]=matrix[0][1];
			matrix[0][1]=temp;
		}/*for small to big*/
		big=0;
		printf("%d %d %d\n",matrix[0][0],matrix[0][1],a+b);/*print out*/
		for(i=0;i<100;i++)q[i]=0;/*clean q[100]*/
	}
	return 0;
}
