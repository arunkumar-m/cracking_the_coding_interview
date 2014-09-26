package com.wwei2.leetcode.sqrtx;

/**
 * Sqrt(x).
 */
public class Solution {
  public int sqrt(int x) {
    double y = 1;
    while (Math.abs(y * y - x) > 10e-3) {
      y = (y * y + x) / 2 / y;
    }
    return (int) y;
  }
}
