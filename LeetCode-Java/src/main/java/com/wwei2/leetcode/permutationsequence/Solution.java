package com.wwei2.leetcode.permutationsequence;

import java.util.ArrayList;
import java.util.List;

/**
 * Permutation sequence.
 */
public class Solution {
  public String getPermutation(int n, int k) {
    List<String> list = new ArrayList<>();
    for (int i = 1; i <= n; i++) {
      list.add(Integer.toString(i));
    }
    return getPermutationHelper(list, k);
  }

  private String getPermutationHelper(List<String> list, int k) {
    int n = list.size();
    if (n == 1) {
      return list.get(0);
    }
    int index = (k - 1) / factorial(n - 1);
    String digit = list.get(index);
    list.remove(index);
    int kprime = k % factorial(n - 1);
    kprime = kprime == 0 ? factorial(n - 1) : kprime;
    String str = getPermutationHelper(list, kprime);
    return digit + str;
  }

  private int factorial(int n) {
    int ret = 1;
    for (int i = 2; i <= n; i++) {
      ret *= i;
    }
    return ret;
  }
}
