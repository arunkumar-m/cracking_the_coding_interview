package com.wwei2.leetcode.singlenumber;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 8/21/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test3() {
    testHelper(new int[]{1, 1, 2}, 2);
    testHelper(new int[]{2, 1, 2}, 1);
  }
  private void testHelper(int[] A, int expected) {
    int actual = sol.singleNumber(A);
    Assert.assertEquals(expected, actual);
  }
}
