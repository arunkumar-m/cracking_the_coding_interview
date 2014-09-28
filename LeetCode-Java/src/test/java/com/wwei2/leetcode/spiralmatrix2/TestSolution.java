package com.wwei2.leetcode.spiralmatrix2;

import org.junit.Test;

/**
 * Created by weiwei on 9/27/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSimple() {
    printMatrix(sol.generateMatrix(1));
    printMatrix(sol.generateMatrix(2));
    printMatrix(sol.generateMatrix(3));
    printMatrix(sol.generateMatrix(4));
    printMatrix(sol.generateMatrix(5));
  }

  private void printMatrix(int[][] matrix) {
    System.out.println("#### #### #### ####");
    int r = matrix.length;
    int c = r == 0 ? 0 : matrix[0].length;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        System.out.print(matrix[i][j] + ", ");
      }
      System.out.println("");
    }
    System.out.println("#### #### #### ####");
  }
}
