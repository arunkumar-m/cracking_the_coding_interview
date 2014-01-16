# The Minimum Cut Problem

Input: an undirected graph G = (V, E). [parallel edges allowed]

Goal: compute a cut with fewest number of crossing edges. (a min cut)

## Random Contraction Algorithm

    while there are more than 2 vertices:
      pick a remaining edge (u, v) uniformly at random
      merge (or "contract") u and v into a single vertex
      remove self-loops
    return cut represented by final 2 vertices

### What is the probability of success?

Fix a graph G = (V, E) with n vertices, m edges.

Fix a minimum cut (A, B).

Let k = number of edges crossing (A, B). (call those edges F.)

What could go wrong?
- Suppose an edge of F is contracted at some point. => algorithm will
  not output (A, B)
- Suppose only edges inside A or inside B get contracted. => algorithm
  will output (A, B).

Thus the probability of the output is (A, B) is the probability that we
never contracts an edge of F.

Let Si = event that an edge of F contracted in iteration i.

The probability that an edge crossing the minimum cut (A, B) is chosen
in the first iteration is k / m <= 2 / n.

Key observation: degree of each vertex is at least k.

Reason: each vertex v defines a cut ({v}, V - {v}).

Thus the sum of the degrees of all vertices is 2m. m >= kn / 2.

The second iteration: >= (1 - 2 / (n - 1)) * ( 1 - 2 / n)

The nth iteration: >= (1 - 2 / (n - k)) * ( 1 - 2 / (n - k + 1)) * ...

**Overall probability = 2 / n / (n - 1) >= 1 / n^2**

Problem: low success probability. (non-trivial)

### Repeated Trials

Solution: run the basic algorithm a large number N times, remember the
smallest cut found.

Questions: how many trials needed?

Let Ti = event that the cut (A, B) is found on the ith try.

=> by definition, different Ti's are independent.

So: Pr[all N trials fail] = (1 - 1 / n^2)^N

Recall that 1 + x <= e^x.

So: if we take N = n^2, Pr[all fails] <= (e^(-1/n^2))^(n^2) = 1 / e

If we take N = n^2 ln n, Pr[all fails] <= 1 / n

### Running Time

polynomial time algorithm in n and m but slow (O(n^2 * m))

But: can get big speedups to roughly O(n^2) with more ideas.
