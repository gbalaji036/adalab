#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[],int n)
{
	int i,j,minIdx,temp;
	for(i=0;i<n-1;i++)
	{
		minIdx=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[minIdx])
			{
				minIdx=j;
			}
		}
		
		temp=arr[minIdx];
		arr[minIdx]=arr[i];
		arr[i]=temp;
	}
}

void generateRandomArray(int arr[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%10000;
	}
}

void main()
{	
	int n=5000;
	int increment=5000;
	int max_n=50000;
	
	for(n=5000;n<=max_n;n+=increment)
	{
		int arr[n];
		generateRandomArray(arr,n);
		clock_t start=clock();
		selectionSort(arr,n);
		clock_t end=clock();
		
		double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
		printf("n=%d,Time Taken=%f seconds\n",n,time_taken);
	}
}
