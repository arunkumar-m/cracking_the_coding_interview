#!/usr/bin/python
# -*- coding: utf-8 -*-

import math

def build_seg_tree(array):
    N = len(array)
    height = int(math.ceil(math.log(N) / math.log(2)))
    length = 2 * 2 ** (height)
    seg_tree = list([float('inf')] * length)
    build_seg_tree_helper(array, 0, N - 1, seg_tree, 1)
    return seg_tree

def build_seg_tree_helper(array, start, end, seg_tree, idx):
    if start == end:
        seg_tree[idx] = array[start]
        return seg_tree[idx]
    mid = start + (end - start) / 2
    left_min = build_seg_tree_helper(array, start, mid, seg_tree, idx * 2)
    right_min = build_seg_tree_helper(array, mid + 1, end, seg_tree, idx * 2 + 1)
    seg_tree[idx] = min(left_min, right_min)
    return seg_tree[idx]

def rmq(seg_tree, n, qs, qe):
    if qs < 0 or qe >= len(seg_tree) or qs > qe:
        return float("inf")
    return rmq_helper(seg_tree, 0, n - 1, qs, qe, 1)

def rmq_helper(seg_tree, ss, se, qs, qe, idx):
    if ss >= qs and se <= qe:
        return seg_tree[idx]
    elif se < qs or ss > qe:
        return float("inf")
    else:
        mid = ss + (se - ss) / 2
        return min(rmq_helper(seg_tree, ss, mid, qs, qe, idx * 2),
                rmq_helper(seg_tree, mid + 1, se, qs, qe, idx * 2 + 1))

if __name__ == '__main__':
    seg_tree = build_seg_tree([2, 5, 1, 4, 9, 3])
    print rmq(seg_tree, 6, 1, 3) == 1
    print rmq(seg_tree, 6, 0, 1) == 2
    print rmq(seg_tree, 6, 3, 5) == 3
    print rmq(seg_tree, 6, 0, 5) == 1
    print rmq(seg_tree, 6, 3, 4) == 4
