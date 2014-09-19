package com.wwei2.leetcode.populatingnextrightpointersineachnode2;

import com.wwei2.leetcode.util.TreeLinkNode;
import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 9/18/14.
 */
public class TestSolution {
  private Solution sol = new Solution();
  @Test
  public void testPerfectBinaryTree() {
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
  @Test
  public void testRandomBinaryTree() {
    TreeLinkNode root = new TreeLinkNode(1);
    root.left = new TreeLinkNode(2);
    root.right = new TreeLinkNode(3);
    root.left.left = new TreeLinkNode(4);
    root.right.right = new TreeLinkNode(5);
    sol.connect(root);
    Assert.assertEquals(root.right, root.left.next);
    Assert.assertEquals(root.left.left.next, root.right.right);
  }
  @Test
  public void testHigherBinaryTree() {
    TreeLinkNode root = new TreeLinkNode(1);
    root.left = new TreeLinkNode(2);
    root.right = new TreeLinkNode(3);
    root.left.left = new TreeLinkNode(4);
    root.right.right = new TreeLinkNode(5);
    root.left.left.right = new TreeLinkNode(6);
    root.right.right.left = new TreeLinkNode(7);
    root.right.right.right = new TreeLinkNode(8);
    root.left.left.right.left = new TreeLinkNode(9);
    root.left.left.right.right = new TreeLinkNode(10);
    root.right.right.right.left = new TreeLinkNode(11);
    sol.connect(root);
    Assert.assertEquals(root.right, root.left.next);
    Assert.assertEquals(root.right.right, root.left.left.next);
    Assert.assertEquals(root.right.right.left, root.left.left.right.next);
    Assert.assertEquals(root.right.right.right, root.right.right.left.next);
    Assert.assertEquals(root.left.left.right.right, root.left.left.right.left.next);
    Assert.assertEquals(root.right.right.right.left, root.left.left.right.right.next);
  }
}
