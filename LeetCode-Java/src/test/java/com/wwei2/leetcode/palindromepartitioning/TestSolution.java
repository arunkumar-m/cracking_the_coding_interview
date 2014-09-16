package com.wwei2.leetcode.palindromepartitioning;

import org.junit.Test;

import java.util.List;

/**
 * Created by weiwei on 9/15/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall() {
    List<List<String>> list = sol.partition("aab");
    System.out.println(list);
  }
  @Test
  public void testSimple() {
    List<List<String>> list = sol.partition("bb");
    System.out.println(list);
  }
}
