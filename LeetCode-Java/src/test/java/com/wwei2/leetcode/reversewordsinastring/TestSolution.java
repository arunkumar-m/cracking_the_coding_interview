package com.wwei2.leetcode.reversewordsinastring;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 8/21/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testWithAllSpaces() {
    testHelper("        ", "");
  }
  @Test
  public void testWithLeadingAndTrailingSpaces() {
    testHelper("   hello world     ", "world hello");
    testHelper("  a b c d  e   f    ", "f e d c b a");
  }
  private void testHelper(String s, String expected) {
    String actual = sol.reverseWords(s);
    Assert.assertEquals(expected, actual);
  }
}
