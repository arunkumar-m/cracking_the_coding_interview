package com.wwei2.leetcode.pascalstriangle2;

import org.junit.Test;

/**
 * Created by weiwei on 9/16/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test1Row() {
    System.out.println(sol.getRow(1));
  }
  @Test
  public void test2Row() {
    System.out.println(sol.getRow(2));
  }
  @Test
  public void test3Row() {
    System.out.println(sol.getRow(3));
  }
  @Test
  public void test4Row() {
    System.out.println(sol.getRow(4));
  }
}
