package com.wwei2.leetcode.util;

/**
 * Created by weiwei on 8/2/14.
 */
public class ArrayUtil {
  public static int indexOf(int[] order, int start, int end, int elem) {
    for (int i = start; i <= end; i++) {
      if (order[i] == elem) {
        return i;
      }
    }
    return -1;
  }
}
