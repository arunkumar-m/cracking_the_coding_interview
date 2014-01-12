# Dynamic Programming

## Introduction, and WIS in Path Graphs

### Problem Statement

Input: a path graph G = (V, E) with nonnegative weights on vertices.

Desired output: subset of nonadjacent vertices - an independent set - of
maximum total weight.

Next: iterate through our algorithm design principles.

Example: 1 - 4 - 5 - 4

### A Greedy Approach

Greedy: iteratively choose the max-weight vertex not adjacent to any
previously chosen vertex.

### A Divide & Conquer Approach

Idea: recursively compute the max-weight IS of 1st half, ditto for 2nd
half, then combine the solutions.

## WIS in Path Graphs: Optimal Substructure

Critical step: reason about structure of an optimal solution. [in terms
of optimal solutions of smaller subproblems]

Motivation: this thought experiment narrows down the set of candidates
for the optimal solution; can search through the small set using
brute-force-search.

Notation: Let S subset of V be a max-weight independent set. Let Vn =
last vertex of path.

### A Case Analysis

Case 1: Suppose Vn not in S. Let G' = G with Vn deleted.

Note: S also an IS of G'.

Note: S must a max-weight IS of G' - if S' was better, it would also be
better than S in G. [contradiction]

Case 2: Suppose Vn in S.

Note: previous vertex Vn-1 not in S. Let G'' = G with Vn-1, vn deleted.

Note: S - {Vn} is an IS of G''.

Note: must in fact be a max-weight IS of G'' - if S' is better than S in
G'', then S' union {Vn} is better than S in G [contradiction]

### Toward an Algorithm

Upshot: a max-weight IS must be either
- a max-weight IS of G' or
- Vn + a max-weight IS of G''

Corollary: if we knew whether or not Vn was in the max-weight IS, call
recursively compute the max-weight IS of G' or G'' and be done.

(Crazy?) idea: try both possibilities + return the best solution

## WIS in Path Graphs: A Linear Time Algorithm

### The Story So Far

Upshot: if we know whether or not Vn is in the max-weight IS, then could
recursively compute the max-weight IS of G' or G'' and be done.

Proposed algorithm:
```
- recursively compute S1 = max-weight IS of G'
- recursively compute S2 = max-weight IS of G''
- return S1 or S2 union [Vn], whichever is better
```

Good news: correct. [optional exercise - prove formally by induction]

Bad news: exponential time.

### The $64,000 Question

Important: how many distinct subproblems ever get solved by this algorithm?

O(n).

### Eliminating Redundancy

Obvious-fix: the first time you solve a subproblem, cache its solution in a
global take for O(1)-time lookup later on. ["memoitation"]

Even better: reformulate as a bottom-up iterative algorithm. Let Gi = 1st i
vertices of G.

Plan: populate array A left to right with A[i] = IS of Gi

Initialization: A[0] = 0, A[1] = w1.

Main loop:
```
For i = 2,3,4,...,n:
    A[i] = max{A[i-1],A[i-2]+1}
```
Time complexity: O(n).

## WIS in Path Graphs: A Reconstruction Algorithm

### Optimal Value vs. Optimal Solution

Recall: A[0] = 0, A[1] = w1, for i = 2,3,4 to n A[i] :=
max[A[i-1],A[i-2]+wi]

Note: algorithm computes the value of a max-weight IS, not such an IS
itself.

Correct but not ideal: store optimal IS of each Gi in the array in
addition to its value.

Better: trace back through filled in array to reconstruct optimal
solution.

Key point: we know that a vertex Vi belongs to a max-weight IS of Gi <=>
Wi + max-weight IS of Gi-2 >= max-weight IS of Gi-1

### A Reconstruction Algorithm

Let A = filled-in array A: 0,4,4,2,...,184

```
- let S = empty set
- while i >= 1 [scan through array from right to left]
  - if A[i - 1] >= A[i - 2] + Wi [i.e. case 1 wins]
    - decrease i by 1
  - else [i.e. case 2 wins]
    - add Vi to S, decrease i by 2
- return S
```

Running time: O(n).

## Principles of Dynamic Programming

### Principles of Dynamic Programming

Fact: our WIS algorithm is a dynamic programming algorithm!

Key ingredients of dynamic programming:
- identify a small number of subproblems [e.g., compute the max-weight
  IS of Gi. for i = 0,1,2,3,...n]
- can quickly + correctly solve "larger" subproblems given the solutions
  to "smaller subproblems" [usually via a recursive such as A[i] =
  max[A[i-1],A[i-2]+Wi].
- after solving all subproblems, can quickly compute the final solution.
  [usually, it's just the answer of the biggest subproblem.

### Why "Dynamic Programming"?

Richard Bellman.
