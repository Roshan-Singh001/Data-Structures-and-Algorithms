/*
============================================================================
Name        : Directed Weighted Graph using Adjacency Matrix in C
Description : This program demonstrates the representation of a directed 
              and weighted graph using an adjacency matrix.

Graph Structure:
----------------------------------------------------------------------------
A directed graph with 4 vertices and weighted edges:

       3
    0 ---> 1
           ^
           | 4
           |
    3 ---> 2 
        8

Functional Overview:
----------------------------------------------------------------------------
1. **add(graph, i, j, w)**  
   - Adds a directed edge from vertex `i` to vertex `j` with weight `w`.
   - Fills only `graph[i][j]`, keeps `graph[j][i]` as INF to indicate no reverse edge.

2. **display(graph)**  
   - Displays the matrix with weights.
   - `INF` is used for non-connected edges.

Constraints:
----------------------------------------------------------------------------
- Fixed number of vertices: V = 4
- Uses INF = -1 to represent no connection between two vertices.
- Only directed edges with weights allowed.

Time Complexity:
----------------------------------------------------------------------------
- Insertion: O(1)
- Display  : O(V^2)

Space Complexity:
----------------------------------------------------------------------------
- O(V^2) for the adjacency matrix

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>
#define V 4
#define INF -1

// Adds a directed edge from i to j with weight w
void add(int graph[V][V], int i, int j, int w){
    graph[i][j] = w;
    graph[j][i] = INF;  // Explicitly mark reverse edge as disconnected
}

// Displays the weighted adjacency matrix
void display(int graph[V][V]){
    printf("Adjacency Matrix (Directed & Weighted):\n");
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (graph[i][j] == INF) printf(" INF ");
            else printf("  %d  ", graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    // Initialize graph with all edges as INF (disconnected)
    int graph[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = INF;

    // Adding directed edges with weights
    add(graph, 0, 1, 3);
    add(graph, 2, 1, 4);
    add(graph, 2, 3, 8);

    // Display graph
    display(graph);

    return 0;
}
