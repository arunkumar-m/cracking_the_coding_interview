package com.wwei2.leetcode.candy;

import java.util.LinkedList;
import java.util.Stack;

/**
 * What is the minimum candies you must give?
 * Two pass solution.
 */
public class Solution {
  public int candy(int[] ratings) {
    int[] candy = new int[ratings.length];
    candy[0] = 1;
    for (int i = 1; i < ratings.length; i++) {
      if (ratings[i] > ratings[i - 1]) {
        candy[i] = candy[i - 1] + 1;
      } else {
        candy[i] = 1;
      }
    }
    for (int i = ratings.length - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]) {
        candy[i] = candy[i + 1] + 1;
      }
    }
    int sum = 0;
    for (int i = 0; i < ratings.length; i++) {
      sum += candy[i];
    }
    return sum;
  }
}
