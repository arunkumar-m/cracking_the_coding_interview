package com.wwei2.leetcode.rotatelist;

import com.wwei2.leetcode.util.ListNode;
import com.wwei2.leetcode.util.ListUtil;
import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;

/**
 * Created by weiwei on 8/17/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testFiveElements() {
    ListNode head = ListUtil.fromList(Arrays.asList(1, 2, 3, 4, 5));
    head = sol.rotateRight(head, 2);
    int[] ret = ListUtil.toArray(head);
    int[] expected = {4, 5, 1, 2, 3};
    Assert.assertArrayEquals(expected, ret);
  }
  @Test
  public void testRotateZero() {
    ListNode head = ListUtil.fromList(Arrays.asList(1, 2, 3, 4, 5));
    head = sol.rotateRight(head, 0);
    int[] ret = ListUtil.toArray(head);
    int[] expected = {1, 2, 3, 4, 5};
    Assert.assertArrayEquals(expected, ret);
  }
}
