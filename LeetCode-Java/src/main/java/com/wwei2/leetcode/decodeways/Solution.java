package com.wwei2.leetcode.decodeways;

/**
 * Decode ways.
 */
public class Solution {
  public int numDecodings(String s) {
    int length = s.length();
    if (length == 0) {
      return 0;
    }
    int[] dp = new int[length];
    if (s.charAt(0) != '0') {
      dp[0] = 1;
    }
    for (int i = 1; i < length; i++) {
      // One characters.
      if (s.charAt(i) != '0') {
        dp[i] = dp[i - 1];
      }
      // Two characters.
      int tmp = Integer.parseInt(s.substring(i - 1, i + 1));
      if (tmp >= 10 && tmp <= 26) {
        if (i - 2 >= 0) {
          dp[i] += dp[i - 2];
        } else {
          dp[i] += 1;
        }
      }
    }
    return dp[length - 1];
  }
}
