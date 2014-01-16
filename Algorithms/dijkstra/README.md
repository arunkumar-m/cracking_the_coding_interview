# Dijkstra's Shortest Path Algorithm

## Single Source Shortest Paths

Input: directed graph G = (V, E), (m = |E|, n = |V|)
- each edge has **nonnegative** length
- source vertex s

Output: for each v in V, compute L(v) := length of a shortest s-v path
in G.

Assumptions:
1. [for convenience] there is a shortest path from s - v
2. [important] No negative length edges (Use bellman ford instead)

## Why Another Shortest Path Algorithm

Question: doesn't BFS already compute shortest paths in linear time?

Answer: yes, IF l_e = 1 for every edge e.

Question: why not just replace each edge e by directed path of l_e iwth
unit length edges?

Answer: blows up graph too much.

## Dijkstra's Algorithm

    Initialize:
    - X = {S} [vertices processed so far]
    - A[S] = 0 [computed shortest path distances]
    - B[S] = empty path [computed shortest path]

    Main Loop:
    - while X <> V: [need to grow x by one node]
      - among all edges (v, w) in E with v in X and w not in X pick the edge
        that minimize A[v] + l_{vw} (dijkstra's greedy criteria) [call it (v', w')]
      - add w' to X
      - set A[w'] := A[v'] + l_{v'w'}
      - set B[w'] := B[v'] \union (v', w')

## Dijkstra's Non-Example

Question: Why not reduce computing shortest paths with negative edge
lengths to the same problem with nonnegative edge lengths? (by adding
large constant to edge lengths)

Problem: doesn't preserve shortest paths! Dijkstra's algorithm is
incorrect on this graph!

** Super simple three node example. s->v: 1, v->t: -5, s->t: -2. **

## Correctness of Dijkstra's Algorithm

### Correctness Claim

Theorem [Dijkstra] for every directed graph with nonnegative edge
lengths, Dijkstra's algorithm correctly computes all shortest-path
distances. [i.e., A[v] = L[v], for any v in V]

Proof: by induction on the number of iterations.

    Base case: A[S] = L[S] = 0 (correct √)

    Induction step:

    Inductive Hypothesis: all preivous iterations correct. i.e., for all v
    in X, A[v] = L[v] and B[v] is a true shortest s-v path in G.

    In current iteration: We pick an edge (v', w') and we add w' to X.

    We set B[w'] = A[v'] \union (v', w')

    By inductive hypothesis, B[v'] has length L[v'], B[w'] has length L[v'] + l_{v'w'}

    Also, A[w'] = A[v'] + l_{v'w'} = L[v'] + l_{v'w'}

    To finish proof: need to show that every s-w' path has length >= L[v'] + l_{v'w'} (if so, our path is the shortest)

    So: let P = any S->w' path (S in X and w' not in X, must cross the frontier)

    Any S->w' path has the form, S -> y -> z -> w' (S, y in X, z, w' not in X)

    The path S->w' should be longer than A[y] + l_{yz} (y in X, z not in X)

    => by Dijkstra's greedy criterion, A[v'] + l_{v'w'} <= A[y] + l_{yz}

## Dijkstra's Algorithm: Implementation and Running Time

The naive implementation of Dijkstra's algorithm's running time is O(mn)
where m is the number of edges and n is the number of vertices.

- (n - 1) iterations of while loop
- linear scans of all edges crossing the frontier

Can we do better?

### Heap Operations

Recall: heap = perform insert, extract-min in O(log n) time.
- conceptually, a perfectly balanced binary tree
- heap property: at every node, key <= children's keys
- extract-min by swapping up last leaf, bubbling down
- insert via bubbling up

Also: will need ability to delete from middle of heap [bubble up or down
as needed]

### Two Invariants

Invariant #1: elements in heap = vertices of V - X.

Invariant #2: for v not in X, key[v] = smallest Dijkstra greedy score of
an edge (u, v) in E with v in X

Point: by invariants, extract-min yields correct vertex w' to add to X
next.

(and we set A[w'] to key[w'])

### Maintaining the Invariants

To maintain Invariant #2: 

for any v not in X, key[v] = smallest Dijkstra greedy score of edge (u,v) with u in X.

When w is extracted from X, (i.e., added to X)
    - for each edge (w, v) in E:
      - if v in V - X (i.e., in heap)
        - delete v from heap
        - recompute key[v] = min(key[v], A[w] + l_{wv})
        - re-insert v into heap

### Running Time Analysis

Dominated by heap operations. (O(log n) each)
- (n - 1) extract mins
- each edge (v, w) triggers at most one delete/insert combo

So: # of heap operations is O(n + m) = O(m) (since graph weakly
conneted)

So: Running time is O(mlog n) (like sorting)
