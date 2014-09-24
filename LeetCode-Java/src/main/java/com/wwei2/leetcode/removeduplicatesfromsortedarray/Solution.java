package com.wwei2.leetcode.removeduplicatesfromsortedarray;

/**
 * Remove duplicates from sorted array.
 */
public class Solution {
  public int removeDuplicates(int[] A) {
    if (A == null || A.length == 0) {
      return 0;
    }
    int prevValue = A[0] - 1, curr = 0;
    int pivotIndex = -1;
    while (curr < A.length) {
      int value = A[curr];
      if (value != prevValue) {
        pivotIndex++;
        A[pivotIndex] = value;
        prevValue = value;
      }
      curr++;
    }
    return pivotIndex + 1;
  }
}
