#include <stdio.h>
#define MAX 100

struct Edge {
    int u, v, weight;
};

int parent[MAX];

// Find with simple path traversal
int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

// Union two sets
void union_sets(int a, int b) {
    parent[a] = b;
}

// Sort edges by weight using simple bubble sort
void sortEdges(struct Edge edges[], int e) {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, e;
    struct Edge edges[MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++) {
        printf("Edge %d (u v weight): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Initialize parent array
    for (int i = 0; i < n; i++)
        parent[i] = i;

    sortEdges(edges, e);

    printf("Minimum Spanning Tree:\n");
    int total = 0;
    for (int i = 0; i < e; i++) {
        int uRoot = find(edges[i].u);
        int vRoot = find(edges[i].v);

        if (uRoot != vRoot) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].weight);
            total += edges[i].weight;
            union_sets(uRoot, vRoot);
        }
    }

    printf("Total cost: %d\n", total);
    return 0;
}
