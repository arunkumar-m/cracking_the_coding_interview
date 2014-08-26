package com.wwei2.leetcode.wordbreak;

import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by weiwei on 8/25/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testLeetCode() {
    Set<String> dict = new HashSet<>(Arrays.asList("leet", "code"));
    String s = "leetcode";
    testHelper(s, dict, true);
  }
  @Test
  public void testComplex() {
    Set<String> dict = new HashSet<>(Arrays.asList("i", "love", "you", "him", "her", "destiny"));
    testHelper("iloveyou", dict, true);
    testHelper("iloveyoudestinyhimher", dict, true);
    testHelper("iloveyoudestin", dict, false);
  }
  private void testHelper(String s, Set<String> dict, boolean expected) {
    boolean actual = sol.wordBreak(s, dict);
    Assert.assertEquals(expected, actual);
  }
}
