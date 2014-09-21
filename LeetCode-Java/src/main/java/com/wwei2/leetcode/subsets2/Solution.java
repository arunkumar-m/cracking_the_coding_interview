package com.wwei2.leetcode.subsets2;

import java.util.*;

/**
 * Subsets II.
 */
public class Solution {
  public List<List<Integer>> subsetsWithDup(int[] num) {
    Arrays.sort(num);
    List<List<Integer>> results = new ArrayList<>();
    results.add(new ArrayList<Integer>());
    Map<Integer, Integer> count = new TreeMap<>();
    for (int i = 0; i < num.length; i++) {
      if (count.containsKey(num[i])) {
        count.put(num[i], count.get(num[i]) + 1);
      } else {
        count.put(num[i], 1);
      }
    }
    for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
      int number = entry.getKey();
      int cnt = entry.getValue();
      int size = results.size();
      for (int s = 0; s < size; s++) {
        for (int j = 0; j < cnt; j++) {
          List<Integer> tmp = new ArrayList<>(results.get(s));
          for (int k = 0; k <= j; k++) {
            tmp.add(number);
          }
          results.add(tmp);
        }
      }
    }
    return results;
  }
}
