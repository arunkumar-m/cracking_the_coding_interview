package com.wwei2.leetcode.combinations;

import org.junit.Test;

/**
 * Created by weiwei on 9/24/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSimple() {
    System.out.println(sol.combine(1, 1));
    System.out.println(sol.combine(4, 2));
    System.out.println(sol.combine(5, 2));
    System.out.println(sol.combine(5, 3));
  }
}
