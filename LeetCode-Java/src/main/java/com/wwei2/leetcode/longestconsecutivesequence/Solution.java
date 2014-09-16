package com.wwei2.leetcode.longestconsecutivesequence;

import java.util.HashSet;
import java.util.Set;

/**
 * Longest Consecutive Sequence.
 */
public class Solution {
  public int longestConsecutive(int[] num) {
    Set<Integer> set = new HashSet<>();
    for (int i : num) {
      set.add(i);
    }
    Set<Integer> visited = new HashSet<>();
    int maxSoFar = 1;
    for (int i = 0; i < num.length; i++) {
      if (!visited.contains(num[i])) {
        visited.add(num[i]);
        int cnt = 1;
        int curr = num[i] + 1;
        while (set.contains(curr)) {
          visited.add(curr);
          curr += 1;
          cnt += 1;
        }
        curr = num[i] - 1;
        while (set.contains(curr)) {
          visited.add(curr);
          curr -= 1;
          cnt += 1;
        }
        maxSoFar = Math.max(maxSoFar, cnt);
      }
    }
    return maxSoFar;
  }
}
