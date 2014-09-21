package com.wwei2.leetcode.restoreipaddresses;

import java.util.ArrayList;
import java.util.List;

/**
 * Restore IP addresses.
 */
public class Solution {
  private List<String> results;
  public List<String> restoreIpAddresses(String s) {
    results = new ArrayList<>();
    restoreHelper(s, "", 4);
    return results;
  }
  private void restoreHelper(String s, String curr, int cnt) {
    if (cnt == 1) {
      if (s.length() != 0 && s.length() <= 3) {
        if (s.length() >= 2 && s.charAt(0) == '0') {
          return;
        }
        int tmp = Integer.parseInt(s);
        if (tmp >= 0 && tmp <= 255) {
          results.add(curr + s);
        }
      }
    } else {
      int length = s.length();
      for (int i = 0; i < 3 && i < length; i++) {
        String str = s.substring(0, i + 1);
        int tmp = Integer.parseInt(str);
        if (tmp <= 255) {
          restoreHelper(s.substring(i + 1), curr + str + ".", cnt - 1);
        }
        if (tmp == 0) {
          break;
        }
      }
    }
  }
}
