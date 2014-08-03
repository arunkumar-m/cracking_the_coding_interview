package com.wwei2.leetcode.buildtreefrompreorderinorder;

import com.wwei2.leetcode.util.TreeNode;

import static com.wwei2.leetcode.util.ArrayUtil.indexOf;

/**
 * Build tree from preorder and inorder traversal.
 */
public class Solution {

  public TreeNode buildTree(int[] preorder, int[] inorder) {
    return buildTreeHelper(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
  }

  private TreeNode buildTreeHelper(int[] preorder, int start1, int end1,
                                  int[] inorder, int start2, int end2) {
    if (start1 > end1) {
      return null;
    } else if (start1 == end1) {
      return new TreeNode(preorder[start1]);
    } else {
      TreeNode root = new TreeNode(preorder[start1]);
      int idx = indexOf(inorder, start2, end2, preorder[start1]);
      TreeNode left = buildTreeHelper(preorder, start1 + 1, start1 + idx - start2, inorder, start2, idx - 1);
      TreeNode right = buildTreeHelper(preorder, start1 + idx - start2 + 1, end1, inorder, idx + 1, end2);
      root.left = left;
      root.right = right;
      return root;
    }
  }
}
