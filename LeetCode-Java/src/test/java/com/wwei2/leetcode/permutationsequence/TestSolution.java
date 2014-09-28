package com.wwei2.leetcode.permutationsequence;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/27/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSimple() {
    test("123", 3, 1);
    test("132", 3, 2);
    test("213", 3, 3);
    test("231", 3, 4);
    test("312", 3, 5);
    test("321", 3, 6);
  }

  private void test(String expected, int n, int k) {
    Assert.assertEquals(expected, sol.getPermutation(n, k));
  }
}
