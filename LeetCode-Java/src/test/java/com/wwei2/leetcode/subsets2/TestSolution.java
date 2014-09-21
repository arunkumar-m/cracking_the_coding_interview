package com.wwei2.leetcode.subsets2;

import org.junit.Test;

/**
 * Created by weiwei on 9/21/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test1() {
    System.out.println(sol.subsetsWithDup(new int[]{1, 2}));
    System.out.println(sol.subsetsWithDup(new int[]{1, 2, 2}));
    System.out.println(sol.subsetsWithDup(new int[]{4, 4, 4, 1, 4}));
  }
}
