package com.wwei2.leetcode.sumroottoleafnumbers;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/15/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testThreeNodes() {
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    Assert.assertEquals(25, sol.sumNumbers(root));
  }
}
