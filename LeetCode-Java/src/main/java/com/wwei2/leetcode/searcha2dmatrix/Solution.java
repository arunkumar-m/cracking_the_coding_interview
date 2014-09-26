package com.wwei2.leetcode.searcha2dmatrix;

/**
 * Search a 2D Matrix.
 */
public class Solution {
  public boolean searchMatrix(int[][] matrix, int target) {
    int imin = 0, imax = matrix.length - 1;
    while (imin < imax) {
      int imid = imin + (imax - imin) / 2;
      if (matrix[imid][0] < target) {
        imin = imid + 1;
      } else {
        imax = imid;
      }
    }
    int index = imin - 1;
    if (imin == 0 || matrix[imin][0] <= target) {
      index = imin;
    }
    int left = 0; int right = matrix[index].length - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (target == matrix[index][mid]) {
        return true;
      } else if (target > matrix[index][mid]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
}
