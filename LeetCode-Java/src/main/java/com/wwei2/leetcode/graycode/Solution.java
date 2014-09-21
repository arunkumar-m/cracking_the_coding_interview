package com.wwei2.leetcode.graycode;

import java.util.ArrayList;
import java.util.List;

/**
 * Gray code.
 */
public class Solution {
  public List<Integer> grayCode(int n) {
    List<Integer> results = new ArrayList<>();
    results.add(0);
    if (n == 0) {
      return results;
    }
    results.add(1);
    for (int i = 2; i <= n; i++) {
      int size = results.size();
      for (int j = size - 1; j >= 0; j--) {
        int tmp = results.get(j);
        results.add(results.get(j) + (int) Math.pow(2, i - 1));
      }
    }
    return results;
  }
}
