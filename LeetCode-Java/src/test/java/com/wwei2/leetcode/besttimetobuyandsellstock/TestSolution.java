package com.wwei2.leetcode.besttimetobuyandsellstock;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/16/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test1() {
    testBestProfit(2, new int[]{2, 1, 3});
  }
  @Test
  public void test2() {
    testBestProfit(1, new int[]{3, 1, 2});
  }
  @Test
  public void test3() {
    testBestProfit(5, new int[]{5, 8, 6, 9, 7, 10, 1, 3, 4, 2});
  }

  private void testBestProfit(int expected, int[] prices) {
    Assert.assertEquals(expected, sol.maxProfit(prices));
  }
}
