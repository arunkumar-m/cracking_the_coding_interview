package com.wwei2.leetcode.buildtreefrompreorderinorder;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 8/3/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmall() {
    int[] inorder = {1, 2, 3};
    int[] preorder = {2, 1, 3};
    TreeNode root = sol.buildTree(preorder, inorder);
    Assert.assertEquals(2, root.val);
    Assert.assertEquals(1, root.left.val);
    Assert.assertEquals(3, root.right.val);
  }
  @Test
  public void testMid() {
    int[] inorder = {4, 2, 5, 1, 3, 6};
    int[] preorder = {1, 2, 4, 5, 3, 6};
    TreeNode root = sol.buildTree(preorder, inorder);
    Assert.assertEquals(1, root.val);
    Assert.assertEquals(2, root.left.val);
    Assert.assertEquals(3, root.right.val);
    Assert.assertEquals(4, root.left.left.val);
    Assert.assertEquals(5, root.left.right.val);
    Assert.assertEquals(6, root.right.right.val);
  }
}
