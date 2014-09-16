package com.wwei2.leetcode.besttimetobuyandsellstock2;

/**
 * Best time to buy and sell stock II.
 */
public class Solution {
  public int maxProfit(int[] prices) {
    int sum = 0;
    for (int i = 0; i < prices.length - 1; i++) {
      int diff = prices[i + 1] - prices[i];
      if (diff > 0) {
        sum += diff;
      }
    }
    return sum;
  }
}
