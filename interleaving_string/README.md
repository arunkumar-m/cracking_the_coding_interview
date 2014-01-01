# Interleaving String

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,

Given:

s1 = "aabcc",

s2 = "dbbca",

When s3 = "aadbbcbcac", return true.

When s3 = "aadbbbaccc", return false.

## Recursive Solution

Using recursion can solve this problem, however, it is not that easy to
use recursion to pass large test cases. Matching head and tail charaters
at the same time helps me pass all the tests.

**The importance of pruning!**

For example, scramble string problem can use recursion to pass big tests
if you add a constraint that the sorted strings should be equal to each
other.

## Dynamic Programming

Let dp[i][j] = 1 if s3[1..i+j] can be formed by s1[1..i] and s2[1..j].

We have:

    dp[i][j] = ((s3[i+j]==s1[i] && dp[i-1][j]) || (s3[i+j]==s2[j] && dp[i][j-1]))

