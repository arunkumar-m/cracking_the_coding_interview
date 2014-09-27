package com.wwei2.leetcode.plusone;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/27/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSimple() {
    int[] arr = new int[]{0};
    sol.plusOne(arr);
    Assert.assertEquals(1, arr.length);
    Assert.assertEquals(1, arr[0]);
  }
}
