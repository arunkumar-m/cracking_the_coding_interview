package com.wwei2.leetcode.gasstation;

/**
 * Gas station.
 */
public class Solution {
  public int canCompleteCircuit(int[] gas, int[] cost) {
    int num = gas.length;
    int pos = -1;
    int[] dp = new int[num];
    dp[0] = gas[0] - cost[0];
    if (dp[0] < 0) {
      pos = 0;
    }
    int sum = gas[0] - cost[0];
    for (int i = 1; i < num; i++) {
      sum += gas[i] - cost[i];
      if (dp[i - 1] >= 0 && dp[i - 1] + gas[i] - cost[i] >= 0) {
        dp[i] = dp[i - 1] + gas[i] - cost[i];
      } else {
        dp[i] = gas[i] - cost[i];
      }
      if (dp[i] < 0) {
        pos = i;
      }
    }
    if (sum >= 0) {
      return pos == num ? -1 : pos + 1;
    } else {
      return -1;
    }
  }
}
