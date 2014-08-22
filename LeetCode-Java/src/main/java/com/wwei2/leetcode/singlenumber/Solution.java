package com.wwei2.leetcode.singlenumber;

/**
 * Given an array of integers, every element appears twice except for one.
 */
public class Solution {
  public int singleNumber(int[] A) {
    int x = 0;
    for (int i = 0; i < A.length; i++) {
      x ^= A[i];
    }
    return x;
  }
}
