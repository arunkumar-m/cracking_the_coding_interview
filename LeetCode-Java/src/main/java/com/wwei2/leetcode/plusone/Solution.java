package com.wwei2.leetcode.plusone;

/**
 * Plus one.
 */
public class Solution {
  public int[] plusOne(int[] digits) {
    int carry = 1;
    for (int i = digits.length - 1; i >= 0; i--) {
      int digit = digits[i];
      digits[i] = (carry + digit) % 10;
      carry = (carry + digit) / 10;
    }
    if (carry == 0) {
      return digits;
    } else {
      int[] ret = new int[digits.length + 1];
      for (int i = ret.length - 1; i > 0; i--) {
        ret[i] = digits[i - 1];
      }
      ret[0] = 1;
      return ret;
    }
  }
}
