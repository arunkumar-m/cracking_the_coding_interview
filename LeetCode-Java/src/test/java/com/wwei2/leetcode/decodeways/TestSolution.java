package com.wwei2.leetcode.decodeways;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/21/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test1() {
    Assert.assertEquals(2, sol.numDecodings("12"));
  }
  @Test
  public void test2() {
    Assert.assertEquals(2, sol.numDecodings("1016"));
  }
  @Test
  public void test3() {
    Assert.assertEquals(3, sol.numDecodings("1129"));
  }
  @Test
  public void test4() {
    Assert.assertEquals(0, sol.numDecodings("010"));
  }
}
