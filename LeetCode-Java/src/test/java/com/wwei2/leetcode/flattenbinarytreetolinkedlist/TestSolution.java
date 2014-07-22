package com.wwei2.leetcode.flattenbinarytreetolinkedlist;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Assert;
import org.junit.Test;

import java.util.LinkedList;
import java.util.List;

import static com.wwei2.leetcode.util.IO.printList;

/**
 * Created by weiwei on 6/25/14.
 */
public class TestSolution {
    private Solution sol = new Solution();
    private boolean compareResults(List<Integer> list, int[] expected) {
        if (list.size() != expected.length) {
            return false;
        } else {
            for (int i = 0; i < expected.length; i++) {
                if (list.get(i) != expected[i]) {
                    return false;
                }
            }
        }
        return true;
    }
    private List<Integer> flattenedTreeToList(TreeNode root) {
        List<Integer> list = new LinkedList<Integer>();
        while (root != null) {
            list.add(root.val);
            root = root.right;
        }
        return list;
    }
    @Test
    public void testSingle() {
        TreeNode root = new TreeNode(1);
        sol.flatten(root);
        List<Integer> list = flattenedTreeToList(root);
        Assert.assertTrue(compareResults(list, new int[]{1}));
    }
    @Test
    public void testSimple() {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        sol.flatten(root);
        List<Integer> list = flattenedTreeToList(root);
        Assert.assertTrue(compareResults(list, new int[]{1, 2, 3}));
    }
    @Test
    public void testComplex() {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.right = new TreeNode(5);
        root.right.right = new TreeNode(6);
        sol.flatten(root);
        List<Integer> list = flattenedTreeToList(root);
        Assert.assertTrue(compareResults(list, new int[]{1, 2, 3, 4, 5, 6}));
    }
}
