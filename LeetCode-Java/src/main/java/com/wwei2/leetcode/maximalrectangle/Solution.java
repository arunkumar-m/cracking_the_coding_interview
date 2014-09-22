package com.wwei2.leetcode.maximalrectangle;

import java.util.Stack;

/**
 * Maximal rectangle.
 */
public class Solution {
  public int maximalRectangle(char[][] matrix) {
    int numCol = matrix.length;
    int numRow = numCol == 0 ? 0 : matrix[0].length;
    int[][] hist = new int[numCol][numRow + 1];
    for (int i = 0; i < numRow; i++) {
      if (matrix[0][i] == '1') {
        hist[0][i] = 1;
      }
    }
    for (int i = 1; i < numCol; i++) {
      for (int j = 0; j < numRow; j++) {
        if (matrix[i][j] == '1') {
          hist[i][j] = hist[i - 1][j] + 1;
        } else {
          hist[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < numCol; i++) {
      hist[i][numRow] = Integer.MIN_VALUE;
    }
    int maxSoFar = 0;
    for (int i = 0; i < numCol; i++) {
      for (int j = 0; j < numRow; j++) {
      }
      maxSoFar = Math.max(maxSoFar, largestRectangleArea(hist[i]));
    }
    return maxSoFar;
  }

  private int largestRectangleArea(int[] height) {
    Stack<Integer> stack = new Stack<>();
    int length = height.length;
    int maxSoFar = 0;
    for (int i = 0; i < length; i++) {
      if (stack.isEmpty() || height[stack.peek()] <= height[i]) {
        stack.push(i);
      } else {
        while (true) {
          int top = stack.peek();
          if (height[top] <= height[i]) {
            break;
          }
          stack.pop();
          if (stack.isEmpty()) {
            maxSoFar = Math.max(maxSoFar, height[top] * i);
            break;
          } else {
            maxSoFar = Math.max(maxSoFar, height[top] * (i - stack.peek() - 1));
          }
        }
        stack.push(i);
      }
    }
    return maxSoFar;
  }
}