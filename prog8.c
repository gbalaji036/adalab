#include <stdio.h>

int max(int a, int b){
	return (a>b)?a:b;
}

int knapsack(int W, int wt[], int val[], int n){
	int i,w;
	int K[n+1][W+1];
	
	for(i=0;i<=n;i++){
		for(w=0;w<=W;w++){
			if(i==0 || w==0)
				K[i][w]=0;
			else if(wt[i-1]<=w)
				K[i][w]=max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
			else
				K[i][w]=K[i-1][w];
		}
	}
	return K[n][W];
}

int main(){
	int n,W;
	
	printf("Enter number of items:");
	scanf("%d",&n);
	
	int val[n],wt[n];
	
	printf("Enter value and weight for each item:\n");
	for(int i=0;i<n;i++){
		printf("Item %d - Value:",i+1);
		scanf("%d",&val[i]);
		printf("Item %d - Weight:",i+1);
		scanf("%d",&wt[i]);
	}
	
	printf("Enter capacity of knapsack:");
	scanf("%d",&W);
	
	int result = knapsack(W,wt,val,n);
	printf("Maximum value that can be put in knapsack = %d\n",result);
	return 0;
}
