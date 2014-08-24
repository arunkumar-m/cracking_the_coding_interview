package com.wwei2.leetcode.util;

/**
 * Created by weiwei on 8/21/14.
 */
public class Point {
  public int x;
  public int y;
  public Point() { x = 0; y = 0; }
  public Point(int a, int b) { x = a; y = b; }
  @Override
  public String toString() {
    return "Point<" + x + ", " + y + ">";
  }
}
