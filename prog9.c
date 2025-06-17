#include <stdio.h>

#define MAX 100

int main() {
    int n, sum, a[MAX], dp[MAX][MAX] = {0};

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter required sum: ");
    scanf("%d", &sum);

    // Initialize: sum 0 is always possible
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < a[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j - a[i-1]];
        }
    }

    if (!dp[n][sum]) {
        printf("No subset found\n");
        return 0;
    }

    // Backtrack to print one subset
    printf("Subset with sum %d: ", sum);
    int i = n, j = sum;
    while (i > 0 && j > 0) {
        if (dp[i-1][j]) {
            i--;
        } else {
            printf("%d ", a[i-1]);
            j -= a[i-1];
            i--;
        }
    }

    printf("\n");
    return 0;
}

