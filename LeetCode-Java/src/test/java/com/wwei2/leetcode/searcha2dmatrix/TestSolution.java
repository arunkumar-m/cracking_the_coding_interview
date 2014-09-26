package com.wwei2.leetcode.searcha2dmatrix;

import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;
import org.junit.Test;

/**
 * Created by weiwei on 9/25/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test() {
    int[][] matrix = new int[][]{
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    assertTrue(sol.searchMatrix(matrix, 1));
    assertTrue(sol.searchMatrix(matrix, 3));
    assertTrue(sol.searchMatrix(matrix, 5));
    assertTrue(sol.searchMatrix(matrix, 7));
    assertTrue(sol.searchMatrix(matrix, 10));
    assertTrue(sol.searchMatrix(matrix, 11));
    assertTrue(sol.searchMatrix(matrix, 16));
    assertTrue(sol.searchMatrix(matrix, 20));
    assertTrue(sol.searchMatrix(matrix, 23));
    assertTrue(sol.searchMatrix(matrix, 30));
    assertTrue(sol.searchMatrix(matrix, 34));
    assertTrue(sol.searchMatrix(matrix, 50));
    assertFalse(sol.searchMatrix(matrix, 0));
    assertFalse(sol.searchMatrix(matrix, 100));
    assertFalse(sol.searchMatrix(matrix, 17));
    assertFalse(sol.searchMatrix(matrix, 8));
    assertFalse(sol.searchMatrix(matrix, 22));
  }
}
