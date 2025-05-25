#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

// Function to find the vertex with the minimum key value that is not yet included in the MST
int minKey(int key[], int visited[], int V) {
    int min = INT_MAX, minIndex;
    
    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to implement Prim's algorithm to find the MST
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int parent[V];    // Array to store the constructed MST
    int key[V];       // Key values used to pick the minimum weight edge
    int visited[V];   // Visited array to keep track of vertices included in MST

    // Initialize all keys to infinity and visited as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Start from the first vertex
    key[0] = 0;   // Make the key of the first vertex 0 to pick it first
    parent[0] = -1; // First node is the root of the MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the vertex with the minimum key value
        int u = minKey(key, visited, V);

        // Include this vertex in MST
        visited[u] = 1;

        // Update the key value and parent index of the adjacent vertices
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only if there's an edge from u to v
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the constructed MST
    printf("Edge \tWeight\n");
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

int main() {
    int V, E;

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Create a graph represented by an adjacency matrix
    int graph[MAX_VERTICES][MAX_VERTICES];

    // Initialize all edges as 0 (no connection)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    // Input all edges (undirected graph)
    printf("Enter the edges (u v w) where u and v are vertices and w is the weight:\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    // Call Prim's algorithm to find MST
    primMST(graph, V);

    return 0;
}
