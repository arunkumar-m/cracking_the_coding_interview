package com.wwei2.leetcode.maximalrectangle;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/23/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test() {
    char[][] matrix = new char[6][];
    matrix[0] = new char[]{'1', '0', '0', '0', '0', '0', '1'};
    matrix[1] = new char[]{'1', '0', '1', '0', '1', '0', '1'};
    matrix[2] = new char[]{'1', '0', '1', '1', '1', '0', '1'};
    matrix[3] = new char[]{'1', '0', '1', '1', '1', '0', '1'};
    matrix[4] = new char[]{'1', '1', '1', '1', '1', '0', '1'};
    matrix[5] = new char[]{'1', '1', '1', '1', '1', '1', '1'};
    Assert.assertEquals(12, sol.maximalRectangle(matrix));
  }
}
