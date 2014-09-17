package com.wwei2.leetcode.besttimetobuyandsellstock3;

/**
 * Best time to buy and sell stock III. (Dynamic Programming)
 */
public class Solution {
  public int maxProfit(int[] prices) {
    int length = prices.length;
    int[] maxLeft = new int[length];
    int[] maxRight = new int[length];
    int maxSoFar = 0;
    int minValue = Integer.MAX_VALUE;
    for (int i = 0; i < length; i++) {
      minValue = Math.min(minValue, prices[i]);
      maxSoFar = Math.max(maxSoFar, prices[i] - minValue);
      maxLeft[i] = maxSoFar;
    }
    maxSoFar = 0;
    int maxValue = 0;
    for (int i = length - 1; i >= 0; i--) {
      maxValue = Math.max(maxValue, prices[i]);
      maxSoFar = Math.max(maxSoFar, maxValue - prices[i]);
      maxRight[i] = maxSoFar;
    }
    maxSoFar = 0;
    for (int i = 0; i < length - 1; i++) {
      maxSoFar = Math.max(maxSoFar, maxLeft[i] + maxRight[i]);
    }
    return maxSoFar;
  }
}
