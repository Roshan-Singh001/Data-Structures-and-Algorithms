/*
============================================================================
Name        : Adjacency List Representation of an Undirected Graph in C
Description : This C program demonstrates how to represent an undirected and
              unweighted graph using an adjacency list. It supports:
              - Creation of nodes using dynamic memory allocation.
              - Bidirectional edge insertion for an undirected graph.
              - Displaying the adjacency list for each vertex.

Graph Structure:
----------------------------------------------------------------------------
Undirected Graph with 4 vertices (0 to 3)

Graph Representation:
    0 - 1
    |   |
    3 - 2

Edges:
    (0,1), (0,3), (1,2), (2,3)

Functional Overview:
----------------------------------------------------------------------------
1. **Struct Node**
   - Represents an adjacency list node with:
     - `dest`: Destination vertex.
     - `next`: Pointer to the next node in the adjacency list.

2. **graph[V]**
   - An array of pointers, where each index `i` points to the head of the 
     adjacency list of vertex `i`.

3. **add(src, dest)**
   - Inserts an edge from `src` to `dest` and vice versa (since the graph is undirected).
   - Dynamically allocates memory for each edge node.

4. **display()**
   - Prints the adjacency list for each vertex.

Constraints:
----------------------------------------------------------------------------
- Graph is undirected.
- Maximum number of vertices is defined by `#define V 4`.

Time Complexity:
----------------------------------------------------------------------------
- Edge Insertion: O(1)
- Display: O(V + E), where E is the number of edges.

Space Complexity:
----------------------------------------------------------------------------
- O(V + E) due to adjacency list representation.

Advantages of Adjacency List:
----------------------------------------------------------------------------
- Efficient for sparse graphs.
- Saves space compared to adjacency matrix.
- Easy to traverse neighbors of a vertex.

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define V 4  // Total number of vertices

// Structure to represent an adjacency list node
typedef struct Node {
    int dest;             // Destination vertex
    struct Node *next;    // Pointer to next node
} Node;

Node *graph[V];  // Array of adjacency list heads

// Function to add an edge between src and dest
void add(int src, int dest) {
    // Add edge from src to dest
    Node *new = (Node *)malloc(sizeof(Node));
    new->dest = dest;
    new->next = graph[src];
    graph[src] = new;

    // Since undirected, add edge from dest to src
    new = (Node *)malloc(sizeof(Node));
    new->dest = src;
    new->next = graph[dest];
    graph[dest] = new;
}

// Function to display the adjacency list
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
    // Initialize all adjacency list heads to NULL
    for (int i = 0; i < V; i++) graph[i] = NULL;

    // Adding edges as per the given graph
    add(0, 1);
    add(0, 3);
    add(1, 2);
    add(2, 3);

    // Display the graph
    display();

    return 0;
}
