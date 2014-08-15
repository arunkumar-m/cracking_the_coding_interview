package com.wwei2.leetcode.removenthnodefromendoflist;

import com.wwei2.leetcode.util.ListNode;
import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 8/14/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSingle() {
    ListNode actual = sol.removeNthFromEnd(new ListNode(1), 1);
    Assert.assertEquals(null, actual);
  }
}
