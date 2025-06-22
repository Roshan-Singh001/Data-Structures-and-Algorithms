/*
============================================================================
Name        : Undirected Unweighted Graph using Adjacency Matrix in C
Description : This program demonstrates the implementation of an undirected
              and unweighted graph using a fixed-size adjacency matrix.

Graph Structure:
----------------------------------------------------------------------------
Graph with 4 vertices (0 to 3) and edges:
- 0 - 1
      |
- 3 - 2

Functional Overview:
----------------------------------------------------------------------------
1. **add(graph, i, j)**
   - Adds an undirected edge between vertex `i` and vertex `j` by setting
     both `graph[i][j]` and `graph[j][i]` to 1.

2. **display(graph)**
   - Prints the adjacency matrix representation of the graph.

3. **main()**
   - Initializes the matrix with 0s.
   - Adds edges and displays the matrix.

Constraints:
----------------------------------------------------------------------------
- Number of vertices `V` is fixed (4).
- No support for weighted edges or self-loops.
- No dynamic memory used; matrix is statically allocated.

Time Complexity:
----------------------------------------------------------------------------
- Edge Insertion: O(1)
- Display: O(V^2)

Space Complexity:
----------------------------------------------------------------------------
- O(V^2) for storing the matrix.

Applications:
----------------------------------------------------------------------------
- Dense graphs, connectivity check, graph traversal (DFS/BFS), MST, etc.

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>
#define V 4  // Number of vertices

// Function to add an undirected edge between i and j
void add(int graph[V][V], int i, int j){
    graph[i][j] = 1;
    graph[j][i] = 1;
}

// Function to display the adjacency matrix
void display(int graph[V][V]){
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

int main(){
    int graph[V][V] = {0};  // Initialize all values to 0

    // Add edges
    add(graph, 0, 1);
    add(graph, 1, 2);
    add(graph, 2, 3);

    // Display adjacency matrix
    display(graph);

    return 0;
}
