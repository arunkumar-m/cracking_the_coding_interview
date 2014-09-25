package com.wwei2.leetcode.minimumwindowsubstring;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/24/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSimple() {
    Assert.assertEquals("BANC", sol.minWindow("ADOBECODEBANC", "ABC"));
    Assert.assertEquals("ABCD", sol.minWindow("ABCDEFG", "BAD"));
  }
  @Test
  public void testNotExist() {
    Assert.assertEquals("", sol.minWindow("ABCDEFG", "ABCH"));
  }
  @Test
  public void testComplex() {
    Assert.assertEquals("cwae", sol.minWindow("cabwefgewcwaefgcf", "cae"));
  }
}
