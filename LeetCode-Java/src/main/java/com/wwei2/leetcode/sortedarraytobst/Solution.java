package com.wwei2.leetcode.sortedarraytobst;

import com.wwei2.leetcode.util.TreeNode;

/**
 * Created by weiwei on 7/21/14.
 */
public class Solution {
  public TreeNode sortedArrayToBST(int[] num) {
    return sortedArrayToBST(num, 0, num.length - 1);
  }
  private TreeNode sortedArrayToBST(int[] num, int start, int end) {
    if (start > end) {
      return null;
    }
    int mid = start + (end - start) / 2;
    TreeNode node = new TreeNode(num[mid]);
    TreeNode left = sortedArrayToBST(num, start, mid - 1);
    TreeNode right = sortedArrayToBST(num, mid + 1, end);
    node.left = left;
    node.right =right;
    return node;
  }
}
