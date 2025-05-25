#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;  // Find the middle point
      
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; 
    }
}

int main() {
    srand(time(0)); 
    
    FILE *outfile = fopen("results.csv", "w");
    if (outfile == NULL) {
        printf("Error opening file for writing\n");
        return 1;
    }
    
    
    fprintf(outfile, "n,TimeTaken(ms)\n");
    
   
    for (int n = 5000; n <= 10000; n += 500) {
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
         generateRandomArray(arr, n);
        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        fprintf(outfile, "%d,%.2f\n", n, time_taken);
        free(arr);
    }
    fclose(outfile);
    printf("Results have been saved to 'results.csv'.\n");
    return 0;
}
