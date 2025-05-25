#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int low,int high)
{
	int pivot=arr[high];
	int i=(low-1),j;
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return(i+1);
}

void quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pi=partition(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}

void generateRandomArray(int arr[],int n)
{
	int i;
	for(i=0; i<n;i++)
	{
		arr[i]=rand()%10000;
	}
}

void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
}

int main()
{
	srand(time(NULL));
	int n_values[]={50000,100000,150000,200000,250000,300000,350000,400000,450000,500000};
	int i;
	for(i=0;i<10;i++)
	{
		int n=n_values[i];
		int arr[n];
		
		generateRandomArray(arr,n);
		clock_t start=clock();
		quickSort(arr,0,n-1);
		clock_t end=clock();
		double time_taken=((double)(end-start))/CLOCKS_PER_SEC * 1000;
		printf("Time taken to sort %d elements: %.2f ms\n",n,time_taken);
	}
	return 0;
}
