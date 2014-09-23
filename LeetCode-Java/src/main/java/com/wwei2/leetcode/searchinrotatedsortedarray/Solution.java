package com.wwei2.leetcode.searchinrotatedsortedarray;

/**
 * Search in rotated sorted array.
 */
public class Solution {
  public int search(int[] A, int target) {
    int low = 0;
    int high = A.length - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (target == A[mid]) {
        return mid;
      }
      if (A[low] <= A[mid]) {
        if (target >= A[low] && target < A[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else if (A[mid] < A[high]) {
        if (target > A[mid] && target <= A[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    }
    return -1;
  }
}
