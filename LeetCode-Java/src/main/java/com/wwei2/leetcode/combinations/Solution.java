package com.wwei2.leetcode.combinations;

import java.util.ArrayList;
import java.util.List;

/**
 * Combinations.
 */
public class Solution {
  public List<List<Integer>> combine(int n, int k) {
    if (n < k) {
      return new ArrayList<>();
    }
    if (k == 0) {
      return new ArrayList<List<Integer>>() {{
        add(new ArrayList<Integer>());
      }};
    }
    List<List<Integer>> ret = new ArrayList<>();
    List<List<Integer>> result1 = combine(n - 1, k);
    List<List<Integer>> result2 = combine(n - 1, k - 1);
    for (List<Integer> list : result2) {
      list.add(n);
    }
    ret.addAll(result1);
    ret.addAll(result2);
    return ret;
  }
}
