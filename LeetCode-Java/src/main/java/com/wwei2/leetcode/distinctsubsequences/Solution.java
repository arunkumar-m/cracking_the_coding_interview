package com.wwei2.leetcode.distinctsubsequences;

/**
 * Distinct subsequences. Dynamic programming.
 */
public class Solution {
  public int numDistinct(String S, String T) {
    int sLength = S.length();
    int tLength = T.length();
    int[][] dp = new int[tLength + 1][sLength + 1];
    for (int i = 0; i < sLength + 1; i++) {
      dp[0][i] = 1;
    }
    for (int i = 1; i < tLength + 1; i++) {
      for (int j = 1; j < sLength + 1; j++) {
        if (S.charAt(j - 1) != T.charAt(i - 1)) {
          dp[i][j] = dp[i][j - 1];
        } else {
          dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        }
      }
    }
    return dp[tLength][sLength];
  }
}
