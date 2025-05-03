# Graphs

## Introduction to graphs

### Edges and Vertices/Nodes
![Edges and Vertices](https://upload.wikimedia.org/wikipedia/commons/2/2f/Small_Network.png)

### Types of graphs


| Type | Edge Type | Direction | Notation |
|------|-----------|-----------|----------|
| Undirected Graph | Undirected Edges | Bidirectional | $A - B$|
| Directed Graph | Directed Edges | Unidirectional | $A \to B$ |


![Types of Graphs](https://study.com/cimages/multimages/16/3161f86d-d02f-4bc4-ab9d-9e654800ad60_graphs.png)

> A graph can be an open or an enclosed structure.

### Cycles in a graph

- A graph is cyclic if it has at least one cycle in it; otherwise, it is acyclic.
    - $DAG$ is a $\text{directed acyclic graph}$.

### Path in a graph

- Contains a lot of nodes and vertices and each of them are reachable.
    - A node cannot appeat twice in a path it can only appear once.
    - The adjacent nodes in a path must have an edge between them.

### Degrees in a graph

| Graph Type | Term | Definition | Formula/Properties |
|------------|------|------------|-------------------|
| Undirected | Degree | Number of edges connected to a node | - |
| Undirected | Total degree | Sum of all degrees | 2 × (number of edges) |
| Directed | Indegree | Number of incoming edges to a node | - |
| Directed | Outdegree | Number of outgoing edges from a node | - |
| Directed | Total degree | Sum of all degrees | Sum of indegrees = Sum of outdegrees |

> Note: In undirected graphs, each edge contributes to 2 degrees (one for each endpoint)


### Edge weights
- If the weights are not assigned we assume unit weights to all edges.

### Representation of a Graph in C++

- $N$ - number of nodes
- $M$ - number of edges
- Next $M$ lines contains pairs of nodes (we assume edge b/w them)

> $M$ $\leq$ $N \choose 2$

- How to store a graph?
    - 1. Adjacency matrix - ```adj[N + 1][N + 1] = {0}```
        - For all the $M$ edges we mark, ```adj[i][j] = 1 ``` and ```adj[j][i] = 1(omit in case of directed graph)```
        - Space: $O(N^2)$
    - 2. Adjacency list - ```vector<int> adj[n + 1]```(Array of vectors). Initially, at every index `{0, 1, 2, ... n}` in `adj` contains an empty vector.
        - For all $M$ edges we mark, `adj[i].emplace_back(j)` and `adj[j].emplace_back(i)(omit incase of directed graph)`.
        - Space: $O(2M)(undirected)$,  $O(M) (directed)$
- How to store a weighted graph?
    - 1. Adjacency matrix - ```adj[N + 1][N + 1] = {0}```
        - For all the $M$ edges we mark, ```adj[i][j] = w ``` and ```adj[j][i] = w(omit in case of directed graph)```
        - Space: $O(N^2)$
    - 2. Adjacency list - ```vector<pair<int, int>> adj[n + 1]```(Array of vectors). Initially, at every index `{0, 1, 2, ... n}` in `adj` contains an empty vector.
        - For all $M$ edges we mark, `adj[i].emplace_back({j, w})` and `adj[j].emplace_back({i, w})(omit incase of directed graph)`.
        - Space: $O(4M)(undirected)$,  $O(2M) (directed)$
    
### Connected components in a Graph
- A connected component is a group of vertices in an undirected graph that are connected to each other by paths.
    - Due to this, every traversal algorithm will always keeps track of a `visited_array[N + 1]`, loop over `1 ... N` the visited array and if the node is not visited we tarverse over that connected component corresponding to that node and mark every node in that corresponding component as visited.

> Maximum no of connected components in a graph $\leq$ $N$ 

- Practice Problem:
    -  [Connected Components in an Undirected Graph](https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1) ($❌$ **Unsolved**)

### BFS on a graph 
- Level-wise traversal of the graph
- Depending on the starting node the BFS order changes
- Nodes at equal distance from the starting node are placed at the same level (can be in any order)
- Uses a queue data structure and visited array
- Time Complexity: O(V + E), where V is vertices and E is edges
- Space Complexity: O(V) for visited array + O(V) for queue

#### Algorithm
1. Push starting node to queue and mark it visited
2. While queue is not empty:
   - Pop front node
   - Add all unvisited adjacent nodes to queue
   - Mark them as visited

#### Key Points
- Visits all nodes at current level before moving to next level
- Useful for:
  - Finding shortest path in unweighted graph
  - Level-wise traversal
  - Finding connected components
  - Testing bipartiteness

#### Practice Problem
- [BFS of graph](https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?selectedLang=cpp) ($✅$ **Solved**)

### DFS on a graph
- Depth First Search (DFS) explores as far as possible along each branch before backtracking
- Uses recursion or a stack data structure
- Marks nodes as visited to avoid cycles
- Time Complexity: O(V + E), where V is vertices and E is edges
- Space Complexity: O(V) for visited array + O(V) for recursion stack

#### Algorithm
1. Mark current node as visited
2. Recursively visit all unvisited adjacent nodes
3. Backtrack when no unvisited adjacent nodes remain


#### Key Points
- Order of traversal depends on how adjacent nodes are stored
- Useful for:
  - Finding connected components
  - Detecting cycles
  - Topological sorting
  - Path finding

#### Practice Problem
- [DFS of Graph](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1) ($✅$ **Solved**)    

### Problems

| No. | Problem | Status | Solution |
|-----|---------|--------|----------|
| 1 | [Number of Provinces](https://leetcode.com/problems/number-of-provinces/) | $✅$ Solved | [Solution](https://leetcode.com/problems/number-of-provinces/solutions/6709888/beats-100-c-clean-code-all-3-approaches-bjhkf/) |