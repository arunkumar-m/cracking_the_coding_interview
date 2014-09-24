package com.wwei2.leetcode.removeduplicatesfromsortedarray2;

/**
 * Remove duplicates from sorted array II.
 */
public class Solution {
  public int removeDuplicates(int[] A) {
    if (A == null || A.length == 0) {
      return 0;
    }
    int pivotIndex = -1;
    int prevValue = A[0] - 1;
    int curr = 0;
    int cnt = 0;
    while (curr < A.length) {
      int currValue = A[curr];
      if (currValue != prevValue) {
        cnt = 1;
        pivotIndex++;
        A[pivotIndex] = currValue;
        prevValue = currValue;
      } else {
        cnt++;
        if (cnt == 2) {
          pivotIndex++;
          A[pivotIndex] = currValue;
        }
      }
      curr++;
    }
    return pivotIndex + 1;
  }
}
