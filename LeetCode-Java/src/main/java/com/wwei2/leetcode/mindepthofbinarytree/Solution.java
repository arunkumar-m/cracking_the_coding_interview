package com.wwei2.leetcode.mindepthofbinarytree;

import com.wwei2.leetcode.util.TreeNode;

/**
 * Created by weiwei on 6/26/14.
 */
public class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            return 1;
        } else {
            int leftMin = Integer.MAX_VALUE, rightMin = Integer.MAX_VALUE;
            if (root.left != null)
                leftMin = minDepth(root.left);
            if (root.right != null)
                rightMin = minDepth(root.right);
            return 1 + Math.min(leftMin, rightMin);
        }
    }
}
