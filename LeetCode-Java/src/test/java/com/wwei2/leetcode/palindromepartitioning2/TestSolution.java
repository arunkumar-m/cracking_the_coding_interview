package com.wwei2.leetcode.palindromepartitioning2;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/15/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test1() {
    Assert.assertEquals(1, sol.minCut("aab"));
  }
  @Test
  public void test2() {
    Assert.assertEquals(0, sol.minCut("12321"));
  }
  @Test
  public void test3() {
    Assert.assertEquals(4, sol.minCut("12345"));
  }
}
