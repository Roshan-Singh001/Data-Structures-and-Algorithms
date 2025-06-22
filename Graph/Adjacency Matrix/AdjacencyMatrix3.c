/*
============================================================================
Name        : Directed Unweighted Graph using Adjacency Matrix in C
Description : This program demonstrates the representation of a directed 
              and unweighted graph using an adjacency matrix.

Graph Structure:
----------------------------------------------------------------------------
A directed graph with 4 vertices (0 to 3) and edges:

    0 → 1
         ↑
         |
    3 ← 2

Functional Overview:
----------------------------------------------------------------------------
1. **add(graph, i, j)**
   - Adds a directed edge from vertex `i` to vertex `j`.

2. **display(graph)**
   - Displays the adjacency matrix representation.
   - 1 indicates the presence of an edge from i to j.
   - 0 indicates no edge.

Constraints:
----------------------------------------------------------------------------
- Number of vertices `V = 4` (fixed).
- Only directed edges (i → j) are added; reverse edges are not assumed.
- Graph is unweighted.

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

// Adds a directed edge from i to j
void add(int graph[V][V], int i, int j){
    graph[i][j] = 1;
}

// Prints the adjacency matrix
void display(int graph[V][V]){
    printf("Adjacency Matrix (Directed & Unweighted):\n");
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

int main(){
    int graph[V][V] = {0}; // Initialize all entries to 0

    add(graph, 0, 1);
    add(graph, 2, 1);
    add(graph, 2, 3);

    display(graph);

    return 0;
}
