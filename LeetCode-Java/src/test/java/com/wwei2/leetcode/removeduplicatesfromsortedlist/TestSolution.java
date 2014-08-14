package com.wwei2.leetcode.removeduplicatesfromsortedlist;

import com.wwei2.leetcode.util.ListNode;
import com.wwei2.leetcode.util.ListUtil;
import org.junit.Assert;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by weiwei on 8/13/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testNull() {
    ListNode result = sol.deleteDuplicates(null);
    Assert.assertEquals(null, result);
  }
  @Test
  public void testSingle() {
    ListNode head = ListUtil.fromList(Arrays.asList(1));
    ListNode result = sol.deleteDuplicates(head);
    Assert.assertEquals(1, result.val);
    Assert.assertEquals(null, result.next);
  }
  @Test
  public void testSmall() {
    ListNode head = ListUtil.fromList(Arrays.asList(1, 1, 1, 2, 2));
    ListNode result = sol.deleteDuplicates(head);
    Assert.assertEquals(1, result.val);
    Assert.assertEquals(2, result.next.val);
    Assert.assertEquals(null, result.next.next);
  }
}
