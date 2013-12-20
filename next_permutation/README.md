# Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

## Solution

    Scan from the back of the vector.
    Find the index i you first run into where num[i + 1] > num[i].
    If the index is 0:
      simply reverse the whole vector.
    If the index is not 0:
      swap the element at index i with the smallest element that is larger than the element at index i.
      reverse all the elements after index i
