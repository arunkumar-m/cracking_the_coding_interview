package com.wwei2.leetcode.editdistance;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/25/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSingle() {
    Assert.assertEquals(0, sol.minDistance("a", "a"));
    Assert.assertEquals(1, sol.minDistance("a", "b"));
  }
  @Test
  public void testTwo() {
    Assert.assertEquals(0, sol.minDistance("ac", "ac"));
    Assert.assertEquals(1, sol.minDistance("ac", "bc"));
    Assert.assertEquals(1, sol.minDistance("ac", "abc"));
  }
}
