package com.wwei2.leetcode.util;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by weiwei on 6/29/14.
 */
public class ListUtil {

  public static ListNode getMiddleElem(ListNode head) {
    ListNode fast = head, slow = head;
    boolean flip = true;
    while (fast != null) {
      fast = fast.next;
      flip = !flip;
      if (flip && fast != null)
        slow = slow.next;
    }
    return slow;
  }

  public static int getLength(ListNode head) {
    int len = 0;
    while (head != null) {
      head = head.next;
      len++;
    }
    return len;
  }

  public static ListNode fromList(List<Integer> list) {
    ListNode head = new ListNode(0); // Dummy.
    ListNode curr = head;
    for (int i : list) {
      curr.next = new ListNode(i);
      curr = curr.next;
    }
    return head.next;
  }

  public static int[] toArray(ListNode head) {
    List<Integer> integers = new ArrayList<>();
    while (head != null) {
      integers.add(head.val);
      head = head.next;
    }
    int[] ret = new int[integers.size()];
    for (int i = 0; i < ret.length; i++) {
      ret[i] = integers.get(i);
    }
    return ret;
  }
}
