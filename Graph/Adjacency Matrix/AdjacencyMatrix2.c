/*
============================================================================
Name        : Directed Weighted Graph using Adjacency Matrix in C
Description : This program demonstrates the representation of a directed
              and weighted graph using an adjacency matrix.

Graph Structure:
----------------------------------------------------------------------------
A directed graph with 4 vertices (0 to 3) and edges:

     (3)
   0 ---> 1
          |
         (4)
          v
   3 <--- 2
      (8)

Functional Overview:
----------------------------------------------------------------------------
1. **add(graph, i, j, w)**
   - Adds a directed edge from vertex `i` to vertex `j` with weight `w`.

2. **display(graph)**
   - Prints the adjacency matrix representation.
   - `INF` (-1) is shown for no direct edge.

Constraints:
----------------------------------------------------------------------------
- `V = 4`: Number of vertices is fixed.
- Edge weights are positive integers.
- Unreachable edges are represented as `INF`.

Time Complexity:
----------------------------------------------------------------------------
- Insertion: O(1)
- Display  : O(V^2)

Space Complexity:
----------------------------------------------------------------------------
- O(V^2) for storing the adjacency matrix.

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>
#define V 4
#define INF -1

// Adds a directed edge from i to j with weight w
void add(int graph[V][V], int i, int j, int w){
    graph[i][j] = w;
}

// Display the adjacency matrix
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
    int graph[V][V];

    // Initialize all cells to INF
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = INF;

    // Add directed edges
    add(graph, 0, 1, 3);
    add(graph, 1, 2, 4);
    add(graph, 2, 3, 8);

    // Display the adjacency matrix
    display(graph);

    return 0;
}
