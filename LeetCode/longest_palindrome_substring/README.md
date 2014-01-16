# Longest Palindrome Substring

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

## Solution

Details about the solution of longest palindrome substring problem can be [here in Leetcode](http://leetcode.com/2011/11/longest-palindromic-substring-part-i.html).

### Brute Force

A simple brute force algorithm takes O(n^3) time because there are a
total of C(n, 2) such substrings (excluding the trivial solution where a
character itself is a palindrome) and verifying each substring takes
O(n) time. Thus the running time is O(n^3).

### Dynamic Programming

O(n^3) is large! It is where dynamic programming comes in! DP solution
takes O(n^2) time and O(n^2) space.

A overview:

    Define D[i, j] to be true if and only if the substring S[i..j] is a
    palindrome, false otherwise.

We have:

    D[i, j] = D[i + 1, j - 1] and S[i] == S[j]
    
The base cases:

    D[i, i] = true
    D[i, i+1] = S[i] == S[i + 1]

### A Great Observation

Observation:

    A palindrome mirrors around its center. Therefore, a palindrome can
    be expanded from its cente, and there are only 2N - 1 such centers.

### Do we have O(n) Solution?

Yes! But it is pretty complicated. See the [post in Leetcode](http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html) for more
details.
