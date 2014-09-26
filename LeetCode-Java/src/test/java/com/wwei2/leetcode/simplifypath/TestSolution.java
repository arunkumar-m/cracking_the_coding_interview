package com.wwei2.leetcode.simplifypath;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/26/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSimple() {
    testHelper("/home/", "/home");
    testHelper("a/./b/../../c/", "/c");
    testHelper("/../", "/");
    testHelper("/home//foo/", "/home/foo");
  }

  private void testHelper(String path, String expected) {
    Assert.assertEquals(expected, sol.simplifyPath(path));
  }
}
