#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int u, v, w;
};

struct Subset {
    int parent, rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

void kruskal(struct Edge edges[], int V, int E) {
    struct Subset subsets[MAX];
    struct Edge mst[MAX];
    int cost = 0, count = 0;

    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    qsort(edges, E, sizeof(edges[0]), compare);

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int setU = find(subsets, u);
        int setV = find(subsets, v);

        if (setU != setV) {
            mst[count++] = edges[i];
            cost += edges[i].w;
            unionSets(subsets, setU, setV);
        }
    }

    printf("Edges in MST:\n");
    for (int i = 0; i < count; i++)
        printf("%d - %d : %d\n", mst[i].u, mst[i].v, mst[i].w);
    printf("Total weight: %d\n", cost);
}

int main() {
    int V, E;
    struct Edge edges[MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    kruskal(edges, V, E);
    return 0;
}
