package com.wwei2.leetcode.triangle;

import java.util.List;

/**
 * Triangle. O(n) space.
 */
public class Solution {
  public int minimumTotal(List<List<Integer>> triangle) {
    int length = triangle.size();
    if (length == 0) {
      return 0;
    }
    int[] total = new int[length];
    total[0] = triangle.get(0).get(0);
    for (int i = 1; i < length; i++) {
      for (int j = i; j >= 0; j--) {
        int value = triangle.get(i).get(j);
        if (j == 0) {
          total[j] = value + total[j];
        } else if (j == i) {
          total[j] = value + total[j - 1];
        } else {
          total[j] = value + Math.min(total[j], total[j - 1]);
        }
      }
    }
    int minSoFar = Integer.MAX_VALUE;
    for (int i = 0; i < length; i++) {
      minSoFar = Math.min(minSoFar, total[i]);
    }
    return minSoFar;
  }
}
