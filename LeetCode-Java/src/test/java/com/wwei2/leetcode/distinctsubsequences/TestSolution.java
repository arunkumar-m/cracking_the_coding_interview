package com.wwei2.leetcode.distinctsubsequences;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/20/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test1() {
    Assert.assertEquals(3, sol.numDistinct("rabbbit", "rabbit"));
  }
  @Test
  public void test2() {
    Assert.assertEquals(6, sol.numDistinct("rabbbbit", "rabbit"));
  }
}
