package com.wwei2.leetcode.reorderlist;

import com.wwei2.leetcode.util.ListNode;
import com.wwei2.leetcode.util.ListUtil;
import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;
import java.util.List;

/**
 * Created by weiwei on 8/20/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testNull() {
    ListNode head = null;
    sol.reorderList(head);
    Assert.assertEquals(null, head);
  }
  @Test
  public void testOne() {
    testHelper(Arrays.asList(1), new int[]{1});
  }
  @Test
  public void testFour() {
    testHelper(Arrays.asList(1, 2, 3, 4), new int[]{1, 4, 2, 3});
  }
  @Test
  public void testFive() {
    testHelper(Arrays.asList(1, 2, 3, 4, 5), new int[]{1, 5, 2, 4, 3});
  }
  private void testHelper(List<Integer> list, int[] expected) {
    ListNode head = ListUtil.fromList(list);
    sol.reorderList(head);
    int[] actual = ListUtil.toArray(head);
    Assert.assertArrayEquals(expected, actual);
  }
}
