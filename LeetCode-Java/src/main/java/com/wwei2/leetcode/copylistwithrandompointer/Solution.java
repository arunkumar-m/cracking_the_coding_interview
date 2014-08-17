package com.wwei2.leetcode.copylistwithrandompointer;

import com.wwei2.leetcode.util.RandomListNode;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by weiwei on 8/16/14.
 */
public class Solution {
  public RandomListNode copyRandomList(RandomListNode head) {
    Map<RandomListNode, RandomListNode> map = new HashMap<>();
    if (head == null) {
      return null;
    }
    RandomListNode curr = head;
    while (curr != null) {
      RandomListNode newNode;
      if (map.containsKey(curr)) {
        newNode = map.get(curr);
      } else {
        newNode = new RandomListNode(curr.label);
        map.put(curr, newNode);
      }
      RandomListNode newNext;
      if (curr.next != null) {
        if (map.containsKey(curr.next)) {
          newNext = map.get(curr.next);
        } else {
          newNext = new RandomListNode(curr.next.label);
          map.put(curr.next, newNext);
        }
      } else {
        newNext = null;
      }
      RandomListNode newRandom;
      if (curr.random != null) {
        if (map.containsKey(curr.random)) {
          newRandom = map.get(curr.random);
        } else {
          newRandom = new RandomListNode(curr.random.label);
          map.put(curr.random, newRandom);
        }
      } else {
        newRandom = null;
      }
      newNode.next = newNext;
      newNode.random = newRandom;
      curr = curr.next;
    }
    return map.get(head);
  }
}
