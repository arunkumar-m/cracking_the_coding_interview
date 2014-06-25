package com.wwei2.leetcode.binaryTreePostorderTraversal;

import com.wwei2.leetcode.util.TreeNode;

import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

/**
 * Created by weiwei on 6/24/14.
 */
public class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list = new LinkedList<Integer>();
        TreeNode prev = new TreeNode(0); // Dummy
        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.add(root);
        while (!stack.empty()) {
            TreeNode node = stack.pop();
            if (node != null) {
                if ((node.left == null && node.right == null) ||
                        (node.right == null && prev == node.left) ||
                        prev == node.right) {
                    list.add(node.val);
                } else {
                    stack.push(node);
                    stack.push(node.right);
                    stack.push(node.left);
                }
                prev = node;
            }
        }
        return list;
    }
}
