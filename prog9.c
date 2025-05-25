#include <stdio.h>
#include <stdbool.h>
#define Max 20

int board[Max];
int N;

bool isSafe(int r, int c){
	for(int i=0;i<r;i++){
		if(board[i]==c || board[i]-i==c-r || board[i]+i==c+r)
			return false;
	}
	return true;
}

void solve(int row){
	if (row==N){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(board[i]==j)
					printf("Q");
				else
					printf(".");
			}
			printf("\n");
		}
		printf("\n");
		return;
	}
	for(int col=0;col<N;col++){
		if(isSafe(row,col)){
			board[row]=col;
			solve(row+1);
		}
	}
}

int main(){
	printf("Enter the value of N(number of queens):");
	scanf("%d",&N);
	if(N<1 || N>Max){
		printf("Please enter N between 1 and %d\n",Max);
		return 1;
	}
	printf("Solutions to the %d - Queens problem:\n\n",N);
	solve(0);
	return 0;
}
