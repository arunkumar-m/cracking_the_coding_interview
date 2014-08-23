package com.wwei2.leetcode.singlenumber2;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 8/22/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSimple() {
    testHelper(new int[]{1, 1, 1, 2}, 2);
    testHelper(new int[]{2, 2, 1, 2}, 1);
    testHelper(new int[]{1, 2, 2, 2}, 1);
  }
  @Test
  public void testComplex() {
    testHelper(new int[]{100, 100, 1, 1, 1, 100, 2, 2, 4, 2, 4, 4, 107}, 107);
  }
  private void testHelper(int[] array, int expected) {
    int actual = sol.singleNumber(array);
    Assert.assertEquals(expected, actual);
  }
}
