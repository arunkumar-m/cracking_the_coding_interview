package com.wwei2.leetcode.removeduplicatesfromsortedlist2;

import com.wwei2.leetcode.util.ListNode;
import com.wwei2.leetcode.util.ListUtil;
import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;

/**
 * Created by weiwei on 8/15/14.
 */
public class TestSolution {

  private Solution sol = new Solution();

  @Test
  public void testTwo() {
    ListNode head = ListUtil.fromList(Arrays.asList(1, 2));
    head = sol.deleteDuplicates(head);
    int[] ret = ListUtil.toArray(head);
    int[] expected = {1, 2};
    Assert.assertArrayEquals(expected, ret);
  }

  @Test
  public void testSeven() {
    ListNode head = ListUtil.fromList(Arrays.asList(1, 2, 3, 3, 4, 4, 5));
    head = sol.deleteDuplicates(head);
    int[] ret = ListUtil.toArray(head);
    int[] expected = {1, 2, 5};
    Assert.assertArrayEquals(expected, ret);
  }

}
