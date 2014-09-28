package com.wwei2.leetcode.minimumpathsum;

/**
 * Minimum path sum.
 */
public class Solution {
  public int minPathSum(int[][] grid) {
    int numRows = grid.length;
    int numCols = numRows == 0 ? 0 : grid[0].length;
    int[][] dp = new int[numRows][numCols];
    if (numRows > 0 && numCols > 0) {
      dp[0][0] = grid[0][0];
    } else {
      return 0;
    }
    for (int i = 1; i < numRows; i++) {
      dp[i][0] += dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < numCols; i++) {
      dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < numRows; i++) {
      for (int j = 1; j < numCols; j++) {
        dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }
    return dp[numRows - 1][numCols - 1];
  }
}
