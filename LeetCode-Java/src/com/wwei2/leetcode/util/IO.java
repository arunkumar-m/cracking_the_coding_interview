package com.wwei2.leetcode.util;

import java.util.List;

/**
 * Created by weiwei on 6/23/14.
 */
public class IO {
    public static <T> void printList(List<T> list) {
        System.out.print("List: <");
        for (T t: list) {
            System.out.print(t + ", ");
        }
        System.out.println(">");
    }

    public static <T> void printArray(T[] arr) {
        System.out.print("Array: <");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + ", ");
        }
        System.out.println(">");
    }
}
