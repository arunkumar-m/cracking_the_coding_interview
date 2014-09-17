package com.wwei2.leetcode.besttimetobuyandsellstock3;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/16/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall() {
    Assert.assertEquals(3, sol.maxProfit(new int[]{1, 2, 4}));
  }
}
