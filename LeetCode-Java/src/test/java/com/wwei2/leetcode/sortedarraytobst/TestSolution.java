package com.wwei2.leetcode.sortedarraytobst;

import com.wwei2.leetcode.util.TreeNode;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

/**
 * Created by weiwei on 7/21/14.
 */
public class TestSolution {
  private com.wwei2.leetcode.balancedbinarytree.Solution judge;
  private Solution sol;

  @Before
  public void setUp() throws Exception {
    sol = new Solution();
    judge = new com.wwei2.leetcode.balancedbinarytree.Solution();
  }

  @Test
  public void testSimple() {
    int[] num = {1, 2, 3, 4, 5};
    TreeNode node = sol.sortedArrayToBST(num);
    Assert.assertTrue(judge.isBalanced(node));
  }
  @Test
  public void testLarge() {
    int[] num = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    TreeNode node = sol.sortedArrayToBST(num);
    Assert.assertTrue(judge.isBalanced(node));
  }
}
