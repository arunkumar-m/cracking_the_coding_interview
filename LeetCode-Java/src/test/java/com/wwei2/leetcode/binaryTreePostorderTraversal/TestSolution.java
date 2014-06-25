package com.wwei2.leetcode.binaryTreePostorderTraversal;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;
import java.util.List;

/**
 * Created by weiwei on 6/24/14.
 */
public class TestSolution {
   static private Solution sol = new Solution();
    @Test
    public void testTwoNodes() {
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(1);
        List<Integer> list = sol.postorderTraversal(root);
        System.out.println(list);
        Assert.assertTrue(list.equals(Arrays.asList(1, 5)));
    }
    @Test
    public void testSmallTree() {
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(3);
        root.right = new TreeNode(10);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(4);
        root.right.left = new TreeNode(7);
        root.right.right = new TreeNode(15);
        List<Integer> list = sol.postorderTraversal(root);
        System.out.println(list);
        Assert.assertTrue(list.equals(Arrays.asList(1, 4, 3, 7, 15, 10, 5)));
    }
}
