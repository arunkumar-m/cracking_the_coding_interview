#!/usr/bin/python
# -*- coding: utf-8 -*-

from math import log, ceil

def build_seg_tree(A):
    """Build segment tree from an array and return an array."""
    length = len(A)
    height = int(ceil(log(length, 2)))
    tree_size = 2 * 2 ** height
    seg_tree = list([float("inf")] * tree_size)
    build_seg_tree_helper(A, 0, length - 1, seg_tree, 1)
    return seg_tree

def build_seg_tree_helper(A, low, high, seg_tree, idx):
    if low == high:
        seg_tree[idx] = (A[low], A[low])
        return seg_tree[idx]
    mid = low + (high - low) / 2
    (left_min, left_max) = build_seg_tree_helper(A, low, mid, seg_tree, idx * 2)
    (right_min, right_max) = \
            build_seg_tree_helper(A, mid + 1, high, seg_tree, idx * 2 + 1)
    seg_tree[idx] = (min(left_min, right_min), max(left_max, right_max))
    return seg_tree[idx]

def range_query(seg_tree, n, qs, qe):
    """Return the minimum and maximum in the given range [qs, qe]."""
    if qe >= n or qs < 0:
        return float("inf")
    return range_query_helper(seg_tree, 0, n - 1, qs, qe, 1)

def range_query_helper(seg_tree, ss, se, qs, qe, idx):
    if ss >= qs and se <= qe:
        return seg_tree[idx]
    elif se < qs or ss > qe:
        return (float("inf"), float("-inf"))
    else:
        mid = ss + (se - ss) / 2
        (left_min, left_max) = \
                range_query_helper(seg_tree, ss, mid, qs, qe, idx * 2)
        (right_min, right_max) = \
                range_query_helper(seg_tree, mid + 1, se, qs, qe, idx * 2 + 1)
        return (min(left_min, right_min), max(left_max, right_max))

def count_bounded_slices(A, k):
    """ Count bounded slices O(n) solution.

    >>> count_bounded_slices([3,5,6,7,3], 2)
    9
    >>> count_bounded_slices([4,1,2,3,4,5,6,10,12], 4)
    30
    """
    N = len(A)
    count = 0
    seg_tree = build_seg_tree(A)
    j = 0
    for i in xrange(N):
        while j < N:
            range_min, range_max = range_query(seg_tree, N, i, j)
            if range_max - range_min <= k:
                j += 1
            else:
                break
        count += j - i
    return count

if __name__ == '__main__':
    import doctest
    doctest.testmod()
