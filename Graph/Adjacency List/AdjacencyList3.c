/*
============================================================================
Name        : Directed Unweighted Graph using Adjacency List in C
Description : This program demonstrates the creation of a directed and 
              unweighted graph using an adjacency list representation.
              It allows adding directed edges and displaying the graph.

Graph Representation:
----------------------------------------------------------------------------
Given 4 vertices (0 to 3), and edges:
- 0 → 1
- 3 → 0
- 2 → 1
- 2 → 3

Graphically:
        0 → 1
        ↑    ↑
        |    |
        3 ← 2

Functional Overview:
----------------------------------------------------------------------------
1. **Struct Node**
   - Represents each adjacent node in the list.
   - Contains destination (`dest`) and a `next` pointer.

2. **graph[V]**
   - An array of pointers, one for each vertex, representing the head of its adjacency list.

3. **add(src, dest)**
   - Adds a directed edge from `src` to `dest`.

4. **display()**
   - Prints the adjacency list of each vertex, indicating its outgoing edges.

Constraints:
----------------------------------------------------------------------------
- Graph is **directed**: Edge from A to B does not imply B to A.
- Graph is **unweighted**: No weights are stored with edges.
- Number of vertices (`V`) is defined as 4.

Time Complexity:
----------------------------------------------------------------------------
- Edge Insertion: O(1)
- Display: O(V + E) where E is the number of edges

Space Complexity:
----------------------------------------------------------------------------
- O(V + E) for adjacency list storage

Applications:
----------------------------------------------------------------------------
- Used in modeling one-way streets, dependency graphs, task scheduling, etc.

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define V 4  // Number of vertices

// Structure to represent an adjacency list node
typedef struct Node {
    int dest;            // Destination vertex
    struct Node *next;   // Pointer to the next adjacent node
} Node;

Node *graph[V];  // Array of adjacency list heads

// Function to add a directed edge from src to dest
void add(int src, int dest) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->dest = dest;
    new->next = graph[src];  // Insert at the beginning
    graph[src] = new;
}

// Function to display the adjacency list of the graph
void display() {
    for (int i = 0; i < V; i++) {
        Node *ptr = graph[i];
        printf("Vertex %d:", i);
        while (ptr) {
            printf(" -> %d", ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    // Initialize adjacency lists as empty
    for (int i = 0; i < V; i++) graph[i] = NULL;

    // Add directed edges
    add(0, 1);
    add(3, 0);
    add(2, 1);
    add(2, 3);

    // Display graph
    display();

    return 0;
}
