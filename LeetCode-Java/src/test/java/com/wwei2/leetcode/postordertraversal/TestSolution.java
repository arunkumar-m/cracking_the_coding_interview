package com.wwei2.leetcode.postordertraversal;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;

import java.util.Arrays;
import java.util.List;

/**
 * Created by weiwei on 6/24/14.
 */
public class TestSolution {
    static private Solution sol = new Solution();
    static TreeNode root1;
    static TreeNode root2;

    @BeforeClass
    public static void beforeClass() {
        root1 = new TreeNode(5);
        root1.left = new TreeNode(1);

        root2 = new TreeNode(5);
        root2.left = new TreeNode(3);
        root2.right = new TreeNode(10);
        root2.left.left = new TreeNode(1);
        root2.left.right = new TreeNode(4);
        root2.right.left = new TreeNode(7);
        root2.right.right = new TreeNode(15);
    }

    @Test
    public void testTwoNodes() {
        List<Integer> list = sol.postorderTraversal(root1);
        System.out.println(list);
        Assert.assertTrue(list.equals(Arrays.asList(1, 5)));
    }

    @Test
    public void testSmallTree() {
        List<Integer> list = sol.postorderTraversal(root2);
        System.out.println(list);
        Assert.assertTrue(list.equals(Arrays.asList(1, 4, 3, 7, 15, 10, 5)));
    }

    @Test
    public void testTwoStackSolution() {
        List<Integer> list = sol.postorderTraversalTwoStack(root2);
        System.out.println(list);
        Assert.assertTrue(list.equals(Arrays.asList(1, 4, 3, 7, 15, 10, 5)));
    }
}
