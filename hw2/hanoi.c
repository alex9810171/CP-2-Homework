#include <stdio.h>
#include <stdlib.h>

void hanoi(int, char, char, char);

int time = 0;

int main(void){
	int n;

	printf("Please enter the height of hanoi:");
	scanf("%d", &n);

	hanoi(n, 'A', 'B', 'C');

	printf("It needs %d times to move %d floor of hanoi.\n",time,n);

	return 0;
}

void hanoi(int n, char A, char B, char C){
	if (n == 1){
		printf("%d:Move the %dst disc from %c to %c\n", ++time, n, A, C);
	}
	else{
		hanoi(n - 1, A, C, B);
		printf("%d:Move the %dst disc from %c to %c\n", ++time, n, A, C);
		hanoi(n - 1, B, A, C);
	}
}
