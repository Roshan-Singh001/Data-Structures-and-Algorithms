# Graph Data Structure - Complete Guide

## Table of Contents
- [Definition](#definition)
- [Basic Terminology](#basic-terminology)
- [Types of Graphs](#types-of-graphs)
- [Graph Representations](#graph-representations)
- [Basic Operations](#basic-operations)
- [Graph Traversal Algorithms](#graph-traversal-algorithms)
- [Shortest Path Algorithms](#shortest-path-algorithms)
- [Minimum Spanning Tree](#minimum-spanning-tree)
- [Advantages](#advantages)
- [Disadvantages](#disadvantages)
- [Applications](#applications)
- [Time and Space Complexity](#time-and-space-complexity)

## Definition

A **Graph** is a non-linear data structure consisting of a finite set of **vertices** (also called **nodes**) and a set of **edges** that connect pairs of vertices. Graphs are used to represent relationships between objects and are fundamental in solving many real-world problems.

**Mathematical Definition:**
```
G = (V, E)
where:
- V is a finite set of vertices
- E is a finite set of edges
- Each edge connects two vertices
```

**Visual Representation:**
```
    A ---- B
    |      |
    |      |
    C ---- D
```

## Basic Terminology

### Vertices and Edges
- **Vertex (Node)**: A fundamental unit representing an entity
- **Edge**: A connection between two vertices
- **Adjacent Vertices**: Vertices connected by an edge
- **Incident Edge**: An edge connected to a vertex

### Degree
- **Degree**: Number of edges connected to a vertex
- **In-degree**: Number of incoming edges (directed graphs)
- **Out-degree**: Number of outgoing edges (directed graphs)

### Path and Connectivity
- **Path**: A sequence of vertices connected by edges
- **Simple Path**: Path with no repeated vertices
- **Cycle**: A path that starts and ends at the same vertex
- **Connected Graph**: Every vertex is reachable from every other vertex
- **Disconnected Graph**: Contains isolated components

### Distance
- **Distance**: Minimum number of edges between two vertices
- **Diameter**: Maximum distance between any two vertices
- **Radius**: Minimum eccentricity among all vertices

## Types of Graphs

### 1. **Directed vs Undirected Graphs**

#### Undirected Graph
```
A ---- B
|      |
|      |
C ---- D
```
- Edges have no direction
- If (A,B) is an edge, then (B,A) is also valid
- Represented as unordered pairs: {A,B}

#### Directed Graph (Digraph)
```
A ---> B
^      |
|      v
C <--- D
```
- Edges have direction
- (A,B) ≠ (B,A)
- Represented as ordered pairs: (A,B)

### 2. **Weighted vs Unweighted Graphs**

#### Unweighted Graph
```
A ---- B
|      |
C ---- D
```
- All edges have equal weight (usually 1)
- Focus on connectivity rather than cost

#### Weighted Graph
```
A --5-- B
|       |
3       2
|       |
C --4-- D
```
- Each edge has an associated weight/cost
- Used for optimization problems

### 3. **Special Types**

#### Complete Graph
- Every vertex is connected to every other vertex
- n vertices have n(n-1)/2 edges (undirected)

#### Bipartite Graph
- Vertices can be divided into two disjoint sets
- Edges only connect vertices from different sets

#### Tree
- Connected acyclic graph
- n vertices have exactly n-1 edges

#### Forest
- Collection of disjoint trees
- Acyclic but may be disconnected

#### Planar Graph
- Can be drawn on a plane without edge crossings

#### Regular Graph
- All vertices have the same degree

## Graph Representations

### 1. **Adjacency Matrix**

A 2D array where `matrix[i][j]` indicates if there's an edge between vertex i and vertex j.

```
Graph:  A--B    Adjacency Matrix:
        |  |         A B C D
        C--D      A [0 1 1 0]
                  B [1 0 0 1]
                  C [1 0 0 1]
                  D [0 1 1 0]
```

**Advantages:**
- O(1) edge lookup
- Simple to implement
- Good for dense graphs

**Disadvantages:**
- O(V²) space complexity
- Inefficient for sparse graphs

### 2. **Adjacency List**

An array of lists where each list contains the neighbors of a vertex.

```
Graph:  A--B    Adjacency List:
        |  |    A: [B, C]
        C--D    B: [A, D]
               C: [A, D]
               D: [B, C]
```

**Advantages:**
- O(V + E) space complexity
- Efficient for sparse graphs
- Easy to iterate over neighbors

**Disadvantages:**
- O(V) edge lookup in worst case
- Slightly more complex implementation

### 3. **Edge List**

A list of all edges in the graph.

```
Graph:  A--B    Edge List:
        |  |    [(A,B), (A,C), (B,D), (C,D)]
        C--D
```

**Advantages:**
- Simple representation
- Efficient for edge-centric algorithms
- Compact for sparse graphs

**Disadvantages:**
- Inefficient for vertex-centric operations
- O(E) time to find neighbors

### 4. **Incidence Matrix**

A matrix where rows represent vertices and columns represent edges.

```
Graph:  A--B    Incidence Matrix:
        |  |         e1 e2 e3 e4
        C--D      A [ 1  1  0  0]
                  B [ 1  0  1  0]
                  C [ 0  1  0  1]
                  D [ 0  0  1  1]
```

## Basic Operations

### 1. **Add Vertex**
- Add a new vertex to the graph
- **Time Complexity**: O(1) for adjacency list, O(V²) for adjacency matrix

### 2. **Add Edge**
- Connect two vertices with an edge
- **Time Complexity**: O(1) for both representations

### 3. **Remove Vertex**
- Remove a vertex and all its incident edges
- **Time Complexity**: O(V + E) for adjacency list, O(V²) for adjacency matrix

### 4. **Remove Edge**
- Remove connection between two vertices
- **Time Complexity**: O(V) for adjacency list, O(1) for adjacency matrix

### 5. **Check Edge**
- Determine if an edge exists between two vertices
- **Time Complexity**: O(V) for adjacency list, O(1) for adjacency matrix

### 6. **Get Neighbors**
- Find all vertices adjacent to a given vertex
- **Time Complexity**: O(V) for adjacency matrix, O(degree) for adjacency list

## Graph Traversal Algorithms

### 1. **Depth-First Search (DFS)**

Explores as far as possible along each branch before backtracking.


**Time Complexity**: O(V + E)
**Space Complexity**: O(V)
**Applications**: Cycle detection, topological sorting, pathfinding

### 2. **Breadth-First Search (BFS)**

Explores all vertices at the current depth before moving to vertices at the next depth.

**Time Complexity**: O(V + E)
**Space Complexity**: O(V)
**Applications**: Shortest path in unweighted graphs, level-order processing

## Shortest Path Algorithms

### 1. **Dijkstra's Algorithm**

Finds shortest paths from a source vertex to all other vertices in weighted graphs with non-negative edge weights.

**Time Complexity**: O((V + E) log V)
**Space Complexity**: O(V)

### 2. **Bellman-Ford Algorithm**

Finds shortest paths from a source vertex, can handle negative edge weights and detect negative cycles.


**Time Complexity**: O(VE)
**Space Complexity**: O(V)

### 3. **Floyd-Warshall Algorithm**

Finds shortest paths between all pairs of vertices.

**Time Complexity**: O(V³)
**Space Complexity**: O(V²)

## Minimum Spanning Tree

### 1. **Kruskal's Algorithm**

Finds minimum spanning tree by sorting edges and using Union-Find.

**Time Complexity**: O(E log E)
**Space Complexity**: O(V)

### 2. **Prim's Algorithm**

Finds minimum spanning tree by growing tree from a starting vertex.

**Time Complexity**: O(E log V)
**Space Complexity**: O(V)

## Advantages

### 1. **Relationship Modeling**
- Naturally represents relationships between entities
- Flexible structure for complex connections
- Can model both symmetric and asymmetric relationships

### 2. **Algorithm Rich**
- Extensive collection of well-studied algorithms
- Solutions for optimization problems
- Efficient pathfinding and connectivity analysis

### 3. **Versatility**
- Applicable to diverse problem domains
- Can represent both physical and abstract relationships
- Supports weighted and unweighted scenarios

### 4. **Visual Representation**
- Easy to visualize and understand
- Intuitive for problem analysis
- Helpful for debugging and explanation

## Disadvantages

### 1. **Space Complexity**
- Can require significant memory for dense graphs
- Adjacency matrix: O(V²) space
- May have memory overhead for sparse graphs

### 2. **Algorithm Complexity**
- Many graph problems are NP-complete
- Some algorithms have high time complexity
- May require approximation for large instances

### 3. **Dynamic Updates**
- Expensive to modify graph structure
- Some algorithms need recomputation after changes
- Maintaining consistency during updates

### 4. **Implementation Complexity**
- More complex than linear data structures
- Multiple representation choices
- Debugging can be challenging

## Applications

### 1. **Social Networks**
- **Friend Connections**: Users as vertices, friendships as edges
- **Influence Analysis**: Measuring information spread
- **Community Detection**: Finding groups of similar users
- **Recommendation Systems**: Friend suggestions, content recommendations

### 2. **Transportation and Navigation**
- **Road Networks**: Intersections as vertices, roads as edges
- **GPS Navigation**: Shortest path algorithms
- **Public Transportation**: Route optimization
- **Flight Networks**: Airports as vertices, flights as edges

### 3. **Computer Networks**
- **Internet Topology**: Routers and switches as vertices
- **Network Routing**: Finding optimal paths for data
- **Network Reliability**: Analyzing connectivity
- **Load Balancing**: Distributing network traffic

### 4. **Web and Internet**
- **Web Page Linking**: PageRank algorithm
- **URL Structure**: Website hierarchy
- **Search Engine Optimization**: Link analysis
- **Web Crawling**: Traversing web pages

### 5. **Biology and Bioinformatics**
- **Protein Interaction Networks**: Protein relationships
- **Gene Regulatory Networks**: Gene expression relationships
- **Phylogenetic Trees**: Evolutionary relationships
- **Metabolic Pathways**: Biochemical reactions

### 6. **Computer Science**
- **Dependency Resolution**: Package managers, build systems
- **Compiler Design**: Control flow graphs, call graphs
- **Database Systems**: Query optimization, transaction dependencies
- **Operating Systems**: Process scheduling, resource allocation

### 7. **Game Development**
- **Game Maps**: Pathfinding in games
- **AI Decision Making**: State machines
- **Quest Systems**: Dependency tracking
- **Level Design**: Connectivity analysis

### 8. **Finance and Economics**
- **Trading Networks**: Market relationships
- **Risk Analysis**: Portfolio dependencies
- **Supply Chain**: Vendor and supplier relationships
- **Economic Modeling**: Market interactions

## Time and Space Complexity

### Representation Comparison

| Operation | Adjacency List | Adjacency Matrix | Edge List |
|-----------|----------------|------------------|-----------|
| Add Vertex | O(1) | O(V²) | O(1) |
| Add Edge | O(1) | O(1) | O(1) |
| Remove Vertex | O(V + E) | O(V²) | O(E) |
| Remove Edge | O(V) | O(1) | O(E) |
| Check Edge | O(V) | O(1) | O(E) |
| Space | O(V + E) | O(V²) | O(E) |

### Algorithm Complexities

| Algorithm | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| DFS/BFS | O(V + E) | O(V) |
| Dijkstra | O((V + E) log V) | O(V) |
| Bellman-Ford | O(VE) | O(V) |
| Floyd-Warshall | O(V³) | O(V²) |
| Kruskal's MST | O(E log E) | O(V) |
| Prim's MST | O(E log V) | O(V) |
| Topological Sort | O(V + E) | O(V) |

## Code Author

**Roshan Singh**