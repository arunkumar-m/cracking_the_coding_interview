package com.wwei2.leetcode.mergesortedarray;

import com.wwei2.leetcode.util.IO;
import org.junit.Test;

/**
 * Created by weiwei on 9/21/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void test1() {
    int[] A = new int[]{1, 3, 5, 0, 0, 0};
    sol.merge(A, 3, new int[]{2, 4, 6}, 3);
    for (int i = 0; i < A.length; i++) {
      System.out.print(A[i] + ", ");
    }
    System.out.println("");
  }
}
