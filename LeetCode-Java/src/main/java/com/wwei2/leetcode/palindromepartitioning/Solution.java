package com.wwei2.leetcode.palindromepartitioning;

import java.util.ArrayList;
import java.util.List;

/**
 * Palindrome Partitioning.
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 */
public class Solution {
  public List<List<String>> partition(String s) {
    int length = s.length();
    List<List<String>> ret = new ArrayList<>();
    if (length == 0) {
      ret.add(new ArrayList<String>());
    }
    for (int i = 1; i <= length; i++) {
      String str = s.substring(0, i);
      if (isPal(str)) {
        String rest = s.substring(i);
        List<List<String>> results = partition(rest);
        for (List<String> list : results) {
          list.add(0, str);
          ret.add(list);
        }
      }
    }
    return ret;
  }
  private boolean isPal(String s) {
    int length = s.length();
    for (int i = 0; i < length; i++) {
      if (s.charAt(i) != s.charAt(length - 1 - i)) {
        return false;
      }
    }
    return true;
  }
}
