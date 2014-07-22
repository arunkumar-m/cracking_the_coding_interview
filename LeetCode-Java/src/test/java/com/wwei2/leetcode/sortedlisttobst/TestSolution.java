package com.wwei2.leetcode.sortedlisttobst;

import com.wwei2.leetcode.util.ListNode;
import com.wwei2.leetcode.util.TreeNode;
import org.junit.Test;

/**
 * Created by weiwei on 6/29/14.
 */
public class TestSolution {
    private Solution sol = new Solution();
    @Test
    public void testSmallList() {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        TreeNode root = sol.sortedListToBST(head);
        System.out.println(root);
    }

    @Test
    public void testMidList() {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        head.next.next.next.next.next = new ListNode(6);
        head.next.next.next.next.next.next = new ListNode(7);
        TreeNode root = sol.sortedListToBST(head);
        System.out.println(root);
    }
}
