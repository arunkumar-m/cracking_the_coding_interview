package com.wwei2.leetcode.mindepthofbinarytree;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 6/26/14.
 */
public class TestSolution {
    private Solution sol = new Solution();
    @Test
    public void testSingle() {
        TreeNode root = new TreeNode(1);
        Assert.assertEquals(1, sol.minDepth(root));
    }
    @Test
    public void testMultiple1() {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.left.left.left = new TreeNode(6);
        root.right = new TreeNode(5);
        System.out.println(root);
        Assert.assertEquals(2, sol.minDepth(root));
    }
    @Test
    public void testMultiple2() {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.left.left.left = new TreeNode(6);
        root.right = new TreeNode(5);
        root.right.left = new TreeNode(7);
        root.left.right.right = new TreeNode(8);
        System.out.println(root);
        Assert.assertEquals(3, sol.minDepth(root));
    }
}
