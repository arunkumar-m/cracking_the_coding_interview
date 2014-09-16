package com.wwei2.leetcode.longestconsecutivesequence;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/16/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall() {
    Assert.assertEquals(4, sol.longestConsecutive(new int[]{100, 4, 200, 1, 3, 2}));
  }
}
