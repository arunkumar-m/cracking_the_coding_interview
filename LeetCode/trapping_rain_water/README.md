# Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 

Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

## Solution

At a specific bar, we need to know the highest bar to its left and the
highest bar to its right. Once we know these two values, we can easily
figure the amount of water it can hold.
