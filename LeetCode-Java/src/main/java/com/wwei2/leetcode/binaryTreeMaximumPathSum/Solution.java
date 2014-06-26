package com.wwei2.leetcode.binaryTreeMaximumPathSum;

import com.wwei2.leetcode.util.TreeNode;

/**
 * Created by weiwei on 6/25/14.
 */
public class Solution {
    private int maxSoFar;
    public int maxPathSum(TreeNode root) {
        maxSoFar = root == null ? 0 : root.val;
        int val = maxPathSumHelper(root);
        return Math.max(maxSoFar, val);
    }

    public int maxPathSumHelper(TreeNode root) {
        if (root == null) {
            return 0;
        } else {
            int leftMax = Math.max(0, maxPathSumHelper(root.left));
            int rightMax = Math.max(0, maxPathSumHelper(root.right));

            // Update maxSoFar
            maxSoFar = Math.max(maxSoFar, root.val + leftMax + rightMax);
            return root.val + Math.max(leftMax, rightMax);
        }
    }
}
