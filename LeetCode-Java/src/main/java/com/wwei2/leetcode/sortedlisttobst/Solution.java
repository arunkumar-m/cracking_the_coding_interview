package com.wwei2.leetcode.sortedlisttobst;

import com.wwei2.leetcode.util.ListNode;
import com.wwei2.leetcode.util.ListUtil;
import com.wwei2.leetcode.util.TreeNode;

/**
 * Created by weiwei on 6/29/14.
 */
public class Solution {
    private ListNode curr;
    public TreeNode sortedListToBST(ListNode head) {
        int n = ListUtil.getLength(head);
        curr = head;
        return sortedListToBSTHelper(0, n - 1);
    }
    private TreeNode sortedListToBSTHelper(int start, int end) {
        if (start > end) return null;
        int mid = start + (end - start) / 2;
        TreeNode left = sortedListToBSTHelper(start, mid - 1);
        TreeNode node = new TreeNode(curr.val);
        curr = curr.next;
        TreeNode right = sortedListToBSTHelper(mid + 1, end);
        node.left = left;
        node.right = right;
        return node;
    }
}
