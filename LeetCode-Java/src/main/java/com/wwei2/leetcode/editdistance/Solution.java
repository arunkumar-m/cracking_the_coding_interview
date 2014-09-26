package com.wwei2.leetcode.editdistance;

/**
 * Edit distance.
 */
public class Solution {
  public int minDistance(String word1, String word2) {
    int[][] dp = new int[word1.length() + 1][word2.length() + 1];
    for (int i = 0; i < word1.length() + 1; i++) {
      dp[i][0] = i;
    }
    for (int i = 0; i < word2.length() + 1; i++) {
      dp[0][i] = i;
    }
    for (int i = 1; i < word1.length() + 1; i++) {
      for (int j = 1; j < word2.length() + 1; j++) {
        int penalty = word1.charAt(i - 1) == word2.charAt(j - 1) ? 0 : 1;
        dp[i][j] = Math.min(penalty + dp[i - 1][j - 1], Math.min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
      }
    }
    return dp[word1.length()][word2.length()];
  }
}
