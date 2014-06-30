package com.wwei2.leetcode.util;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by weiwei on 6/29/14.
 */
public class TestListUtil {
    @Test
    public void testNull() {
        ListNode head = null;
        Assert.assertEquals(null, ListUtil.getMiddleElem(head));
    }
    @Test
    public void testOneElem() {
        ListNode head = new ListNode(1);
        Assert.assertEquals(1, ListUtil.getMiddleElem(head).val);
    }

    @Test
    public void testTwoElem() {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        Assert.assertEquals(1, ListUtil.getMiddleElem(head).val);
    }

    @Test
    public void testThreeElem() {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        Assert.assertEquals(2, ListUtil.getMiddleElem(head).val);
    }
}
