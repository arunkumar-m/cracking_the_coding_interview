# Jump Game II

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:

Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

## Solution

A straight forward solution would be:

Let D(i) denote the minimum number of jumps to reach index i.

    D(i) = min(D(j) + 1) for all j < i if j can reach i

Running Time = O(n * n)

You can also use bfs to solve this problem because this problem is very
similar to shortest path problem. However, bfs's running time is O(v +
e). In this problem, e can be a very large number, so bfs will also
encounter a time limit exceeded error.

You can use greedy algorithm to solve this problem.
