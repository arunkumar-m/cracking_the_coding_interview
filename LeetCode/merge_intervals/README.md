# Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

For example,

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

## A Simple Solution

Write a procedure to insert a new interval into a vector of
non-overlapping intervals. For each interval that we need to merge,
insert it into a new vector.

The time complexity is O(n * n).

## A Efficient Solution

1. Sort the intervals based on increasing order of starting time.
2. Push the first interval onto a stack.
3. For each interval do the following
  - If the current interval does not overlap with the stack top, push it.
  - If the current interval overlaps with stack top and ending time of current interval is more than that of stack top, update stack top with the ending time of current interval.
4. At the end, stack contains the merged intervals.

Please refer to [this post at geeksforgeeks.org](http://www.geeksforgeeks.org/merging-intervals/) for more details.
