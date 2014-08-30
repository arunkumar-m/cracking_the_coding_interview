package com.wwei2.leetcode.clonegraph;

import com.wwei2.leetcode.util.UndirectedGraphNode;

import java.util.*;

/**
 * Clone graph.
 */
public class Solution {
  public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
    if (node == null) {
      return null;
    }
    Set<Integer> visited = new HashSet<>();
    Map<Integer, UndirectedGraphNode> mapping = new HashMap<>();
    Queue<UndirectedGraphNode> queue = new LinkedList<>();
    queue.add(node);
    while (!queue.isEmpty()) {
      UndirectedGraphNode curr = queue.remove();
      if (!visited.contains(curr.label)) {
        UndirectedGraphNode newNode;
        if (!mapping.containsKey(curr.label)) {
          newNode = new UndirectedGraphNode(curr.label);
          mapping.put(curr.label, newNode);
        } else {
          newNode = mapping.get(curr.label);
        }
        for (UndirectedGraphNode n : curr.neighbors) {
          UndirectedGraphNode  newNeighbor;
          if (!mapping.containsKey(n.label)) {
            newNeighbor = new UndirectedGraphNode(n.label);
            mapping.put(n.label, newNeighbor);
          } else {
            newNeighbor = mapping.get(n.label);
          }
          newNode.neighbors.add(newNeighbor);
          queue.add(n);
        }
        visited.add(curr.label);
      }
    }
    return mapping.get(node.label);
  }
}
