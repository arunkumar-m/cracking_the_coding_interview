package com.wwei2.leetcode.restoreipaddresses;

import org.junit.Test;

/**
 * Created by weiwei on 9/20/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test1() {
    System.out.println(sol.restoreIpAddresses("25525511135"));
    System.out.println(sol.restoreIpAddresses("11111111"));
    System.out.println(sol.restoreIpAddresses("10101010"));
  }
  public void testlong() {
    System.out.println(sol.restoreIpAddresses("0279245587303"));
  }
}
