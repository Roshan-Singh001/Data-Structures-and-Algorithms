/*
============================================================================
Name        : Weighted Undirected Graph using Adjacency List in C
Description : This program demonstrates the implementation of an undirected,
              weighted graph using an adjacency list. It allows:
              - Adding weighted edges between vertices.
              - Displaying the graph with vertex-to-vertex weight info.

Graph Layout:
----------------------------------------------------------------------------
Graph with 4 vertices (0 to 3) and weighted edges:

         3
      0 ---- 1
     /        \
   4|          |2
     \        /
      3 ---- 2
         8

Functional Requirements:
----------------------------------------------------------------------------
1. **Struct Node**
   - Represents an adjacency list node.
   - Stores:
     - `dest`: Destination vertex.
     - `weight`: Weight of the edge.
     - `next`: Pointer to the next node.

2. **graph[V]**
   - Array of pointers (head of linked lists), one for each vertex.

3. **add(src, dest, w)**
   - Adds an undirected edge with weight `w` between `src` and `dest`.

4. **display()**
   - Prints adjacency list of each vertex, showing connected vertices and weights.

Constraints:
----------------------------------------------------------------------------
- Maximum vertices defined by `#define V 4`.
- Graph is undirected and weighted.
- Edges are stored bidirectionally.

Time Complexity:
----------------------------------------------------------------------------
- Edge Insertion: O(1)
- Display: O(V + E) where E is the number of edges

Space Complexity:
----------------------------------------------------------------------------
- O(V + E) for adjacency list storage

Applications:
----------------------------------------------------------------------------
- Network routing (with cost)
- Shortest path algorithms (Dijkstra, Prim’s, Kruskal’s)
- Maps and transportation systems

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define V 4  // Total number of vertices

// Structure to represent a node in the adjacency list
typedef struct Node {
    int dest;           // Destination vertex
    int weight;         // Weight of the edge
    struct Node *next;  // Pointer to next node
} Node;

Node *graph[V];  // Array of adjacency list heads

// Function to add an undirected edge with weight
void add(int src, int dest, int w) {
    // Add from src to dest
    Node *new = (Node *)malloc(sizeof(Node));
    new->dest = dest;
    new->weight = w;
    new->next = graph[src];
    graph[src] = new;

    // Since undirected, add from dest to src
    new = (Node *)malloc(sizeof(Node));
    new->dest = src;
    new->weight = w;
    new->next = graph[dest];
    graph[dest] = new;
}

// Function to display the adjacency list
void display() {
    for (int i = 0; i < V; i++) {
        Node *ptr = graph[i];
        printf("Vertex %d:", i);
        while (ptr) {
            printf(" -> %d-%dw", ptr->dest, ptr->weight);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    // Initialize all heads to NULL
    for (int i = 0; i < V; i++) graph[i] = NULL;

    // Add edges with weights
    add(0, 1, 3);
    add(0, 3, 4);
    add(1, 2, 2);
    add(2, 3, 8);

    // Display graph
    display();

    return 0;
}
