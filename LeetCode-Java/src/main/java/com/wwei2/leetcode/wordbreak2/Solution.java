package com.wwei2.leetcode.wordbreak2;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

/**
 * Created by weiwei on 8/25/14.
 */
public class Solution {
  public List<String> wordBreak(String s, Set<String> dict) {
    int length = s.length();
    boolean[] dp = new boolean[length];
    for (int i = 0; i < length; i++) {
      if (dict.contains(s.substring(0, i + 1))) {
        dp[i] = true;
      } else {
        for (int j = 0; j < i; j++) {
          if (dp[j] == true && dict.contains(s.substring(j + 1, i + 1))) {
            dp[i] = true;
            break;
          }
        }
      }
    }
    // Backtrack.
    List<String> results = backtrack(dp, length - 1, s, dict);
    return results;
  }

  private List<String> backtrack(boolean[] dp, int i, String s, Set<String> dict) {
    List<String> results = new ArrayList<>();
    if (dp[i] == false) {
      return results;
    }
    if (dict.contains(s.substring(0, i + 1))) {
      results.add(s.substring(0, i + 1));
    }
    for (int j = 0; j < i; j++) {
      if (dp[j] == true && dict.contains(s.substring(j + 1, i + 1))) {
        List<String> prevs = backtrack(dp, j, s, dict);
        String str = s.substring(j + 1 ,i + 1);
        for (String prev : prevs) {
          results.add(prev + " " + str);
        }
      }
    }
    return results;
  }
}
