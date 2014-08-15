package com.wwei2.leetcode.removenthnodefromendoflist;

import com.wwei2.leetcode.util.ListNode;

/**
 * Created by weiwei on 8/14/14.
 */
public class Solution {
  public ListNode removeNthFromEnd(ListNode head, int n) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode prev = dummy;
    ListNode winStart = head;
    ListNode winEnd = head;
    for (int i = 0; i < n; i++) {
      winEnd = winEnd.next;
    }
    while (winEnd != null) {
      prev = winStart;
      winStart = winStart.next;
      winEnd = winEnd.next;
    }
    prev.next = prev.next.next;
    return dummy.next;
  }
}
