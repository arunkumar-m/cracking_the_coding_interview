package com.wwei2.leetcode.buildtreefrominorderpostorder;

import com.wwei2.leetcode.util.TreeNode;

import static com.wwei2.leetcode.util.ArrayUtil.indexOf;

/**
 * Construct binary tree from inorder and postorder traversal.
 */
public class Solution {

  public TreeNode buildTree(int[] inorder, int[] postorder) {
    return buildTreeHelper(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
  }

  private TreeNode buildTreeHelper(int[] inorder, int start1, int end1, int[] postorder, int start2, int end2) {
    if (start1 > end1) {
      return null;
    } else if (start1 == end1) {
      return new TreeNode(inorder[start1]);
    } else {
      TreeNode root = new TreeNode(postorder[end2]);
      int idx = indexOf(inorder, start1, end1, postorder[end2]);
      TreeNode left = buildTreeHelper(inorder, start1, idx - 1, postorder, start2, start2 + idx - 1 - start1);
      TreeNode right = buildTreeHelper(inorder, idx + 1, end1, postorder, start2 + idx - start1, end2 - 1);
      root.left = left;
      root.right = right;
      return root;
    }
  }
}
