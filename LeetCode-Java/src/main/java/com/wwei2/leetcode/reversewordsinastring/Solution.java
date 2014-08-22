package com.wwei2.leetcode.reversewordsinastring;

/**
 * Created by weiwei on 8/21/14.
 */
public class Solution {
  public String reverseWords(String s) {
    String[] words = s.trim().split("\\s+");
    StringBuilder sb = new StringBuilder();
    if (words.length > 0) {
      sb.append(words[words.length - 1]);
    }
    for (int i = words.length - 2; i >= 0; i--) {
      sb.append(" " + words[i]);
    }
    return sb.toString();
  }
}
