package com.wwei2.leetcode.mergeksortedlists;

import com.wwei2.leetcode.util.ListNode;
import com.wwei2.leetcode.util.ListUtil;
import org.junit.Assert;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by weiwei on 8/19/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testTwoLists() {
    ListNode node1 = ListUtil.fromList(Arrays.asList(1, 3, 5, 7, 9));
    ListNode node2 = ListUtil.fromList(Arrays.asList(0, 2, 4, 6, 8));
    List<ListNode> list = new ArrayList<>();
    list.add(node1);
    list.add(node2);
    ListNode ret = sol.mergeKLists(list);
    int[] actual = ListUtil.toArray(ret);
    int[] expected = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Assert.assertArrayEquals(expected, actual);
  }

  @Test
  public void testTwoListsWithDuplicates() {
    ListNode node1 = ListUtil.fromList(Arrays.asList(1, 2, 2));
    ListNode node2 = ListUtil.fromList(Arrays.asList(1, 1, 2));
    List<ListNode> list = new ArrayList<>();
    list.add(node1);
    list.add(node2);
    ListNode ret = sol.mergeKLists(list);
    int[] actual = ListUtil.toArray(ret);
    int[] expected = {1, 1, 1, 2, 2, 2};
    Assert.assertArrayEquals(expected, actual);
  }
}
