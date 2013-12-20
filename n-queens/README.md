# N-Queens

The n-queens puzzle is the problem on an nxn chessboard such that no two
queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

    [
     [".Q..",  // Solution 1
      "...Q",
      "Q...",
      "..Q."],

     ["..Q.",  // Solution 2
      "Q...",
      "...Q",
      ".Q.."]
    ]

## Solution

Use three array to judge if a queen can be placed in (i, j).

- row[i] = 1 if ith row is taken
- ldiag[x] = 1 if at least one point(i, j) i + j = x
- rdiag[x] = 1 if at least one point(i, j) i - j + n = x

If you only care about calculating the number of solutions we can use
symmetry to reduce the computation.

    board[0] <= (n + 1) / 2 
