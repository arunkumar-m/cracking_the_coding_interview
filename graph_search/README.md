# Generic Graph Search

## Goals

- Find everything findable from a given start vertex.
- Don't explore anything twice. Efficiency: O(m + n)

## Generic Algorithm

Generic Algorithm (given graph G, vertex S)

- initially S explored, all other vertices unexplored
- while possible:
  - choose an edge (u, v) with u explored and v unexplored
  - mark v explored

Claim: at end of the algorithm, v explored <=> G has a path from s to v.
(G undirected or directed)

Proof: 

(=>) easy induction
(<=) by contradiction

## BFS vs. DFS

### Breadth First Search (BFS)

- explore nodes in "layers"
- can complete shortest paths
- can compute connected components of a undirected graph

O(m + n) time using a queue

### Depth First Search (DFS)

- explore aggressively like a maze, backtrack only when necessary
- compute topological ordering of directed acyclic graph
- compute conneced components in directed graphs

O(m + n) time using a stack

## BFS

### Overview and Examples

- explore nodes in "layers"
- can compute shortest paths
- can compute connected components of a undirected graph (linear time)

### The Code

    BFS(graph G, start vertex S)
    [all nodes initially unexplored]
    - mark S as explored
    - let Q = queue data structure (FIFO), intialized with S
    - while Q is not empty:
      - remove the first node of Q, call it v
      - for each edge (v, w):
        - if w unexplored
          - mark w as explored
          - add w to Q (at the end)

### Claims

Claim #1: At the end of BFS, v explored <=> G has a path from s to v.

Reason: special case of the generic algorithm

Claim #2: Running time of main while loop = O(ns + ms), where ns =#nodes
reachable from S, ms = #edges reachable from S

## BFS and Shortest Paths

Goal: Compute dist(v), the fewest # of edges on a path from s to v.

### Extra Code

    - initiate dist(v) = 0 if v = s +inf otherwise
    - when considering edge (v, w）：
      - if w unexplored, then set dist(w) = dist(v) + 1

### Claims

Claim: At termination, dist(v) = i <=> v in ith layer (i.e. <=> shortest
s-v path has i edges).

Proof Idea: Every layer-i node w is added to Q by a layer-(i-1) node v
via the edge (v, w).

## BFS and Undirected Connectivity

Let G = (V, E) be an undirected graph.

Connected components = the "pieces" of G.

Formal definition: equivalent classes of the relation u ~ v <=> exists u-v path in G.

Goal: compute all connected components.

Why?
- Check if network is disconnected.
- Graph visualization.
- Clustering.

### Connected Components via BFS

To compute all components: (undirected case)

    - all nodes unexplored
      [assume labelled 1 to n]
    - for i = 1 to n
      - if i not yet explored
        - BFS(G, i)

Note: finds every connected component.

Running time: O(m + n)

## DFS

### Overview and Example

Depth-First Search (DFS): explore aggressively (only backtrack when
necessary)

- also compute a topological ordering of a directed acyclic graph
- and strongly connected components of directed graphs

Run Time: O(m + n)

### Code

Exercise: mimic BFS code, use a stack instead of a queue [+ minor other
modification]

Recursion version:
    DFS (graph G, start vertex s)
      - Mark S as explored
      - for each edge (s, v):
        - if v unexplored:
          - DFS (G, v)

### Basic DFS Properties

Claim #1: At end of the algorithm, v marked as explored <=> exists path
from s to v in G.

Reason: Particular instantiation of generic search procedure.

Claim #2: Running time is O(ns + ms) where ns is the number of nodes
reachable from s and ms is the number of edges reachable from s.

Reason: Look at each node in connected component of s at most once, each
edge at most twice.

## Topological Ordering

Definition: A topological ordering of a directed graph G is a labelling
f of G's nodes such that:
- the f(v)'s are the set {1, 2, ... , n}
- (u, v) in G => f(u) < f(v)

### Who cares about topological ordering?

Motivation: Sequence tasks while respecting all precedence constraints

Note: G has directed cycle => no topological ordering

Theorem: no directed cycle => can compute topological ordering in O(m +
n) time.

### Straightforward Solution

Note: every directed acyclic graph has a sink vertex.

Reason: if ont, can keep following outgoing arcs to produce a directed
cycle.

To compute topological ordering:

- let v be a sink vertex of G
- set f(v) = n
- recurse on G - {v}

Why does it work? When v is assigned to position i, all out going arcs
already detected => all lead to later vertices in ordering.

### Topological Sort via DFS (Slick)

    DFS(graph G, start vertex s)
      - mark s explored
      - for every edge (s, v):
        - if v not yet explored:
          - DFS(G, v)
    - set f(s) == current_label
    - current_label--

    DFS-Loop(graph G)
      - mark all nodes unexplored
      - current_label = n [to keep track of ordering]
      - for each vertex v in G:
        - if v not yet explored in some previous DFS call.
          - DFS(G, v)

Running Time: O(m + n)

Reason: O(1) time per node, O(1) time per edge

    u --> v

Correctness: need to show that if (u, v) is an edge, then f(u) < f(v).

Case 1: u visited by DFS before v. => recursive call corresponding to v
finishes before that of u (since DFS) => f(v) > f(u)

Case 2: v visited before u => v’s recursive call finishes before u’s even starts. => f(v) > f(u)

## Strongly Connected Components

Formal Definition: the strongly connected components of a directed graph
G are the equivalent classes of the relation

    u ~ v <=> exists a path u --> v and a path v --> u in G.

~ is a equivalence relation.

### Why Depth-First Search?

If you start DFS from a right place, you will find a SCC. Preprocessing
needed.

### Kosaraju's Two-Pass Algorithm

Theorem: can compute all SCCs in O(m + n) time.

Algorithm: (given directed graph G)

1. Let G^rev = G with all arcs reversed
2. run DFS-Loop on G^rev (goal: compute "magical ordering" of nodes)
  - Let f(v) = "finishing time" of each v in V
3. run DFS-Loop on G (goal: discover the SCCs one-by-one)
  - Processing nodes in decreasing order of finishing times
[SCCs = nodes with the same "leader"]

### Code

    DFS-Loop(graph G)
    -----------------
    global variable t = 0 (for finishing times in first pass)
    [# of nodes processed so far]
    global variable s = NULL (for leaders in second pass)
    [current source vertex]
    Assume nodes labelled 1 to n
    For i = n down to 1
      if i not yet explored
        DFS(G, i)

    DFS(graph G, node i)
    --------------------
    - mark i as explored
    - set leader(i) := node s
    - for each arc (i, j) in G:
      - if j not yet explored:
        - DFS(G, j)
    - t++
    - set f(i) := t (i's finishing time)

Running Time: 2 * DFS = O(m + n)
