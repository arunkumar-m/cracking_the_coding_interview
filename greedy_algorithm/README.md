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
