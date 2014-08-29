package com.wwei2.leetcode.gasstation;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/5/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall() {
    int[] gas = {1, 2, -3, -1, 1};
    int[] cost = {0, 0, 0, 0, 0};
    Assert.assertEquals(4, sol.canCompleteCircuit(gas, cost));
  }
  @Test
  public void testCannotComplete() {
    int[] gas = {1, 2, -3, -1, -1};
    int[] cost = {0, 0, 0, 0, 0};
    Assert.assertEquals(-1, sol.canCompleteCircuit(gas, cost));
  }
  @Test
  public void testTwoStation() {
    int[] gas = {1, 2};
    int[] cost = {2, 1};
    Assert.assertEquals(1, sol.canCompleteCircuit(gas, cost));
  }
}
