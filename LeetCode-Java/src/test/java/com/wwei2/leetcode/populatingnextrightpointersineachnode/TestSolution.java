package com.wwei2.leetcode.populatingnextrightpointersineachnode;

import com.wwei2.leetcode.util.TreeLinkNode;
import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/17/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testSmallTree() {
    TreeLinkNode root = new TreeLinkNode(1);
    root.left = new TreeLinkNode(2);
    root.right = new TreeLinkNode(3);
    root.left.left = new TreeLinkNode(4);
    root.left.right = new TreeLinkNode(5);
    root.right.left = new TreeLinkNode(6);
    root.right.right = new TreeLinkNode(7);
    sol.connect(root);
    Assert.assertEquals(root.right, root.left.next);
    Assert.assertEquals(root.left.left.next, root.left.right);
    Assert.assertEquals(root.left.right.next, root.right.left);
    Assert.assertEquals(root.right.left.next, root.right.right);
  }
}
