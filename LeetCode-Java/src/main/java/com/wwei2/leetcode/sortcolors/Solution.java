package com.wwei2.leetcode.sortcolors;

/**
 * Sort colors.
 */
public class Solution {
  public void sortColors(int[] A) {
    onePass(A);
  }

  private void countingSort(int[] A) {
    int[] count = new int[3];
    for (int i = 0; i < A.length; i++) {
      count[A[i]]++;
    }
    for (int i = 0; i < count[0]; i++) {
      A[i] = 0;
    }
    for (int i = count[0]; i < count[0] + count[1]; i++) {
      A[i] = 1;
    }
    for (int i = count[0] + count[1]; i < A.length; i++) {
      A[i] = 2;
    }
  }

  private void onePass(int[] A) {
    int left = -1;
    int right = A.length;
    int i = 0;
    while (i < right) {
      if (i > left && A[i] == 0) {
        left++;
        swap(A, left, i);
      } else if (i < right && A[i] == 2) {
        right--;
        swap(A, right, i);
      } else {
        i++;
      }
    }
  }

  private void swap(int[] A, int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
  }
}
