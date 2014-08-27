package com.wwei2.leetcode.wordbreak2;

import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Created by weiwei on 8/26/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall() {
    Set<String> dict = new HashSet<>(Arrays.asList("cat", "cats", "sand", "and", "dog"));
    Set<String> expected = new HashSet<>(Arrays.asList("cats and dog", "cat sand dog"));
    testHelper("catsanddog", dict, expected);
  }
  private void testHelper(String s, Set<String> dict, Set<String> expected) {
    List<String> results = sol.wordBreak(s, dict);
    Set<String> actual = new HashSet<>(results);
    Assert.assertEquals(expected, actual);
  }
}
