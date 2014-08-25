package com.wwei2.leetcode.lrucache;

import org.junit.Assert;
import org.junit.Test;

import java.util.LinkedList;
import java.util.List;

/**
 * Created by weiwei on 8/24/14.
 */
public class TestCache {
  @Test
  public void testCapacityFour() {
    String[] commands = {"SET 1 1", "SET 2 2", "SET 3 3", "SET 4 4", "GET 1",
        "SET 1 10", "SET 5 5", "GET 2", "GET 3", "SET 6 6", "GET 4", "GET 1",
        "GET 5", "GET 6"};
    int[] expected = {1, -1, 3, -1, 10, 5, 6};
    testHelper(4, commands, expected);
  }
  private void testHelper(int capacity, String[] commands, int[] expected) {
    LRUCache cache = new LRUCache(capacity);
    List<Integer> results = new LinkedList<>();
    for (String command : commands) {
      String[] words = command.split("\\s+");
      String type = words[0];
      int key, value;
      switch (type) {
        case "GET":
          key = Integer.parseInt(words[1]);
          results.add(cache.get(key));
          break;
        case "SET":
          key = Integer.parseInt(words[1]);
          value = Integer.parseInt(words[2]);
          cache.set(key, value);
          break;
        default:
          throw new IllegalArgumentException("A command should be either a GET or SET.");
      }
    }
    int[] actual = new int[results.size()];
    for (int i = 0; i < actual.length; i++) {
      actual[i] = results.get(i);
    }
    Assert.assertArrayEquals(expected, actual);
  }
}
