package com.wwei2.leetcode.spiralmatrix2;

/**
 * Spiral matrix.
 */
public class Solution {
  public int[][] generateMatrix(int n) {
    int[][] result = new int[n][n];
    generateMatrixHelper(result, 0, 0, n, n, 0);
    return result;
  }

  private void generateMatrixHelper(int[][] result, int x, int y, int r, int c, int v) {
    if (r == 0 || c == 0) {
      return;
    }
    if (r == 1) {
      for (int i = 0; i < c; i++) {
        result[x][y + i] = ++v;
      }
      return;
    }
    if (c == 1) {
      for (int i = 0; i < r; i++) {
        result[y][x + i] = ++v;
      }
      return;
    }
    // From (x, y) to (x, y + c - 1)
    for (int i = y; i < y + c; i++) {
      result[x][i] = ++v;
    }
    // From (x + 1, y + c - 1) to (x + r - 1, y + c - 1)
    for (int i = x + 1; i < x + r; i++) {
      result[i][y + c - 1] = ++v;
    }
    // From (x + r - 1, y + c - 2) to (x + r - 1, y)
    for (int i = y + c - 2; i >= y; i--) {
      result[x + r - 1][i] = ++v;
    }
    // From (x + r - 2, y) to (x + 1, y)
    for (int i = x + r - 2; i >= x + 1; i--) {
      result[i][y] = ++v;
    }
    generateMatrixHelper(result, x + 1, y + 1, r - 2, c - 2, v);
  }
}
