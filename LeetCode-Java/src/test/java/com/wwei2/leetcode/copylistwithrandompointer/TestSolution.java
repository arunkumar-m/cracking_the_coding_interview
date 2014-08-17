package com.wwei2.leetcode.copylistwithrandompointer;

import com.wwei2.leetcode.util.RandomListNode;
import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 8/16/14.
 */
public class TestSolution {

  private Solution sol = new Solution();

  @Test
  public void testNull() {
    RandomListNode ret = sol.copyRandomList(null);
    Assert.assertEquals(null, ret);
  }

  @Test
  public void testSingle() {
    RandomListNode head = new RandomListNode(1);
    head.next = null;
    head.random = null;
    head = sol.copyRandomList(head);
    Assert.assertEquals(1, head.label);
    Assert.assertEquals(null, head.next);
    Assert.assertEquals(null, head.random);
  }

  @Test
  public void testThree() {
    RandomListNode one = new RandomListNode(1);
    RandomListNode two = new RandomListNode(2);
    RandomListNode three = new RandomListNode(3);
    one.next = two;
    two.next = three;
    one.random = three;
    two.random = one;
    three.random = two;
    RandomListNode copy = sol.copyRandomList(one);
    Assert.assertEquals(1, copy.label);
    Assert.assertEquals(2, copy.next.label);
    Assert.assertEquals(3, copy.next.next.label);
    Assert.assertEquals(3, copy.random.label);
    Assert.assertEquals(1, copy.next.random.label);
    Assert.assertEquals(2, copy.next.next.random.label);
    Assert.assertEquals(null, copy.next.next.next);
  }
}
