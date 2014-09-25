package com.wwei2.leetcode.minimumwindowsubstring;

/**
 * Minimum window substring.
 */
public class Solution {
  public String minWindow(String S, String T) {
    int left = 0;
    int right = 0;
    int[] charsToMatch = new int[256];
    int[] charsHaveMatched = new int[256];
    for (int i = 0; i < T.length(); i++) {
      charsToMatch[T.charAt(i)]++;
    }
    int minSoFar = Integer.MAX_VALUE;
    int bestLeft = 0, bestRight = 0;
    while (left < S.length() && right < S.length()) {
      while (right < S.length() && !canMatch(charsToMatch, charsHaveMatched)) {
        charsHaveMatched[S.charAt(right)]++;
        right++;
      }
      while (left < right && canMatch(charsToMatch, charsHaveMatched)) {
        if (right - left < minSoFar) {
          minSoFar = right - left;
          bestLeft = left;
          bestRight = right;
        }
        charsHaveMatched[S.charAt(left)]--;
        left++;
      }
    }
    return S.substring(bestLeft, bestRight);
  }

  private boolean canMatch(int[] charsToMatch, int[] charsHaveMatched) {
    for (int i = 0; i < 256; i++) {
      if (charsHaveMatched[i] < charsToMatch[i]) {
        return false;
      }
    }
    return true;
  }
}
