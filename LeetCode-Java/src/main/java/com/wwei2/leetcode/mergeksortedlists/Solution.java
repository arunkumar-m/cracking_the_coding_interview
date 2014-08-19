package com.wwei2.leetcode.mergeksortedlists;

import com.wwei2.leetcode.util.ListNode;

import java.util.Comparator;
import java.util.List;
import java.util.TreeSet;

/**
 * Merge k sorted lists and return it as one sorted list.
 */
public class Solution {
  public ListNode mergeKLists(List<ListNode> lists) {
    Comparator<ListNode> comparator = new Comparator<ListNode>() {
      @Override
      public int compare(ListNode x, ListNode y) {
        if (x.val < y.val) {
          return -1;
        } else if (x.val > y.val) {
          return 1;
        } else {
          return -1;
        }
      }
    };
    // Use custom comparator to avoid removing duplicates.
    TreeSet<ListNode> treeSet = new TreeSet<>(comparator);
    for (ListNode list : lists) {
      if (list != null) {
        treeSet.add(list);
      }
    }
    ListNode dummy = new ListNode(0);
    ListNode curr = dummy;
    while (!treeSet.isEmpty()) {
      ListNode node = treeSet.pollFirst();
      if (node.next != null) {
        treeSet.add(node.next);
      }
      curr.next = node;
      curr = curr.next;
    }
    return dummy.next;
  }
}
