package com.wwei2.leetcode.evaluatereversepolishnotation;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 8/21/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test5() {
    testHelper(new String[]{"2", "1", "+", "3", "*"}, 9);
    testHelper(new String[]{"4", "13", "5", "/", "+"}, 6);
  }
  private void testHelper(String[] s, int expected) {
    int actual = sol.evalRPN(s);
    Assert.assertEquals(expected, actual);
  }
}
