#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to create a subset
void createSubset(struct Subset subsets[], int V) {
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
}

// Function to find the subset of an element with path compression
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to do union of two subsets with union by rank
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Union by rank
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare two edges (used for sorting edges by weight)
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's algorithm to find the MST
void kruskalMST(struct Edge edges[], int V, int E) {
    struct Subset subsets[V];

    // Step 1: Sort edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Create V subsets
    createSubset(subsets, V);

    struct Edge mst[V - 1];  // MST will have V-1 edges
    int mstIndex = 0;
    int mstCost = 0;

    // Step 2: Process each edge
    for (int i = 0; i < E && mstIndex < V - 1; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);

        // If including this edge does not cause a cycle
        if (x != y) {
            mst[mstIndex++] = edges[i];
            mstCost += edges[i].weight;
            unionSets(subsets, x, y);  // Union the sets
        }
    }

    // Step 3: Print the MST
    printf("Edges in the Minimum Spanning Tree (MST):\n");
    for (int i = 0; i < mstIndex; i++) {
        printf("%d - %d : %d\n", mst[i].src, mst[i].dest, mst[i].weight);
    }
    printf("Total weight of MST: %d\n", mstCost);
}

int main() {
    int V, E;

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    // Input edges (src, dest, weight)
    printf("Enter the edges (src, dest, weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    // Call Kruskal's algorithm to find MST
    kruskalMST(edges, V, E);

    return 0;
}
