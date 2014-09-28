package com.wwei2.leetcode.addbinary;

/**
 * Add binary.
 */
public class Solution {
  public String addBinary(String a, String b) {
    int ia = a.length() - 1;
    int ib = b.length() - 1;
    int carry = 0;
    StringBuilder sb = new StringBuilder();
    while (ia >= 0 || ib >= 0) {
      int digitA = ia >= 0 ? a.charAt(ia) - '0' : 0;
      int digitB = ib >= 0 ? b.charAt(ib) - '0' : 0;
      int sum = carry + digitA + digitB;
      carry = sum / 2;
      sb.insert(0, sum % 2);
      ia--;
      ib--;
    }
    if (carry == 1) {
      sb.insert(0, "1");
    }
    return sb.toString();
  }
}
