package com.wwei2.leetcode.pascalstriangle2;

import java.util.ArrayList;
import java.util.List;

/**
 * Pascal's triangle II.
 */
public class Solution {
  public List<Integer> getRow(int rowIndex) {
    List<Integer> prevLevel = new ArrayList<>();
    List<Integer> currLevel = new ArrayList<>();
    prevLevel.add(1);
    for (int i = 1; i <= rowIndex; i++) {
      for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i) {
          currLevel.add(1);
        } else {
          currLevel.add(prevLevel.get(j - 1) + prevLevel.get(j));
        }
      }
      prevLevel = new ArrayList<>(currLevel);
      currLevel.clear();
    }
    return prevLevel;
  }
}
