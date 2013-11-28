# Reorder List

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→...

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

## Solution 1

Recursion solution is quite easy to come up. However, it will fail the
large test case on LeetCode.

## Solution 2

First, I split the list into two lists. Reverse the second half, and
merge it with the first half. This algorithm successfully pass the
large test of LeetCode.
