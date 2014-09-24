package com.wwei2.leetcode.maximumproductsubarray;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/24/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test1() {
    Assert.assertEquals(6, sol.maxProduct(new int[]{2, 3, -2, 4}));
    Assert.assertEquals(48, sol.maxProduct(new int[]{2, 3, -2, -4}));
    Assert.assertEquals(48, sol.maxProduct(new int[]{2, 3, -2, -4, -1}));
  }
  @Test
  public void test2() {
    Assert.assertEquals(30, sol.maxProduct(new int[]{2, 3, 0, 5, 5, 0, -3, -10, -1, -1, 0}));
  }
  @Test
  public void test3() {
    Assert.assertEquals(-2, sol.maxProduct(new int[]{-2}));
  }
}
