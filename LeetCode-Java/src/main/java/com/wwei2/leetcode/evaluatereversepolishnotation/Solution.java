package com.wwei2.leetcode.evaluatereversepolishnotation;

import java.util.Stack;

/**
 * Evaluate reverse polish notation.
 */
public class Solution {
  public int evalRPN(String[] tokens) {
    Stack<Integer> stack = new Stack<>();
    int x, y;
    for (int i = 0; i < tokens.length; i++) {
      switch (tokens[i]) {
        case "+":
          x = stack.pop();
          y = stack.pop();
          stack.push(x + y);
          break;
        case "-":
          x = stack.pop();
          y = stack.pop();
          stack.push(y - x);
          break;
        case "*":
          x = stack.pop();
          y = stack.pop();
          stack.push(x * y);
          break;
        case "/":
          x = stack.pop();
          y = stack.pop();
          stack.push(y / x);
          break;
        default:
          stack.push(Integer.parseInt(tokens[i]));
      }
    }
    return stack.pop();
  }
}
