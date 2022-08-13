#include <stdio.h>
#include <string.h>

int visited[20];
int graph[20][20];

/**queue implementation**/
int front = 0;
int rear = 0;
int q[20] = { 0 };
void enqueue(int val);
int dequeue();
/************************/

void bfs(int v, int n);

int main() {
	int N;
	scanf("%d",&N);
	for(int k=0; k<N; k++){
		for(int j=0; j<N; j++){
			scanf("%d",&graph[k][j]);
		}
	}	
	memset(visited, 0, sizeof(visited));

	bfs(0,N);
	return 0;
}

void bfs(int v, int n) {

	visited[v] = 1;
	enqueue(v);

	/* your code */


}
void enqueue(int val){
	/* your code */

}

int dequeue(){
	/* your code */

}
