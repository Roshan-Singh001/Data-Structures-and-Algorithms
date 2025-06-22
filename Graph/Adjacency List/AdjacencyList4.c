/*
============================================================================
Name        : Directed Weighted Graph using Adjacency List in C
Description : This program creates a directed and weighted graph using 
              adjacency lists. Each vertex points to a linked list of 
              destination vertices with associated edge weights.

Graph Structure:
----------------------------------------------------------------------------
Graph with 4 vertices (0 to 3) and edges:
- 0 → 1 (weight 3)
- 3 → 0 (weight 4)
- 2 → 1 (weight 2)
- 2 → 3 (weight 8)

Visual Representation:
        3
    0 ----> 1
    ^       ^
   4|       |2
    |       |
    3 <---- 2
        8

Functional Overview:
----------------------------------------------------------------------------
1. **Struct Node**
   - Represents each edge with destination and weight.
   - Each vertex in the graph has a linked list of outgoing edges.

2. **graph[V]**
   - Array of pointers to the head of each vertex’s adjacency list.

3. **add(src, dest, weight)**
   - Adds a directed edge from `src` to `dest` with specified weight.

4. **display()**
   - Prints the adjacency list of each vertex including edge weights.

Constraints:
----------------------------------------------------------------------------
- Graph is **directed** and **weighted**.
- Number of vertices (`V`) is fixed at 4.
- No duplicate edge handling.

Time Complexity:
----------------------------------------------------------------------------
- Edge Insertion: O(1)
- Display: O(V + E), where V = vertices, E = edges

Space Complexity:
----------------------------------------------------------------------------
- O(V + E) for adjacency list nodes

Applications:
----------------------------------------------------------------------------
- Routing networks, dependency graphs, shortest path algorithms, etc.

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define V 4  // Total number of vertices

// Structure for adjacency list node
typedef struct Node {
    int dest;            // Destination vertex
    int weight;          // Edge weight
    struct Node *next;   // Pointer to next node
} Node;

// Adjacency list for each vertex
Node *graph[V];

// Function to add an edge from src to dest with weight w
void add(int src, int dest, int w) {
    Node *new = (Node *) malloc(sizeof(Node));
    new->dest = dest;
    new->weight = w;
    new->next = graph[src];  // Insert at the beginning
    graph[src] = new;
}

// Function to display the adjacency list of the graph
void display() {
    for (int i = 0; i < V; i++) {
        Node* ptr = graph[i];
        printf("Vertex %d:", i);
        while (ptr) {
            printf(" -> %d(%dw)", ptr->dest, ptr->weight);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    // Initialize all vertex lists as empty
    for (int i = 0; i < V; i++) graph[i] = NULL;

    // Add directed edges with weights
    add(0, 1, 3);
    add(3, 0, 4);
    add(2, 1, 2);
    add(2, 3, 8);

    // Display the graph
    display();

    return 0;
}
