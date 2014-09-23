package com.wwei2.leetcode.largestrectangleinhistogram;

import java.util.Stack;

/**
 * Largest rectangle in histogram.
 */
public class Solution {
  public int largestRectangleArea(int[] height) {
    int[] arr = new int[height.length + 1];
    for (int i = 0; i < height.length; i++) {
      arr[i] = height[i];
    }
    arr[height.length] = Integer.MIN_VALUE;
    return largestRectangleAreaStack(arr);
  }

  // Use stack to solve the problem.
  private int largestRectangleAreaStack(int[] arr) {
    Stack<Integer> stack = new Stack<>();
    stack.push(0);
    int maxSoFar = 0;
    for (int i = 1; i < arr.length; i++) {
      int index = stack.peek();
      if (arr[index] <= arr[i]) {
        stack.push(i);
      } else {
        while (true) {
          int top = stack.peek();
          if (arr[top] > arr[i]) {
            stack.pop();
            if (stack.isEmpty()) {
              maxSoFar = Math.max(maxSoFar, arr[top] * i);
              break;
            } else {
              maxSoFar = Math.max(maxSoFar, arr[top] * (i - stack.peek() - 1));
            }
          } else {
            break;
          }
        }
        stack.push(i);
      }
    }
    return maxSoFar;
  }

  // Divide and Conquer solution utilizing segment tree.
  private int largestRectangleAreaDivideAndConquer(int[] height) {
    if (height.length == 0) {
      return 0;
    }
    int[] st = constructST(height);
    return largestRectangleAreaHelper(height, 0, height.length - 1, st);
  }

  private int largestRectangleAreaHelper(int[] height, int start, int end, int[] st) {
    if (start > end) {
      return 0;
    }
    int minIndex = rmq(height, 0, height.length - 1, start, end, st, 1);
    int x = largestRectangleAreaHelper(height, start, minIndex - 1, st);
    int y = largestRectangleAreaHelper(height, minIndex + 1, end, st);
    return max3(x, y, height[minIndex] * (end - start + 1));
  }

  private int[] constructST(int[] arr) {
    int height = (int)(Math.ceil(Math.log(arr.length + 1) / Math.log(2)));
    int length = (int)(2 * Math.pow(2, height) - 1);
    int[] st = new int[length];
    constructSTHelper(arr, 0, arr.length - 1, st, 1);
    return st;
  }

  private int constructSTHelper(int[] arr, int start, int end, int[] st, int index) {
    if (start == end) {
      st[index] = start;
      return start;
    }
    int mid = start + (end - start) / 2;
    int left = constructSTHelper(arr, start, mid, st, index * 2);
    int right = constructSTHelper(arr, mid + 1, end, st, index * 2 + 1);
    st[index] = minValue(arr, left, right);
    return st[index];
  }

  private int rmq(int[] arr, int ss, int se, int qs, int qe, int[] st, int index) {
    if (qs <= ss && qe >= se) {
      return st[index];
    }
    if (se < qs || ss > qe) {
      return -1;
    }
    int mid = ss + (se - ss) / 2;
    return minValue(arr, rmq(arr, ss, mid, qs, qe, st, index * 2),
        rmq(arr, mid + 1, se, qs, qe, st, index * 2 + 1));
  }

  private int max3(int a, int b, int c) {
    return Math.max(a, Math.max(b, c));
  }

  private int minValue(int arr[], int left, int right) {
    if (left == -1) {
      return right;
    }
    if (right == -1) {
      return left;
    }
    if (arr[left] < arr[right]) {
      return left;
    } else {
      return right;
    }
  }
}