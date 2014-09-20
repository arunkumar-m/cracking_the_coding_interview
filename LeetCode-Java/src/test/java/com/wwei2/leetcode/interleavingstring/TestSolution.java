package com.wwei2.leetcode.interleavingstring;

import org.junit.Test;

/**
 * Created by weiwei on 9/20/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test1() {
    System.out.println(sol.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    System.out.println(sol.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    System.out.println(sol.isInterleave("aaaaaaaaaa", "aaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa"));
  }
}
