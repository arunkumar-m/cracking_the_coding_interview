package com.wwei2.leetcode.sortlist;

import com.wwei2.leetcode.util.ListNode;
import com.wwei2.leetcode.util.ListUtil;
import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;

/**
 * Created by weiwei on 8/19/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testNull() {
    ListNode result = sol.sortList(null);
    Assert.assertEquals(null, result);
  }
  @Test
  public void testFive() {
    ListNode head = ListUtil.fromList(Arrays.asList(5, 4, 2, 1, 3));
    ListNode result = sol.sortList(head);
    int[] actual = ListUtil.toArray(result);
    int[] expected = {1, 2, 3, 4, 5};
    Assert.assertArrayEquals(expected, actual);
  }
  @Test
  public void testTen() {
    ListNode head = ListUtil.fromList(Arrays.asList(7, 10, 8, 6, 5, 1, 3, 2, 9, 4));
    ListNode result = sol.sortList(head);
    int[] actual = ListUtil.toArray(result);
    int[] expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Assert.assertArrayEquals(expected, actual);
  }
}
