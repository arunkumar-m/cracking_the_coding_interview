package com.wwei2.leetcode.insertionsortlist;

import com.wwei2.leetcode.util.ListNode;
import com.wwei2.leetcode.util.ListUtil;
import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 8/15/14.
 */
public class TestSolution {

  private Solution sol = new Solution();

  @Test
  public void testSingle() {
    ListNode head = new ListNode(1);
    head = sol.insertionSortList(head);
    int[] ret = ListUtil.toArray(head);
    int[] expected = new int[]{1};
    Assert.assertArrayEquals(expected, ret);
  }

  @Test
  public void testTwo() {
    ListNode head = new ListNode(1);
    head.next = new ListNode(0);
    head = sol.insertionSortList(head);
    int[] ret = ListUtil.toArray(head);
    int[] expected = new int[]{0, 1};
    Assert.assertArrayEquals(expected, ret);
  }

  @Test
  public void testThree() {
    ListNode head = new ListNode(2);
    head.next = new ListNode(1);
    head.next.next = new ListNode(3);
    head = sol.insertionSortList(head);
    int[] ret = ListUtil.toArray(head);
    int[] expected = new int[]{1, 2, 3};
    Assert.assertArrayEquals(expected, ret);
  }
}
