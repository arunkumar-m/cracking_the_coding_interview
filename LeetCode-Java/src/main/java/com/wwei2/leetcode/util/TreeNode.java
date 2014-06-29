package com.wwei2.leetcode.util;

/**
 * Created by weiwei on 6/19/14.
 */
public class TreeNode {

    public int val;

    public TreeNode left;

    public TreeNode right;

    public TreeNode(int x) {
        val = x;
        left = null;
        right = null;
    }

    public TreeNode(int x, TreeNode left, TreeNode right) {
        this.val = x;
        this.left = left;
        this.right = right;
    }

    @Override
    public String toString() {
        if (this == null) return "Empty tree.";
        StringBuilder sb = new StringBuilder();
        sb.append(val + ": ");
        sb.append("{ ");
        if (left != null) {
            sb.append(left);
        } else {
            sb.append("#");
        }
        sb.append(", ");
        if (right != null) {
            sb.append(right);
        } else {
            sb.append("#");
        }
        sb.append(" }");
        return sb.toString();
    }
}
