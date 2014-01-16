# Unique Binary Search Trees II

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,

Given n = 3, your program should return all 5 unique BST's shown below.

    1         3     3      2      1
     \       /     /      / \      \
      3     2     1      1   3      2
     /     /       \                 \
    2     1         2                 3

## Solution

Recursion! When run into problems regarding trees, the first thing that
comes to mind should be recursion. If we can solve the problem for the
left subtree and right subtree, what we should do? When you think about
it you will find the answer.
