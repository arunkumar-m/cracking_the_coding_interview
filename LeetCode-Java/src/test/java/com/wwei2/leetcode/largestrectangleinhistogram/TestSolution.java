package com.wwei2.leetcode.largestrectangleinhistogram;

import org.junit.Assert;
import org.junit.Test;

/**
 * Largest rectangle in histogram.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test0() {
    Assert.assertEquals(0, sol.largestRectangleArea(new int[]{}));
  }
  @Test
  public void test1() {
    Assert.assertEquals(1, sol.largestRectangleArea(new int[]{1}));
  }
  @Test
  public void test2() {
    Assert.assertEquals(10, sol.largestRectangleArea(new int[]{2, 1, 5, 6, 2, 3}));
  }
  @Test
  public void test3() {
    Assert.assertEquals(2147483647,
        sol.largestRectangleArea(new int[]{2147483647, 0, 2147483647, 0, 2147483647, 0, 2147483647, 0, 2147483647, 0}));
  }
  @Test
  public void test4() {
    Assert.assertEquals(3, sol.largestRectangleArea(new int[]{2, 1, 2}));
  }

  @Test
  public void test5() {
    Assert.assertEquals(6, sol.largestRectangleArea(new int[]{4, 2, 0, 3, 2, 5}));
  }
}
