package com.wwei2.leetcode.besttimetobuyandsellstock;

/**
 * Best time to buy and sell stock.
 */
public class Solution {
  public int maxProfit(int[] prices) {
    int length = prices.length;
    int min = Integer.MAX_VALUE;
    int bestProfit = 0;
    for (int i = 0; i < length; i++) {
      min = Math.min(min, prices[i]);
      bestProfit = Math.max(bestProfit, prices[i] - min);
    }
    return bestProfit;
  }
}
