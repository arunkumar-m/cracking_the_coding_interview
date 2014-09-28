package com.wwei2.leetcode.lengthoflastword;

/**
 * Length of Last Word.
 */
public class Solution {
  public int lengthOfLastWord(String s) {
    int prevLength = 0;
    int currLength = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s.charAt(i) == ' ') {
        prevLength = currLength == 0 ? prevLength : currLength;
        currLength = 0;
      } else {
        currLength++;
      }
    }
    return currLength == 0 ? prevLength : currLength;
  }
}
