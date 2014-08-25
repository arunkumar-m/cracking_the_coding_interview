package com.wwei2.leetcode.lrucache;

import java.util.HashMap;
import java.util.Map;

/**
 * Design and implement a data structure for Least Recently Used cache.
 */
public class LRUCache {

  private int capacity;
  private int size;
  private Map<Integer, ListNode> map;
  private ListNode head;
  private ListNode tail;

  private class ListNode {
    public int key;
    public int val;
    public ListNode next;
    public ListNode prev;
    public ListNode(int key, int val) {
      this.key = key;
      this.val = val;
      this.prev = null;
      this.next = null;
    }
  }

  public LRUCache(int capacity) {
    this.capacity = capacity;
    this.size = 0;
    this.map = new HashMap<>();
    this.head = new ListNode(0, 0); // Dummy head.
    this.tail = new ListNode(0, 0); // Dummy tail.
    // Connect dummy head with dummy tail.
    this.head.next = this.tail;
    this.tail.prev = this.head;

  }

  public int get(int key) {
    if (map.containsKey(key)) {
      ListNode node = map.get(key);
      remove(node);
      insert(node);
      return node.val;
    } else {
      return -1;
    }
  }

  public void set(int key, int value) {
    if (map.containsKey(key)) {
      ListNode node = map.get(key);
      // Modify value associated with key.
      node.val = value;
      // Remove node and re-insert.
      remove(node);
      insert(node);
    } else {
      ListNode node = new ListNode(key, value);
      if (size < capacity) {
        size++;
      } else {
        ListNode last = tail.prev;
        remove(last);
        map.remove(last.key);
      }
      insert(node);
      map.put(key, node);
    }
  }

  // Remove a node from the list.
  private void remove(ListNode node) {
    node.prev.next = node.next;
    node.next.prev = node.prev;
  }

  // Insert node into a list.
  private void insert(ListNode node) {
    ListNode next = head.next;
    head.next = node;
    node.prev = head;
    node.next = next;
    next.prev = node;
  }
}
