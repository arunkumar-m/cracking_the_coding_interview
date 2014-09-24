package com.wwei2.leetcode.maximumproductsubarray;

/**
 * Maximum Product Subarray.
 */
public class Solution {
  public int maxProduct(int[] A) {
    if (A == null || A.length == 0) {
      return 0;
    }
    int[] maxVal = new int[A.length];
    int[] minVal = new int[A.length];
    maxVal[0] = A[0];
    minVal[0] = A[0];
    int maxSoFar = A[0];
    for (int i = 1; i < A.length; i++) {
      maxVal[i] = Math.max(A[i], Math.max(maxVal[i - 1] * A[i], minVal[i - 1] * A[i]));
      minVal[i] = Math.min(A[i], Math.min(maxVal[i - 1] * A[i], minVal[i - 1] * A[i]));
      maxSoFar = Math.max(maxSoFar, maxVal[i]);
    }
    return maxSoFar;
  }
}
