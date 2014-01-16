# Scramble String

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

        great
       /    \
      gr    eat
     / \    /  \
    g   r  e   at
               / \
              a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

        rgeat
       /    \
      rg    eat
     / \    /  \
    r   g  e   at
               / \
              a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

        rgtae
       /    \
      rg    tae
     / \    /  \
    r   g  ta  e
           / \
          t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

## Solution

Recursion.

A huge optimization would be: at the start of the recursive function, check if the two sorted strings are the same. If it is
not the same, return false.

[LeetCode's disccusion](http://discuss.leetcode.com/questions/262/scramble-string) suggests three dimensional dynamic programming. Maybe I will
have a try:

    3 dimensional dynamic programming:
    f(i, j, n) = || ((f(i, j, m) && f(i + m, j + m, n - m)) || f(i, j + n - m, m) && f(i + m, j, n - m)) for 1 < m < n
    where f(i, j, n) is true iff substring starts at s1[i] and substring starts at s2[j] both with length n are scrambled
