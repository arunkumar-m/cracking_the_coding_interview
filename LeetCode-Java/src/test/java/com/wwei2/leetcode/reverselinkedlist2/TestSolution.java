package com.wwei2.leetcode.reverselinkedlist2;

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
  public void testSingle() {
    ListNode head = new ListNode(1);
    head = sol.reverseBetween(head, 1, 1);
    Assert.assertEquals(1, head.val);
    Assert.assertEquals(null, head.next);
  }

  @Test
  public void testLarge() {
    ListNode head = ListUtil.fromList(Arrays.asList(1, 2, 3, 4, 5));
    head = sol.reverseBetween(head, 2, 4);
    Assert.assertArrayEquals(new int[]{1, 4, 3, 2, 5}, ListUtil.toArray(head));
  }
}
