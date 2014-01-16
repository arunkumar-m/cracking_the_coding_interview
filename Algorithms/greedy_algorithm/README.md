# Greedy Algorithms

## Introduction to Greedy Algorithms

### Algorithm Design Paradigms

Algorithm Design: no single "silver bullet" for solving problems.

Some Design Paradigms
- divide and conquer
- randomized algorithms
- greedy algorithms
- dynamic programming

### Greedy Algorithms

"Definition": iteratively make "myopic" decisions, hope everything works
out at the end.

Example: Dijkstra's shortest path algorithm
- processed each destination once, irrevocably

### Constrast with Divide & Conquer

1. easy to propose multiple greedy algorithms for many problems
2. easy running time analysis (constrast with master method etc.)
3. **hard** to establish correctness (constrast with straightforward
   inductive correctness proofs)

DANGER: most greedy algorithm are NOT correctly (even if your intuition
says otherwise!)

### In(correctness)

Example: Dijkstra's algorithm with negative edge lengths. 

### Proof of Correctness

Method 1: induction. ("greedy stays ahead")

Example: correctness proof for Dijkstra's algorithm

Method 2: "exchange argument"

Method 3: whatever works!

## Optimal Caching

### The Caching Problem

- small fast memory (the cache)
- big slow memory
- process sequence of "page requests"
- on a "fault" (that is, a cache miss), need to evict something from
  cache to make room - but what?

### Example

Cache: |a|b|c|d|

Request sequence: c d e f a b

=> 4 page faults
- 2 were inevitable (e f)
- 2 consequences of poor eviction choices

### The Optimal Caching Algorithm

Theorem: the "furthest-in-future" algorithm is optimal (i.e., minimizes
the number of cache misses)

Why useful?
1. serves as guideline for practical algorithms (e.g., least recently
   used (LRU) should do weel provided data exhibits locality of reference).
2. serves as idealized benchmark for caching algorithms

Proof: tricky exchange argument.

## A Scheduling Algorithm

Setup: 
- one shared resource (e.g., a processor)
- many jobs to do (e.g., processors)

Questions: in what order should we sequence the jobs?

Assume: each job j has a:
- weight Wj ("priority")
- length Lj

### Completion Times

Definition: the completion time Cj of job j = sum of job lengths up to
and including j.

Example: 3 jobs, L1 = 1, L2 = 2, L3 = 3. We first do job 1 then 2
finally 3. The completion time for 1 is 1, for 2 is 3, for 3 is 6.

### The Objective Function

Goal: minimize the weighted sum of completion times.

Back to example: if W1 = 3, W2 = 2, W1 = 1, this sum is 15.

### Intuition for Algorithm

Recall: want to minimize the weighted sum of completion time.

Goal: devise correct greedy algorithm.

Question:
1. with equal lengths, schedule larger- or smaller-weight jobs earlier?
2. if all jobs have the same weight, is it better to schedule shorter or
   longer jobs earlier?

Answer: Larger; Shorter;

### Resolving Conflict Advice

Question: what if Wi > Wj but Li > Lj?

Idea: assign "scores" to jobs that are:
- increasing in weight
- decreasing in length

Guess:
1. order jobs by decreasing value of Wj - Lj
2. order jobs by Wj / Lj

### Breaking A Greedy Algorithm

To distinguish 1 & 2: find example where the two algorithms produce
different outputs (at least one will be incorrect)

Example: L1 = 5, L2 = 3, W1 = 3, W2 = 1

Using algorithm 1: 23, algorithm 2: 22.

### The Story So Far

So: Alg #1 not (always) correct.

Claim: Alg #2 (order by decreasing ratio Wj / Lj) is always correct.

[Not obvious! - proof coming up next!]

## Correctness Proof

### Correctness Claim

Claim: Alg #2 (order jobs according to decreasing ratios Wj / Lj) is
always correct.

Proof: by an Exchange Argument

Plan: Fix arbitrary input of n jobs will proceed by contraction.

Let \sigma = greedy schedule, \sigma' = optimal schedule.

\sigma will produce schedule even better than \sigma', contradicting
purported optimality of \sigma'.

### Correctness Proof

Assume: all Wj / Lj is distinct.

Assume: [just by renaming jobs W1 / L1 > W2 / L2 > ... > Wn / Ln.

Thus: greedy schedule \sigma is just 1, 2, ... , n.

Thus: if optimal schedule \sigma' <> \sigma, then there are consecutive
jobs i, j with i > j. [only schedule where indices always go up is 1, 2,
3, ... , n]

Thought experiment: suppose we exchangeorder of i & j in \sigma'
(leaving other jobs unchanged).

### Cost-Benefit Analysis

By exchanging i and j (i < j):
- the completion time of a job k other than i or j is unaffected
- the completion time of the job i goes up
- the completion time of the job j goes down

Ci' = Ci + Lj

Cj' = Cj - Li

WiCi' + WjCj' = WiCi + WiLj + WjCj - WjLi

Since Wi / Li < Wj / Lj, WiLj - WjLi < 0, thus WiCi' + WjCj' > WiCi +
WjCj which contradicts optimality of \sigma'.
WjCj

## Handling Ties

### Correctness Claim

Claim: Alg #2 (order jobs in nonincreasing order of ratio Wj / Lj) is
always correct. [even with ties]

New Proof Plan: Fix arbitrary input of n jobs. Let \sigma = greedy
schedule, let \sigma' = any other schedule.  Will show \sigma at least
as good as \sigma' => implies that greedy schedule is optimal.

### Correctness Proof

Assume: [just by renaming jobs] greedy schedule \sigma is just 1, 2, 3,
..., n (and so W1 / L1 >= W2 / L2 >= ... >= Wn / Ln)

Consider arbitrary schedule \sigma'. If \sigma' = \sigma, done.

Else recall there exists consecutive jobs i, j in \sigma' with i > j.
(from last time)

Note: i > j => Wi / Li <= Wj / Lj => WiLj <= WjLi

Recall: exchanging i & j in \sigma' has a net benefit of WjLi - WiLj >=
0.

Upshot: exchanging an "adjacent inversion" like i, j only makes \sigma'
better and it decreases the number of inverted pairs.
(jobs i, j with i > j and i scheduled earlier)

=> after at most nC2 such exchanges, can transform \sigma' into \sigma.

=> \sigma at least as good as \sigma'

=> greedy is optimal

[Like bubble sort]

## Minimum Spanning Trees

### Overview

Informal Goal: connect a bunch of points together as cheaply as
possible.

Applications: clustering (more later), networking.

Blazingly Fast Greedy Algorithm:
- Prim's Algorithm [1957; also Dijkstra 1959; Jarnik 1930]
- Kruskal's Algorithm [1956]

=> O(m log n) time (using suitable data structures)

### Problem Definition

Input: undirected graph G = (V, E) and a cost Ce for each edge e in E.
- assume adjacency list representation
- OK if edge costs are negative.

Output: minimum cost tree T in E that spans all vertices. [cost: sum of
edge costs]
- T has no cycles
- the subgraph (V, T) is connected.

### Standing Assumptions

Assumption #1: input graph G is connected.
- else no spanning trees
- easy to check in preprocessing (e.g., depth-first search)

Assumption #2: edge costs are distinct.
- Prim + Kruskal remain correct with ties (which can be broken
  arbitrarily)
- Correctness proof a bit more annoying (will skip)

## Prim's MST Algorithm

### Example

(compare to Dijkstra's Shortest-Path Algorithm)

### Prim's MST Algorithm

    - initialize X = [s] where s belongs V and is chosen arbitrarily.
    - T = empty set [invariant: X = vertices spanned by tree-so-far T]
    - while X <> V:
      - let e = (u, v) be the cheapest edge of G with u in X, v not in X
      - add e to T
      - add v to X
    i.e., increase # of spanned vertices in cheapest way possible

### Correctness of Prim's Algorithm

Theorem: Prim's algorithm always computes an MST.

Part I: computes a spanning Tree T'. [will use basic properties of
graphs & spanning trees]

Part II: T' is an MST.
[will use the "cut property"]

Later: fast [O(m log n)] using heap.

## Correctness of Prim's Algorithm

### Cuts

Claim: Prim's algorithm outputs a spanning tree.

Definition: a cut of a graph G = (V, E) is a partition of V into 2
non-empty sets.

Roughly a graph has 2^n cuts.

### Empty Cut Lemma

Empty Cut Lemma: a graph is not connected <=> there exists a cut (A, B)
with no crossing edges.

Proof:

(<=) Assume the RHS. Pick any u in A and v in B. Since no edges
cross (A, B), there is no u-v path in G -> G not connected.

(=>) Assume the LHS. Suppose G has no u-v path. Define A = {vertices
reachable from u in G} (i.e., u's connected component) B = {all other
vertices} (i.e., all other connected components)

Note: no edges cross cut (A, B) (otherwise A would be much bigger!)

### Two Easy Facts

Double-Crossing Lemma: Suppose the cycle C in E has an edge crossing the
cut (A, B), then so does some other edge of C.

Lonely Cut Corollary: if e is the only edge crossing some cut (A, B),
then it is not in any cycle.

[if it were in a cycle, some other edge would have to cross the cut!]

### Proof of Part I

Claim: Prim's algorithm outputs a spanning tree.

Proof:
- algorithm maintains invariant that T spans X [straightforward
  induction - you check]
- can't get stuck with X <> V (otherwise the cut (X, V - X) must be
  empty; by empty cut lemma, input graph G is disconnected)
- no cycles ever get created in T. Why? Consider any iteration, with
  current sets X and T. Suppose e gets added. **key point:** e is the
first edge crossing (X, V - X) that gets added to T => its addition
cannot create a cycle in T [by lonely cut corollary].

## Correctness of Prim's Algorithm

### Correctness of Prim's Algorithm

Theorem: Prim's algorithm always outputs a minimum-cost spanning tree.

Key Question: when is it "safe" to include an edge in the tree-so-far.

### The Cut Property

Cut Property: consider an edge e of G. Suppose there is a cut (A, B)
such that e is the cheapest edge of G that crosses it. Then e belongs to the MST of G.

**It turns out that MST is unique if edge costs are distinct**

### Cut Property Implies Correctness

Claims: Cut Property => Prim's algorithm is correct.

Proof: By previous video, Prim's algorithm outputs a spanning tree T'.

Key point: every edge e in T' is explicitly justified by the CUT
PROPERTY!

=> T' is a subset of the MST.
=> since T' is already a spanning tree, it must be the MST.

## Proof of the Cut Property

### The Cut Property

Assumption: distinct edge costs.

CUT PROPERTY: consider an edge e of G. Suppose there is a cut (A, B)
such that e is the cheapest edge of G that crosses it. Then e belongs to
the MST of G.

### Proof Plan

Will argue by contradiction, using an exchange argument. [compare to
scheduling application]

Suppose there is an edge e that is the cheapest one crossing a cut (A,
B), yet e is not in the MST T'.

Idea: exchange e with another edge in T' to make it even cheaper
(contradiction)

### Attempted Exchange

Given cut (A, B) with the cheapest edge e crossing it.

Note: since T' is connected, must contain an edge f crossing (A, B)

Question: Let T' be a spanning tree of G, e not in T', f in T'. Is T'
\union {e} - {f} a spanning tree of G?

### Smart Exchanges

Hope: Can always find suitable edge e' so that exchange yields a 
spanning tree of G.

How?: Let C = cycle created by adding e to T'.

By the double-crossing lemma: some other edge e' of C (with e' <> e and
e' in T'] crosses (A, B).

You check: T = T' \union {e} - {e'} is also a spanning tree. Since Ce <
Ce', T cheaper than purported MST T', contradiction.

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

## Kruskal's MST Algorithm

### Pseudocode

    - sort edges in order of increasing cost [rename edges 1, 2, ... , m
      so that C1 < C2 < ... < Cm]
    - T = empty set
    - for i = 1 to m
      - if T \union {i} has no cycles
        - add i to T
    - return T

## Correctness of Kruskal's Algorithm

### Correctness of Kruskal (Part I)

Theorem: Kruskal's algorithm is correct.

Proof: Let T' = output Kruskal's algorithm on input graph G.
- clearly T' has no cycles
- T' is connected, why?
  - by empty cut lemma, only need to show that T' crosses every cut.
  - fix a cut (A, B). since G connected at least one of its edges
    crosses (A, B).
    - key point: Kruskal will include first edge crossing (A, B) that it sees.
      [by lonely cut corollary, cannot create a cycle]
  - every edge of T' justified by the Cut Property (implies T' is the
    MST)

Reason for (3):

Consider iteration where edge (u, v) added to current set T.

Since T \union {(u, v)} has no cycle, T has no u - v path.

=> exists empty cut (A, B) separate u and v

=> no edges crossing (A, B) were previously considered by Kruskal's
algorithm.

=> (u, v) is the first (hence the cheapest!) edge crossing (A, B)

=> (u, v) justified by the Cut Property.

## Implementating Kruskal's Algorithm via Union-Find

### Kruskal's MST Algorithm

Running Time of straightforward implementation:
- sorting takes O(m log n).
- O(m) iterations
- O(n) time to check for cycle (use BFS or DFS)
- total: O(mn)

Plan: data structure for O(1)-time cycle checks => O(m log n) time.

### Union-Find Data Structure

Union-Find: maintain partition of a set of objects.

FIND(x): return name of group that x belongs to

UNION(Ci, Cj): fuse group Ci and Cj into a single one.

Why useful for Kruskal's algorithm?
- groups = connected components w.r.t. current chosen edges T
- adding new edge (u, v) to T <-> fusing connected components of u, v

### Union-Find Basics

Idea #1:
- maintain one linked structure per connected component of (V, T)
- each component has an arbitrary leader vertex.

Invariant: each vertex points to the leader of its component.

Key point: given edge (u, v), can check if u & v alreadly in same
component in O(1) time. => O(1) - time cycle checks!

### Maintaining the Invariant

Notes: when new edges (u, v) added to T, connected components of u & v
merge.

Question: how many leader pointer updates are needed to restore the
invariant in the worst case?

Answer: O(n)

Idea #2: when two components merge, have smaller one inherit the leader
of the larger one.

Question: how many leader pointer updates are now required to restore
the invariant in the worst case?

Answern: O(n)

But: how many times does a single vertex have its header pointer update
over the course of Kruskal's algorithm?

Answer: O(log n)

### Running Time of Fast Implementation

Scorecard:

- O(m log n) time for sorting
- O(m) time for cycle checks [O(1) per iteration]
- O(n log n) time overall for leader pointer updates

**Total Running Time: O(m log n)**

## MSTs: State of the Art and Open Questions

### State-of-the-Art MST Algorithm

Question: can we do better than O(m log n)?

Answer: yes!

O(m) randomized algorithm. [Karger-Klein-Tarjan JACM 1995]

O(m \alpha(n)) deterministic [Chazelle JACM 2000]

\alpha() is inverse Ackermann Function, grows really slower.

### Open Questions

- simple randomized O(m)-time algorithm for MST [sufficient: do this
  just for the "MST verification" problem]
- is there a deterministic O(m)-time algorithm

Further Reading: [Eisner 97]

## Application to Clustering

### Clustering

aka unsupervised learning

Informal goal: given n "points" [web pages, images, genome fragments]
clustering into "coherent groups".

Assumptions: as input, given a (dis)similarity measure - a distance d(p,
q) between each point pair.

Examples: Euclidean distance, genome similarity, etc.

Goal: same cluster <=> "nearby"

### Max-Spacing k-Clusterings

Assmue: we know k := # of clusters desired.

(all points p & q separated if they're assigned to different clusters)

Definition: the spacing of a k-clustering is min d(p, q) where p & q are
seperated. (the bigger, the better)

Given a distance measure d and k, compute k-clustering with maximum
spacing.

    - initially, each point in a separate cluster
    - repeat until only k clusters:
      - let p, q = closest pair of separated points
      - merge the clusters containing p & q into a single cluster

Note: just like kruskal's MST algorithm, but stopped early.

- points <-> vertices; distances <-> edge costs; point pairs <-> edges

=> called single-link clustering

## Correctness of Clustering Algorithm

### Correctness Claim

Theorem: single-link clustering finds the max-spacing k-clustering.

Proof: Let C1, ..., Ck = greedy clustering with spacing S.

Need to show: Spacing of arbitrary clustering is smaller or equal to S.

### Correctness Proof

Details are shown in the video.

## Huffman Codes

### Binary Codes

Binary Code: maps each character of an alphabet \sum to a binary string

Example: \sum = a - z & various pinctuation (size 32 overall, say)

Obvious encoding: use the 32 5-bit binary strings to encode this \sum (a
fixed-length code)

Can we do better? yes, if some characters of \sum are much more frequent
than others, use a variable-length code.

### Ambiguity

Example: Suppose \sum = {A, B, C, D}. Fixed-length encoding would be
{00, 01, 10, 11}.

Suppose instead, we use the encoding {0, 01, 10, 1}. What is 001 an
encoding of?

### Prefix-Free Codes

Problem: with variable-length codes, not clear where one character ends + next one begins.

Solution: prefix-free codes - make sure that for every pair i, j in
\sum, neither of the encodings f(i), f(j) is a prefix of the other.

Example: {0, 10, 110, 111}

### Example

    A 60% 00   0
    B 25% 01  10
    C 10% 10 110
    D 5%  11 111

fixed-length encoding: 2 bits / character

variable-length encoding: 1.55 bits / character

## Huffman Codes: Problem Definition

### Codes as Trees

Goal: best binary prefix-tree encoding for a given set of character
frequencies.

Useful fact: binary codes <-> binary trees

Examples: \sum = {A, B, C, D}

### Prefix-Free Codes as Trees

In general: left child edges <-> "0", right child edges <-> "1"
- for each i in E, exactly one node labeled "i"
- encoding of i in \sum <-> bits along path from root to the node "i"

To decode: repeatedly follow path from root until you hit a leaf.

Note: encoding length of i in \sum = depth of i in tree.

### Problem Definition

Input: probability Pi for each character i in \sum

Notation: if T = tree with leaves <-> symbols of \sum, then L(T) is the
average encoding length.

## Huffman Codes: A Greedy Algorithm

### Building a Tree

Question: what's a principled approach for building a tree with leaves
<-> symbols of \sum?

Natural but suboptimal idea: top-down / divide + conquer.
- partition \sum into \sum1 \sum2 each with 50% of total frequency
- recursively compute T1 for \sum1, T2 for \sum2, return

Huffman's idea:
- build tree bottom-up
- using succesive merges

### A Greedy Approach

Question: which pair of symbols is "safe" to merge?

Observation: final encoding length i in \sum = number of mergers its
subtree endures.

### Huffman's Algorithm

    If |\sum| = 2 return ...
    Let a, b in \sum have the smallest frequencies.
    Let \sum' = \sum with a, b replaced by new symbol ab.
    Define Pab = Pa + Pb.
    Recursively compute T' (for the alphabet \sum')
    Extend T' (with leaves <-> \sum') to a tree T with leaves <-> \sum
                            by splitting leaf ab into two leaves a & b
    Return T

## Huffman Codes: Correctness Proof

### Correctness of Huffman's Algorithm

Theorem: Huffman's algorithm computes a binary tree (with leaves <->
symbols of \sum) that minimizes the average encoding length L(T).

Proof: by induction on n = |\sum|. (Can assume n >= 2)

Base case: when n = 2, algorithm outputs the optimal tree.

Inductive steps: fix input with n = |\sum| > 2.

By inductive hypothesis: algorithm solves smaller subproblem (for \sum') optimally.

### Inductive Step

Let \sum' = \sum with a, b (symbols with smallest frequencies) replaced by meta-symbol ab. Define Pab = Pa +
Pb.

**Important:** for every such pair T' and T, L(T) - L(T') is Pa * [depth of
a in T] + Pb * [depth of b in T] - Pab * [depth of ab in T'] = Pa + Pb

## Huffman Codes: Correctness Proof II

### Proof of Theorem

**Inductive Hypothesis:** Huffman's algorithm computes a tree that minimize
L(T') for \sum'.

Upshot of last slide: corresponding Huffman's solution minimizes L(T) for
\sum over all trees in Xab (i.e., where a & b are siblings)

Key lemma: there is an optimal tree (for \sum) in Xab.

Intuition: can make an optimal tree better by pushing a & b as deep as
possible. (since a, b have smallest frequencies)

### Proof of Key Lemma

By exchange argument, Let T'' be any tree that minimizes L(T) for \sum.

Let x, y be siblings at the deepest level of T''.

The exchange: obtain optimal solution from T'' by swapping labels a <->
x, b <-> y

Note: optimal solution in Xab (by choice of x, y)

To finish: will show that L(optimal) <= L(T'')

Reason: ...

### Notes on Running Time

Naive Implementation: O(n^2) time, where n = |\sum|.

*Speed ups: use a heap!*
- use keys = frequencies
- after extracting the two smallest-frequency symbols, re-Insert the new
  meta symbol

=> iterative, O(n log n) implementation

Even faster: (non-trivial exercise) sorting + O(n) additional work.
- manage (meta-) symbols using two queues!
