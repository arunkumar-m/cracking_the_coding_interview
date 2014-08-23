package com.wwei2.leetcode.singlenumber2;

/**
 * Given an array of integers, every element appears three times except for
 * one. Find that one.
 */
public class Solution {
  private static final int NUMBITS = 32;
  // For bit i, if i % 3 == 0, the unique element doesn't have this bit set
  // to 1. If i % 3 == 1, the unique element has this bit set to 1.
  public int singleNumber(int[] A) {
    int[] counts = new int[NUMBITS];
    for (int i = 0; i < A.length; i++) {
      for (int j = 0; j < NUMBITS; j++) {
        counts[j] += (A[i] & (0x1 << j)) >> j;
      }
    }
    int number = 0;
    for (int i = 0; i < NUMBITS; i++) {
      number += (counts[i] % 3) * Math.pow(2, i);
    }
    return number;
  }
}