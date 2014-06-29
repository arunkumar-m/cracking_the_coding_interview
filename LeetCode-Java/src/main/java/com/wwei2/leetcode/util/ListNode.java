package com.wwei2.leetcode.util;

/**
 * Created by weiwei on 6/29/14.
 */
public class ListNode {

    public int val;

    public ListNode next;

    public ListNode(int x) { val = x; next = null; }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("List: <");
        ListNode curr = this;
        while (curr != null) {
            sb.append(curr.val).append(", ");
            curr = curr.next;
        }
        sb.append(">\n");
        return sb.toString();
    }
}
