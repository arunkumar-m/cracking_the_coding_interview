package com.wwei2.leetcode.interleavingstring;

import java.util.Arrays;

/**
 * Interleaving string.
 */
public class Solution {
  public boolean isInterleave(String s1, String s2, String s3) {
    String combined = s1 + s2;
    if (combined.length() != s3.length()) {
      return false;
    }
    boolean[][] dp = new boolean[s1.length() + 1][s2.length() + 1];
    dp[0][0] = true;
    for (int i = 1; i < s2.length() + 1; i++) {
      dp[0][i] = dp[0][i - 1] && s2.charAt(i - 1) == s3.charAt(i - 1);
    }
    for (int i = 1; i < s1.length() + 1; i++) {
      dp[i][0] = dp[i - 1][0] && s1.charAt(i - 1) == s3.charAt(i - 1);
    }
    for (int i = 1; i < s1.length() + 1; i++) {
      for (int j = 1; j < s2.length() + 1; j++) {
        char c1 = s1.charAt(i - 1);
        char c2 = s2.charAt(j - 1);
        char c3 = s3.charAt(i + j - 1);
        if (c1 == c3 && c2 == c3) {
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        } else if (c1 == c3) {
          dp[i][j] = dp[i - 1][j];
        } else if (c2 == c3) {
          dp[i][j] = dp[i][j - 1];
        } else {
          dp[i][j] = false;
        }
      }
    }
    return dp[s1.length()][s2.length()];
  }
}
