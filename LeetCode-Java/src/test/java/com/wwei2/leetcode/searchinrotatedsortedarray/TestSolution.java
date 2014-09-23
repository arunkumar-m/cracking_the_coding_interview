package com.wwei2.leetcode.searchinrotatedsortedarray;

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
      Assert.assertEquals(i - 1, sol.search(A, i));
    }
  }

  @Test
  public void testRotated() {
    int[] A = new int[]{16, 18, 20, 2, 4, 6, 8, 10, 12, 14};
    for (int i = 1; i <= 20; i++) {
      int expected = -1;
      if (i % 2 == 0) {
        expected = ((i - 2) / 2 + 3) % A.length;
      }
      Assert.assertEquals(expected, sol.search(A, i));
    }
  }
}
