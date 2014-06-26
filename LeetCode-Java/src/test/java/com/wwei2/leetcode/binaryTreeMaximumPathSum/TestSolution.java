package com.wwei2.leetcode.binaryTreeMaximumPathSum;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 6/25/14.
 */
public class TestSolution {
    static private Solution sol = new Solution();
    @Test
    public void testSingleNeg() {
        TreeNode root = new TreeNode(-10);
        Assert.assertEquals(-10, sol.maxPathSum(root));
    }
    @Test
    public void testSimpleTree() {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        Assert.assertEquals(6, sol.maxPathSum(root));
    }
    @Test
    public void testBestInLeftTree() {
        TreeNode root = new TreeNode(-10);
        root.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.left.left = new TreeNode(2);
        root.right = new TreeNode(1);
        Assert.assertEquals(9, sol.maxPathSum(root));
    }
    @Test
    public void testNegativeLeaf() {
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(3);
        root.right = new TreeNode(-10);
        Assert.assertEquals(8, sol.maxPathSum(root));
    }
}
