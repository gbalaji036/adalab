#include <stdio.h>

#define MAX_N 100
#define MAX_SUM 1000

int main() {
    int n, d, S[MAX_N];
    int dp[MAX_N + 1][MAX_SUM + 1];
    int i, j;

    printf("Enter number of elements in set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &S[i]);

    printf("Enter the required sum: ");
    scanf("%d", &d);

    // Initialize DP table
    for (i = 0; i <= n; i++)
        dp[i][0] = 1; // Sum 0 is always possible (empty subset)
    for (j = 1; j <= d; j++)
        dp[0][j] = 0; // With 0 elements, no sum except 0 is possible

    // Fill DP table
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= d; j++) {
            if (j < S[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j - S[i-1]];
        }
    }

    // If no subset with sum d exists
    if (!dp[n][d]) {
        printf("No subset found\n");
        return 0;
    }

    // To print one subset, backtrack the DP table
    printf("Subset with sum %d is: ", d);
    i = n;
    j = d;
    while (i > 0 && j > 0) {
        // If the sum j can be obtained without the current element,
        // then the current element is not included.
        if (dp[i-1][j])
            i--;
        else {
            // Else the current element is included.
            printf("%d ", S[i-1]);
            j -= S[i-1];
            i--;
        }
    }
    printf("\n");

    return 0;
}
