package com.wwei2.leetcode.minimumpathsum;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/27/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test() {
    int[][] grid = new int[][]{
        {1, 10, 10, 10},
        {1, 1, 10, 10},
        {10, 1, 1, 1}
    };
    Assert.assertEquals(6, sol.minPathSum(grid));
  }
}
