package com.wwei2.leetcode.sqrtx;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/26/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSimple() {
    for (int i = 0; i < 100; i++) {
      testHelper((int) Math.sqrt(i), i);
    }
  }

  @Test
  public void testBig() {
    testHelper(46340, Integer.MAX_VALUE);
  }

  private void testHelper(int expected, int input) {
    Assert.assertEquals(expected, sol.sqrt(input));
  }
}
