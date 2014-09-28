package com.wwei2.leetcode.addbinary;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/27/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSimple() {
    testHelper("0", "0", "0");
    testHelper("1", "0", "1");
    testHelper("10", "1", "1");
    testHelper("100", "1", "11");
  }

  private void testHelper(String expected, String a, String b) {
    Assert.assertEquals(expected, sol.addBinary(a, b));
  }
}
