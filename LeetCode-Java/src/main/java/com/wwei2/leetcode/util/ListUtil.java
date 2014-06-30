package com.wwei2.leetcode.util;

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
}
