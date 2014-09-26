package com.wwei2.leetcode.setmatrixzeroes;

/**
 * Set matrix zeroes.
 */
public class Solution {
  public void setZeroes(int[][] matrix) {
    int length = matrix.length;
    int width = length == 0 ? 0 : matrix[0].length;
    boolean[] rows = new boolean[length];
    boolean[] cols = new boolean[width];
    for (int i = 0; i < length; i++) {
      for (int j = 0; j < width; j++) {
        if (matrix[i][j] == 0) {
          rows[i] = true;
          cols[j] = true;
        }
      }
    }
    for (int i = 0; i < length; i++) {
      if (rows[i]) {
        for (int j = 0; j < width; j++) {
          matrix[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < width; i++) {
      if (cols[i]) {
        for (int j = 0; j < length; j++) {
          matrix[j][i] = 0;
        }
      }
    }
  }
}
