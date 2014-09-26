package com.wwei2.leetcode.simplifypath;

import java.util.Stack;

/**
 * Simplify path.
 */
public class Solution {
  public String simplifyPath(String path) {
    String[] words = path.split("/+");
    Stack<String> stack = new Stack<>();
    for (String word : words) {
      if (word.equals("..")) {
        if (!stack.isEmpty()) {
          stack.pop();
        }
      } else if (!word.equals(".") && !word.equals("")) {
        stack.push(word);
      }
    }
    return join(stack);
  }

  private String join(Stack<String> stack) {
    if (stack.isEmpty()) {
      return "/";
    }
    StringBuilder sb = new StringBuilder();
    while (!stack.isEmpty()) {
      String word = stack.pop();
      sb.insert(0, "/" + word);
    }
    return sb.toString();
  }
}
