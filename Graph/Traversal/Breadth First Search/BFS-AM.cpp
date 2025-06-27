/*
============================================================================
Name        : Breadth-First Search (BFS) using Adjacency Matrix in C++
Description : This program implements the BFS traversal of an undirected 
              graph using an adjacency matrix. BFS explores all neighbors 
              at the current depth before moving on to nodes at the next depth level.

Functional Requirements:
----------------------------------------------------------------------------
1. Represent the graph using a 2D adjacency matrix of size V x V.
2. Traverse the graph using BFS starting from a given source node.
3. Use a queue to manage the exploration frontier.
4. Maintain a `visited` array to avoid revisiting nodes.
5. Print the traversal order.

Intuition:
----------------------------------------------------------------------------
- Start from the source node, mark it visited and enqueue it.
- Dequeue a node, process it, and enqueue all unvisited adjacent nodes.
- Continue until the queue becomes empty.

Edge Cases:
----------------------------------------------------------------------------
- Handles disconnected graphs (if extended for all components).
- Prevents infinite loops via visited array.
- Works for undirected graphs (1s mirrored across diagonal).
- Can be extended to weighted/directed graphs with modifications.

Time Complexity:
----------------------------------------------------------------------------
- O(V^2) for adjacency matrix representation.
  (Checking all neighbors for each vertex)

Space Complexity:
----------------------------------------------------------------------------
- O(V) for visited array and queue.

Limitations:
----------------------------------------------------------------------------
- Adjacency matrix uses O(V^2) space; not efficient for sparse graphs.

Author      : Roshan Singh
============================================================================
*/

#include <iostream>
#include <queue>
#include <vector>
#define V 7
using namespace std;

// BFS traversal using adjacency matrix
void bfs(int graph[V][V], int source){
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

        for (int i = 0; i < V; i++)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    // Print BFS result
    cout << "BFS Traversal starting from node " << source << ": ";
    for (int i = 0; i < res.size(); i++) cout << res.at(i) << " ";
    cout << endl;
}

int main()
{
    int graph[V][V] = {
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,0,0,1,1,0,0},
        {1,1,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    bfs(graph, 0);

    return 0;
}
