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

## The Knapsack Problem

### Problem Definition

Input: n items. Each has a value:
- value vi (nonnegative)
- size wi (nonnegative and integral)
- capacity w (a nonnegative integer)

Output: S which is a subset of {1,2,3,...,n} that maximize the sum of vi
subject to sum of wi <= W.

### Developing a Dynamic Programming Algorithm

Step 1: formulate recurrence [optimal solution as function of solutions
to "smaller" subproblems] based on structure of an optimal solution.

Let S = a max-value solution to an instance of knapsack.

Case 1: suppose item n not in S.
- S must be optimal with the first (n - 1) items. (same capacity W)

### Optimal Substructure

Case 2: Suppose item n in S. Then S - [n] is an optimal solution with
respect to the first (n - 1) items and capacity W - wn.

## A Dynamic Programming Algorithm

### Recurrence from Last Time

Notation: let Vi,x = value of the best solution that:
- uses only the first i items.
- has total size <= x

Upshot of last video: for in {1,2,...,n} and any x,

```
Vi,x = max(Vi-1,x, Vi + Vi-1,x-wi)

Don't forget edge case.
Edge case.
```

### The Subproblems

Step 2: identifying the subproblems.
- all possible prefixes of items {1,2,...,i}
- all possible (integral) residual capacities x in {0,1,...,n}

Step 3: use recurrence from step 1 to systematically solve all
subproblems.

Let A = 2-D array

Initiate A[0,x] = 0 for x = 0,1,2,...,W.

```
for i = 1,2,3,...,n:
  for x = 0,1,2,...,W:
    if wi > x:
      A[i, x] = A[i-1, x-1]
    else:
      A[i,x] := max {A[i-1, x], A[i-1, x-wi] + vi}
```

Running Time: O(nW)

## Sequence Alignment: Optimal Substructure

### Problem Definition

Recall: sequence alignment [needleman-wunsch score = similarity measure
between strings]

Example: AGGGCT - AGG-CA 

Input: strings X = x1 .. xn, Y = y1 .. yn over some alphabet \sum (like
{A,C,G,T}.
- penalty >=0 for inserting a gap.
- penalty for matching a & b [presumably = 0 if a = b]

Feasible Solutions:
- alignments - i.e., insert gaps to equalize lengths of the strings

Goal:
- minimize the penalty

### A Dynamic Programming Approach

Key step: identify subproblems. As usual, will look at structure of an
optimal solution for clues. [i.e., develop a recurrence then reverse
engineer the subproblems]

Structure of optimal solution: consider an optimal alignment of X, Y

    - --- x + gaps ---
    - --- y + gaps ---
    - focus on final position

How many relevant possiblilities are there for the contents of the final
position of an optimal alignment?

**3 Cases!**

- Case 1: xm, ym matched
- Case 2: xm matched with a gap
- Case 3: ym matched with a gap

### Optimal Substructure

Point: narrow optimal solution down to 3 candidates.

Optimal Substructure: Let X' = X - xm, Y' = Y - yn.

- If case (1) holds, then induced alignment of X' and Y' is optimal.
- If case (2) holds, then induced alignment of X' and Y is optimal
- If case (3) holds, then induced alignment of X and Y' is optimal.

### Optimal Substructure (Proof)

Proof: [of Case 1, other cases are similar]

By contradiction, suppose induced alignment of X', Y' has penalty P
while some other one has penalty p' < p.

=> matching xm with ym to the latter, get an alignment of X and Y with
penalty p' + penalty of xm yn < p + penalty of xm yn (penalty of
origianl alignment)

=> contradicts optimality of original alignment.

## An Algorithm for Sequence Alignment

### The Recurrence

Notation: Pi,j = penalty of optimal alignment of Xi and Yj.

Recurrence: for all i = 1,2,3,...,m and j = 1,2,3,...,n:

    Pi,j = min(Xi != Yj + Pi-1,j-1, 1 + Pi-1,j, 1 + Pi,j-1)

Correctness: optimal solution is one these 3 candidates, and recurrence
selects the best of these.

### Base Cases

Question: what is the value of Pi,0 and P0,i?

Answer: i

### The Algorithm

```
A = 2-D array.
A[i,0] = A[0,i] = i for any i >= 0
For i = 1 to m
  For j = 1 to n
    A[i,j] = ...
```

### Reconstructing A Solution

- trace back through filled-in table A, starting at A[m,n]
- when you reach subproblem A[i, j]:
  - if A[i,j] filled using case 1, match xi and yj and got to A[i-1,j-1]
  - if A[i,j] filled in using case 2, match xi with a gap and got to
    A[i-1,j]
  - if A[i,j] filled in using case 3, match yi with a gap and go to
    A[i,j-1]

[if i = 0 or j = 0, match remaining substring with gaps]

## Optimal Binary Search Trees

### A Multiplicity of Search Trees

Recall: for a given set of keys, there are lots of valid search trees.

Question: what is the "best" search tree for a given set of keys?

=> worst-case search time = O(height) = O(log n)

### Exploiting Non-Uniformity

Question: Suppose we have keys x < y < z and we know that 80% of
searches are for x, 10% of searches are for y, 10% of searches are for
z.

What is average search time (i.e., number of nodes looked at) in the
trees.

### Problem Definition

Input: frequencies p1,p2,...,pn for items 1,2,...,n. [assume items in
sorted order, 1 < 2 < 3 < ... < n]

Goal: compute a valid search tree that minimizes the weighted (average)
search time.

    C(T) = \sum_{items i} Pi * [search time for i in T]

Example: if T is a red black tree, then C(T) = O(log n)

### Huffman Codes

Similarities:
- output = a binary tree
- goal is (essentially) to minimize average depth with respect to given
  probabilities

Difference:
- with Huffman codes, constraint was prefix-freeness [i.e., symbols only
  at leaves]

## Optimal BSTs: Optimal Substructure

### Greedy Doesn't Work

Intuition: want the most (respectively, least) frequently accessed items
closest (respectively, furthest) from the root

### Ideas for greedy algorithms:

- bottom-up [populate lowest level with least frequently accessed keys]
- top-down [put most frequently accessed item at root, recurse]

### Choosing the Root

Issue: with the top-down approach, the choice of root has
hard-to-predict repercussions further down the tree. [stymies both
greedy and naive divide + conquer approaches]

Idea: what if we knew the root? (i.e., maybe can try all probabilities
within a dynamic programming algorithm!)

### Comparison with Huffman Codes

Suppose an optimal binary search tree for keys {1,2,...,n} has root r,
left subtree T1, and right subtree T2. Pick the strongest statement that
you suspect is true.

T1 is optimal for keys {1,2,...,r-1}, and T2 is optimal for the keys
{r+1,r+2,...,n}.

## Optimal BSTs: Proof of Optimal Substructure

### Proof of Optimal Substructure

Let T be an optimal BST for keys {1,2,...,n} with frequencies p1,...,pn.
Suppose T has root r. Suppose for contradiction that T1 is not optimal
for {1,2,...,r-1} [other case is similar] with C(T1') < C(T1). Obtain T'
from T by cutting + pasting T1' in for T1.

Note: to complete contradiction + proof, only need to show that C(T') <
C(T).

## Optimal BSTs: A Dynamic Programming Algorithm
