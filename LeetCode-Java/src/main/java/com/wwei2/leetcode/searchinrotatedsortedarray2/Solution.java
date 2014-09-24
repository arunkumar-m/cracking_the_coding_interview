package com.wwei2.leetcode.searchinrotatedsortedarray2;

/**
 * Search in rotated sorted array 2.
 */
public class Solution {
  public boolean search(int[] A, int target) {
    int left = 0;
    int right = A.length - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (target == A[mid] || target == A[left] || target == A[right]) {
        return true;
      }
      if (A[mid] < A[right]) {
        if (target > A[mid] && target < A[right]) {
          left = mid + 1;
          right = right - 1;
        } else {
          left = left + 1;
          right = mid - 1;
        }
      } else if (A[left] < A[mid]) {
        if (target > A[left] && target < A[mid]) {
          left = left + 1;
          right = mid - 1;
        } else {
          left = mid + 1;
          right = right - 1;
        }
      } else {
        left++;
      }
    }
    return false;
  }
}
