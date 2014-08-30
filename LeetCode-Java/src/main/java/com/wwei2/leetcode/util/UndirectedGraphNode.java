package com.wwei2.leetcode.util;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by weiwei on 8/29/14.
 */
public class UndirectedGraphNode {
  public int label;
  public List<UndirectedGraphNode> neighbors;
  public UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("label: " + label + ", neighbors: <");
    for (UndirectedGraphNode node : neighbors) {
      sb.append(node.label + ", ");
    }
    sb.append(">");
    return sb.toString();
  }
}
