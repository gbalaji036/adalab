#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Edge
{
    int u, v, weight;
};
int parent[MAX];
int find(int i)
{
    while (i != parent[i])
        i = parent[i];
    return i;
}
void union_sets(int a, int b)
{
    parent[a] = b;
}
void krushkal(struct Edge edges[], int e)
{
    struct Edge temp;
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, e;
    struct Edge edges[MAX], temp;
     printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    for (int i = 0; i < e; i++)
    {
        printf("Enter edge %d (u v weight): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    krushkal(edges, e);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("Minimum Spanning Tree:\n");
    int total = 0;
    for (int i = 0; i < e; i++)
    {
        int u = find(edges[i].u);
        int v = find(edges[i].v);
        if (u != v)
        {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].weight);
            total += edges[i].weight;
            union_sets(u, v);
        }
    }

    printf("Total cost: %d\n", total);
    return 0;
}
