package com.wwei2.leetcode.subsets;

import org.junit.Test;

/**
 * Created by weiwei on 9/20/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall() {
    System.out.println(sol.subsets(new int[]{1, 2, 3}));
    System.out.println(sol.subsets(new int[]{3, 2, 1}));
  }
}
