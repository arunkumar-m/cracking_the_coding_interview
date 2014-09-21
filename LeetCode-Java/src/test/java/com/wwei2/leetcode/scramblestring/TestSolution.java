package com.wwei2.leetcode.scramblestring;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/21/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSimple() {
    Assert.assertTrue(sol.isScramble("great", "rgeat"));
    Assert.assertTrue(sol.isScramble("great", "rgtae"));
  }
  @Test
  public void test1() {
    Assert.assertTrue(sol.isScramble("abb", "bab"));
  }
  @Test
  public void test2() {
    Assert.assertFalse(sol.isScramble("abcdd", "dbdac"));
  }
}
