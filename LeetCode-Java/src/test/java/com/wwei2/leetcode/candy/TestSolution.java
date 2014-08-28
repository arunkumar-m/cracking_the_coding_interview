package com.wwei2.leetcode.candy;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 8/28/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall1() {
    testHelper(new int[]{4, 1, 3, 2, 5}, 8);
  }
  @Test
  public void testSmall2() {
    testHelper(new int[]{4, 2, 3, 4, 1}, 9);
  }
  private void testHelper(int[] ratings, int expected) {
    int actual = sol.candy(ratings);
    Assert.assertEquals(expected, actual);
  }
}
