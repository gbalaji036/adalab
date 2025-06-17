#include <stdio.h>
void main()
{
    int i, j, a[10][10], n, m = 0, k, que[10], flag[10];
    printf("enter the no of vertices\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        flag[i] = 0, que[i] = 0;
    printf("enter the matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j])
                flag[j]++;
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            if (!flag[i])
            {
                flag[i] = -1;
                que[++m] = i;
                for (j = 1; j <= n; j++)
                {
                    if (a[i][j] && flag[j] > 0)
                    {
                        flag[j]--;
                    }
                }
            }
        }
    }

    if (m == n)
    {
        printf("The topological order is:\n");
        for (i = 1; i <= n; i++)
        {
            printf("\t %d", que[i]);
        }
    }
    else
        printf("No topological order\n");
}
