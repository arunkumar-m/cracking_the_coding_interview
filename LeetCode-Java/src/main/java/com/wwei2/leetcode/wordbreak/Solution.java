package com.wwei2.leetcode.wordbreak;

import java.util.Set;

/**
 * Word break.
 */
public class Solution {
  public boolean wordBreak(String s, Set<String> dict) {
    boolean[] dp = new boolean[s.length()];
    for (int i = 0; i < s.length(); i++) {
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
    return dp[s.length() - 1];
  }
}
