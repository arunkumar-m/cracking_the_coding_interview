package com.wwei2.leetcode.validbst;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 8/6/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testTwoNodes() {
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(1);
    // root.right = new TreeNode(1);
    boolean valid = sol.isValidBST(root);
    Assert.assertEquals(false, valid);
  }
}
