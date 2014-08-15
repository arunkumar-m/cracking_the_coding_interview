package com.wwei2.leetcode.reverselinkedlist2;

import com.wwei2.leetcode.util.ListNode;

/**
 * Created by weiwei on 8/14/14.
 */
public class Solution {
  public ListNode reverseBetween(ListNode head, int m, int n) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode prev = dummy;
    // Get the parent node of m.
    for (int i = 1; i < m; i++) {
      prev = prev.next;
    }
    ListNode curr = prev.next;
    ListNode next = curr.next;
    ListNode tail = curr; // m to n elements' tail.
    ListNode dummyHead = new ListNode(0); // dummy head of m to n.
    for (int i = 0; i <= n - m; i++) {
      next = curr.next;
      // Insert.
      ListNode tmp = dummyHead.next;
      dummyHead.next = curr;
      curr.next = tmp;
      curr = next;
    }
    prev.next = dummyHead.next;
    tail.next = next;
    return dummy.next;
  }
}
