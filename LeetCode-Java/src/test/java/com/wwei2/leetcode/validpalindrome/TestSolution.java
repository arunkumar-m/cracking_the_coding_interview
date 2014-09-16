package com.wwei2.leetcode.validpalindrome;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/16/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test1() {
    Assert.assertTrue(sol.isPalindrome("abcba"));
  }
  @Test
  public void test2() {
    Assert.assertTrue(sol.isPalindrome("ab cb a"));
  }
  @Test
  public void testEmpty() {
    Assert.assertTrue(sol.isPalindrome(""));
  }
  @Test
  public void testPunc() {
    Assert.assertTrue(sol.isPalindrome("A man, a plan, a canal: Panama"));
  }
}
