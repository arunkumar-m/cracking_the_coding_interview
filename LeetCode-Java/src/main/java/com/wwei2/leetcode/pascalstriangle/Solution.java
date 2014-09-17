package com.wwei2.leetcode.pascalstriangle;

import java.util.ArrayList;
import java.util.List;

/**
 * Pascal's Triangle.
 */
public class Solution {
  public List<List<Integer>> generate(int numRows) {
    List<List<Integer>> ret = new ArrayList<>();
    if (numRows == 0) {
      return ret;
    }
    List<Integer> tmp = new ArrayList<>();
    tmp.add(1);
    ret.add(tmp);
    for (int i = 1; i < numRows; i++) {
      tmp = new ArrayList<>();
      for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i) {
          tmp.add(1);
        } else {
          tmp.add(ret.get(i - 1).get(j - 1) + ret.get(i - 1).get(j));
        }
      }
      ret.add(tmp);
    }
    return ret;
  }
}
