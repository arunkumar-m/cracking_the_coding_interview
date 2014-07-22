package com.wwei2.leetcode.flattenbinarytreetolinkedlist;

import com.wwei2.leetcode.util.TreeNode;

/**
 * Created by weiwei on 6/25/14.
 */
public class Solution {
    public void flatten(TreeNode root) {
        if (root == null) return;
        TreeNode left = root.left;
        TreeNode right = root.right;
        flatten(left);
        flatten(right);
        root.left = null;
        root.right = left;
        TreeNode curr = root;
        while (curr.right != null) {
            curr = curr.right;
        }
        curr.right = right;
    }
}
