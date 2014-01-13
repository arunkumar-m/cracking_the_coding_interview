# Prim's Algorithm

## Fast Implementation I

### Running Time of Prim's Algorithm

Running time of straightforward implementation:
- O(n) iterations [where n is the number of vertices] 
- O(m) per iteration [where m is the number of edges]

=> O(nm) time

BUT CAN WE DO BETTER?

### Speed-Up Via Heaps

Recall from Part I: a heap is to speed up repeated minimum computations.

Specifically: a heap supports Insert, ExtractMin, and Delete in O(log n)
time. [where n is the number of objects in the heap]

Natural idea: use heap to store edges, with keys = edge costs.

Exercise: leads to an O(m log n) implementation of Prim's algorithm.
Larger constants.

### Prim's Algorithm with Heaps

[compare to fast implementation of Dijkstra's algorithm]

Invariant #1: elements in heap = vertices of V - X.

Invariant #2: for v in V - X, key[v] = cheapest edge (u, v) with u in X.
[or +inf if no such edges exist]

Check: can initialize heap with O(m + n log n) = O (m log n)
preprocessing. (m to compute keys, n log n insertion)

Note: given invariants, Extract-Min yields next vertex v not in X and
edge (u, v) crossing (X, V - X) to add to X and T respectively.

## Fast Implementation II

### Maintaining Invariant #2

Issue: might need to recompute some keys to maintain Invariant #2 after
each Extract-Min.

Pseudocode:

    when v added to X:
    - for each edge (v, w) in E:
      - if w in V - X
        - Delete w from heap
        - recompute key[w] = min[key[w], Cvw]
        - re-Insert w into heap

### Running Time with Heaps

- dominated by tree required for heap operations
- (n - 1) Inserts during preprocessing
- (n - 1) Extract-Mins (one per iteration of while loop)
- each edge (v, w) triggers one Delete / Insert combo [when its first
  endpoint gets sucked int oX]

=> O(m) heap operations

=> O(m log n) time

