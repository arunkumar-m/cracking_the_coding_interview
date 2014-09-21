package com.wwei2.leetcode.scramblestring;

import java.util.Arrays;

/**
 * Scramble string.
 */
public class Solution {
  private String s1, s2;
  public boolean isScramble(String s1, String s2) {
    this.s1 = s1;
    this.s2 = s2;
    return isScrambleHelper(0, s1.length() - 1, 0, s2.length() - 1);
  }

  private boolean isScrambleHelper(int start1, int end1, int start2, int end2) {
    if (start1 > end1 || start2 > end2) {
      return false;
    }
    String str1 = s1.substring(start1, end1 + 1);
    String str2 = s2.substring(start2, end2 + 1);
    if (!sortString(str1).equals(sortString(str2))) {
      return false;
    }
    if (str1.equals(str2)) {
      return true;
    }
    int length = end1 - start1 + 1;
    for (int split = 1; split < length; split++) {
      boolean success =
          isScrambleHelper(start1, start1 + split - 1, start2, start2 + split - 1) &&
              isScrambleHelper(start1 + split, end1, start2 + split, end2) ||
              (isScrambleHelper(start1, start1 + split - 1, end2 - split + 1, end2) &&
              isScrambleHelper(start1 + split, end1, start2, end2 - split));
      if (success) {
        return true;
      }
    }
    return false;
  }

  private String sortString(String s) {
    char[] charArray = s.toCharArray();
    Arrays.sort(charArray);
    return new String(charArray);
  }
}
