package com.wwei2.leetcode.subsets;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Subsets.
 */
public class Solution {
  public List<List<Integer>> subsets(int[] S) {
    Arrays.sort(S);
    List<List<Integer>> results = new ArrayList<>();
    results.add(new ArrayList<Integer>());
    for (int i = 0; i < S.length; i++) {
      int size = results.size();
      for (int j = 0; j < size; j++) {
        List<Integer> tmp = new ArrayList<>(results.get(j));
        tmp.add(S[i]);
        results.add(tmp);
      }
    }
    return results;
  }
}
