#!/usr/bin/python
# -*- coding: utf-8 -*-

def count_bounded_slices(A, k):
    """ Count bounded slices O(n) solution.

    >>> count_bounded_slices([3,5,6,7,3], 2)
    9
    >>> count_bounded_slices([4,1,2,3,4,5,6,10,12], 4)
    30
    """
    N = len(A)
    min_queue = []
    max_queue = []
    count = 0
    j = 0
    for i in xrange(N):
        while j < N:
            while len(max_queue) > 0 and max_queue[-1][0] <= A[j]:
                max_queue.pop()
            max_queue.append((A[j], j))
            while len(min_queue) > 0 and min_queue[-1][0] >= A[j]:
                min_queue.pop()
            min_queue.append((A[j], j))
            if max_queue[0][0] - min_queue[0][0] <= k:
                j += 1
            else:
                break
        count += j - i
        if max_queue[0][1] == i:
            max_queue.pop(0)
        if min_queue[0][1] == i:
            min_queue.pop(0)
    return count

if __name__ == '__main__':
    import doctest
    doctest.testmod()
