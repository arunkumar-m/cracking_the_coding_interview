package com.wwei2.leetcode.sortlist;

import com.wwei2.leetcode.util.ListNode;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Sort list.
 */
public class Solution {
  public ListNode sortList(ListNode head) {
    Queue<ListNode> queue = new LinkedList<>();
    ListNode curr = head;
    while (curr != null) {
      ListNode next = curr.next;
      curr.next = null;
      queue.add(curr);
      curr = next;
    }
    while (queue.size() > 1) {
      ListNode first = queue.remove();
      ListNode second = queue.remove();
      queue.add(merge(first, second));
    }
    return queue.poll();
  }
  private ListNode merge(ListNode x, ListNode y) {
    ListNode dummy = new ListNode(0);
    ListNode curr = dummy, next;
    while (x != null && y != null) {
      if (x.val < y.val) {
        next = x;
        x = x.next;
      } else {
        next = y;
        y = y.next;
      }
      curr.next = next;
      curr = curr.next;
    }
    while (x != null) {
      curr.next = x;
      curr = curr.next;
      x = x.next;
    }
    while (y != null) {
      curr.next = y;
      curr = curr.next;
      y = y.next;
    }
    curr.next = null;
    return dummy.next;
  }
}
