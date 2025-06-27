/*
============================================================================
Name        : Breadth-First Search (BFS) using Adjacency List in C++
Description : This program performs BFS traversal on an undirected graph 
              represented via adjacency lists, which is efficient for 
              sparse graphs.

Functional Requirements:
----------------------------------------------------------------------------
1. Represent the graph using a vector of vectors (adjacency list).
2. Add edges between pairs of vertices (bidirectional).
3. Traverse the graph using BFS from a given source node.
4. Use a queue to manage the frontier.
5. Use a visited array to track explored nodes.
6. Print the BFS traversal order.

Intuition:
----------------------------------------------------------------------------
- Enqueue the source node, mark it visited.
- While the queue is not empty:
   - Dequeue a node.
   - Enqueue all unvisited adjacent nodes.
- Record and print the order of traversal.

Edge Cases:
----------------------------------------------------------------------------
- Handles disconnected components if BFS is called repeatedly.
- Prevents revisiting nodes using visited[].
- Assumes a simple undirected graph (add both ways).

Time Complexity:
----------------------------------------------------------------------------
- O(V + E), where V is the number of vertices and E is the number of edges.

Space Complexity:
----------------------------------------------------------------------------
- O(V) for visited array and queue.
- O(V + E) for adjacency list storage.

Advantages over Adjacency Matrix:
----------------------------------------------------------------------------
- Efficient in memory and traversal for sparse graphs.

Author      : Roshan Singh
============================================================================
*/

#include <iostream>
#include <queue>
#include <vector>
#define V 4
using namespace std;

// Adjacency List representation
vector<vector<int>> graph(V);

// Adds an undirected edge between two nodes
void add(int src, int dest) {
    graph[src].push_back(dest);
    graph[dest].push_back(src);
}

// Breadth-First Search (BFS)
void bfs(int source){
    queue<int> q;
    vector<int> res;
    int visited[V] = {0};

    q.push(source);
    visited[source] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        res.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    // Print BFS result
    cout << "BFS Traversal starting from node " << source << ": ";
    for (int node : res) cout << node << " ";
    cout << endl;
}

int main()
{
    add(0, 1);
    add(0, 3);
    add(1, 2);
    add(2, 3);

    bfs(0);
    return 0;
}
