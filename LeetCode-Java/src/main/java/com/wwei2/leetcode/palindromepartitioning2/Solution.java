package com.wwei2.leetcode.palindromepartitioning2;

/**
 * Given a string s, partition s such that every substring of the partition
 * is a palindrome.
 */
public class Solution {
  public int minCut(String s) {
    int length = s.length();
    boolean[][] isPal = new boolean[length][length];
    for (int j = 0; j < length; j++) {
      for (int i = 0; i <= j; i++) {
        if (i == j) {
          isPal[i][j] = true;
        } else if (s.charAt(i) == s.charAt(j) && (i + 1 == j || isPal[i + 1][j - 1])) {
          isPal[i][j] = true;
        } else {
          isPal[i][j] = false;
        }
      }
    }
    int[] min = new int[length + 1];
    for (int i = 0; i < length + 1; i++) {
      min[i] = length - i - 1;
    }
    for (int i = length - 1; i >= 0; i--) {
      for (int j = i; j < length; j++) {
        if (isPal[i][j]) {
          min[i] = Math.min(min[i], min[j + 1] + 1);
        }
      }
    }
    return min[0];
  }
}
