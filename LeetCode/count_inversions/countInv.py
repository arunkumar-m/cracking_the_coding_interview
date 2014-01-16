# count number of inversions for a given array

def readArray(filename):
    array = []
    with open(filename, 'r') as f:
        for line in f:
            array.append(int(line.strip()))
    return array

def sort_and_count(A):
    """Sort A and count the number of inversions inside A

    >>> sort_and_count([1, 3, 5, 2, 4, 6])
    ([1, 2, 3, 4, 5, 6], 3)
    >>> sort_and_count([5, 3, 1, 6, 4, 2])
    ([1, 2, 3, 4, 5, 6], 9)
    """
    if len(A) == 1:
        return A, 0
    else:
        B, x = sort_and_count(A[:len(A)/2])
        C, y = sort_and_count(A[len(A)/2:])
        D, z = merge_and_countSplitInv(B, C)
    return D, x + y + z

def merge_and_countSplitInv(B, C):
    """Merge B and C into D and count the number of inversions

    >>> merge_and_countSplitInv([1,3,5], [2,4,6])
    ([1, 2, 3, 4, 5, 6], 3)
    >>> merge_and_countSplitInv([1,3,5,7], [2,4,6,8])
    ([1, 2, 3, 4, 5, 6, 7, 8], 6)
    >>> merge_and_countSplitInv([1,3,5,7], [2,4,6])
    ([1, 2, 3, 4, 5, 6, 7], 6)

    """
    i = 0
    j = 0
    k = 0
    z = 0
    D = []
    while i < len(B) and j < len(C):
        if B[i] < C[j]:
            D.append(B[i])
            i += 1
        elif B[i] > C[j]:
            D.append(C[j])
            j += 1
            z += len(B[i:])
    D += B[i:]
    D += C[j:]
    return D, z

if __name__ == '__main__':
    "main program"
    # import doctest
    # doctest.testmod()
    array = readArray('IntegerArray.txt')
    print sort_and_count(array)[1]
