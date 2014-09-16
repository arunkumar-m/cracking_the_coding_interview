package com.wwei2.leetcode.wordladder;

import org.junit.Assert;
import org.junit.Test;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by weiwei on 9/16/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall() {
    Set<String> dict = new HashSet<String>(){{
      add("hot");
      add("dot");
      add("dog");
      add("lot");
      add("log");
    }};
    Assert.assertEquals(5, sol.ladderLength("hit", "cog", dict));
  }
}
