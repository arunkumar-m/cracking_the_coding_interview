package com.wwei2.leetcode.balancedbinarytree;

/**
 * Created by weiwei on 6/19/14.
 */

import java.lang.Math;
import com.wwei2.leetcode.util.TreeNode;

public class Solution {
    public boolean isBalanced(TreeNode root) {
        return isBalancedHelper(root, 0) < Integer.MAX_VALUE;
    }

    public int isBalancedHelper(TreeNode root, int level) {
        if (root == null) return level;
        else {
            int l = isBalancedHelper(root.left, level + 1);
            int r = isBalancedHelper(root.right, level + 1);
            if (Math.abs(l - r) > 1) {
                return Integer.MAX_VALUE;
            } else {
                return Math.max(l, r);
            }
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        TreeNode t5 = new TreeNode(5);
        TreeNode t6 = new TreeNode(6);
        TreeNode t4 = new TreeNode(4, t5, t6);
        TreeNode t3 = new TreeNode(3);
        TreeNode t2 = new TreeNode(2, t3, t4);
        TreeNode t1 = new TreeNode(1, t2, null);
        System.out.println(t4);
        System.out.println("isBalanced: " + sol.isBalanced(t4));
        System.out.println(t1);
        System.out.println("isBalanced: " + sol.isBalanced(t1));
        System.out.println(t2);
        System.out.println("isBalanced: " + sol.isBalanced(t2));
    }
}
