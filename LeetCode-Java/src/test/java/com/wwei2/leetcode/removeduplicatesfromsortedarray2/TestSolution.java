package com.wwei2.leetcode.removeduplicatesfromsortedarray2;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/23/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSimple() {
    int[] A = new int[]{1, 1, 1, 2, 2, 3};
    Assert.assertEquals(5, sol.removeDuplicates(A));
    Assert.assertEquals(1, A[0]);
    Assert.assertEquals(1, A[1]);
    Assert.assertEquals(2, A[2]);
    Assert.assertEquals(2, A[3]);
    Assert.assertEquals(3, A[4]);
  }
}
