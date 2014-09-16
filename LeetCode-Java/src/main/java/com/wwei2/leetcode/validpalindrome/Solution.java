package com.wwei2.leetcode.validpalindrome;

/**
 * Valid palindrome.
 */
public class Solution {
  public boolean isPalindrome(String s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
      while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
        left++;
      }
      while (right > left && !Character.isLetterOrDigit(s.charAt(right))) {
        right--;
      }
      if (Character.toUpperCase(s.charAt(left)) != Character.toUpperCase(s.charAt(right))) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
}