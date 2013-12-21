# Edit Distance

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

- Insert a character
- Delete a character
- Replace a character

## Solution

For two strings
- X of length n
- Y of length m

We define D(i, j)
- the edit distance between X[1..i], Y[1..j]
  - the first i characters of X and the first j characters of Y
- the edit distance between X and Y is thus D(n, m)

### Dynamic Programming for Minimum Edit Distance

- Dynamic Programming: A tabular computation of D(n, m)
- Solving problems by combining solutions to subproblems
- Bottom-up
  - We compute D(i, j) for small i, j
  - And compute larger D(i, j) based on previously computed smaller
    values
  - i.e. compute D(i, j) for all i (i < i < n) and j (0 < j < m)

**Note:** What is an insertion and deletion anyway?

- Initialization:

    D(i, 0) = i
    D(0, j) = j

- Recurrence Relation:

    For each i = 1..M
      For each j = 1..N
        D(i, j) = min(D(i-1, j) + 1, D(i, j-1) + 1, D(i-1, j-1) + (X(i) == Y(j))

- Termination:

    D(N, M) is distance

Running time: O(mn)
