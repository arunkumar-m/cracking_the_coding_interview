package com.wwei2.leetcode.sortcolors;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/24/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test() {
    int[] A = new int[]{0, 2, 1, 1, 2, 0};
    sol.sortColors(A);
    Assert.assertArrayEquals(new int[]{0, 0, 1, 1, 2, 2}, A);
  }
}
