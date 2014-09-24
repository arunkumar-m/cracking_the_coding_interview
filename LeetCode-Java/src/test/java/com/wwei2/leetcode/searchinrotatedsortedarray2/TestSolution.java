package com.wwei2.leetcode.searchinrotatedsortedarray2;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/23/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testNotRotated() {
    int[] A = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 1; i <= 10; i++) {
      Assert.assertEquals(true, sol.search(A, i));
    }
  }

  @Test
  public void testRotated() {
    int[] A = new int[]{16, 18, 20, 2, 4, 6, 8, 10, 12, 14};
    for (int i = 2; i <= 20; i += 2) {
      Assert.assertEquals(true, sol.search(A, i));
    }
  }

  @Test
  public void testEqual() {
    int[] A = new int[]{1, 1, 1, 3, 1, 1};
    Assert.assertEquals(true, sol.search(A, 1));
    Assert.assertEquals(false, sol.search(A, 2));
    Assert.assertEquals(true, sol.search(A, 3));
  }
}
