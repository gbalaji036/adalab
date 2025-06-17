#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge two halves
void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

// Recursive Merge Sort
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// Fill array with random numbers
void fillRandom(int a[], int n) {
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100000;
}

int main() {
    srand(time(0));
    FILE *f = fopen("results.csv", "w");
    if (!f) {
        printf("Cannot open file.\n");
        return 1;
    }

    fprintf(f, "Size,Time(ms)\n");

    for (int n = 5000; n <= 10000; n += 500) {
        int *a = malloc(n * sizeof(int));
        if (!a) {
            printf("Memory error.\n");
            return 1;
        }

        fillRandom(a, n);
        clock_t start = clock();
        mergeSort(a, 0, n - 1);
        clock_t end = clock();

        double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
        fprintf(f, "%d,%.2f\n", n, time);
        free(a);
    }

    fclose(f);
    printf("Done. Results saved in results.csv\n");
    return 0;
}
