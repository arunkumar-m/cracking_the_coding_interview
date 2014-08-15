package com.wwei2.leetcode.partitionlist;

import com.wwei2.leetcode.util.ListNode;
import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 8/14/14.
 */
public class TestSolution {
  private Solution sol = new Solution();

  @Test
  public void testNull() {
    ListNode ret = sol.partition(null, 0);
    Assert.assertEquals(null, ret);
  }

  @Test
  public void testSingle() {
    ListNode ret = sol.partition(new ListNode(1), 2);
    Assert.assertEquals(1, ret.val);
    Assert.assertEquals(null, ret.next);
  }

  @Test
  public void testSingle2() {
    ListNode ret = sol.partition(new ListNode(1), 0);
    Assert.assertEquals(1, ret.val);
    Assert.assertEquals(null, ret.next);
  }

  @Test
  public void testLarge() {
    ListNode head = new ListNode(1);
    head.next = new ListNode(4);
    head.next.next = new ListNode(3);
    head.next.next.next = new ListNode(2);
    head.next.next.next.next = new ListNode(5);
    head.next.next.next.next.next = new ListNode(2);
    head = sol.partition(head, 3);
    Assert.assertEquals(1, head.val);
    Assert.assertEquals(2, head.next.val);
    Assert.assertEquals(2, head.next.next.val);
    Assert.assertEquals(4, head.next.next.next.val);
    Assert.assertEquals(3, head.next.next.next.next.val);
    Assert.assertEquals(5, head.next.next.next.next.next.val);
    Assert.assertEquals(null, head.next.next.next.next.next.next);

  }
}
