package com.wwei2.leetcode.binaryTreePreorderTraversal;

import com.wwei2.leetcode.util.TreeNode;

import java.util.LinkedList;
import java.util.List;

/**
 * Created by weiwei on 6/23/14.
 */
public class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<Integer>();
        preorderTraversalHelper(root, result);
        return result;
    }

    private void preorderTraversalHelper(TreeNode root, List<Integer> result) {
        if (root == null) {
            return;
        } else {
            result.add(root.val);
            preorderTraversalHelper(root.left, result);
            preorderTraversalHelper(root.right, result);
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(5);
        root.right = new TreeNode(15);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(6);
        List<Integer> result = sol.preorderTraversal(root);
        System.out.print("List: <");
        for (int i: result) {
            System.out.print(i + ",");
        }
        System.out.println(">");
    }
}
