package com.wwei2.leetcode.mergesortedarray;

/**
 * Merge sorted array.
 */
public class Solution {
  public void merge(int A[], int m, int B[], int n) {
    int a = m - 1, b = n - 1;
    for (int i = m + n - 1; i >= 0; i--) {
      if ((a >= 0 && b >= 0 && A[a] >= B[b]) || b < 0) {
        A[i] = A[a];
        a--;
      } else {
        A[i] = B[b];
        b--;
      }
    }
  }
}
