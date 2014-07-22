package com.wwei2.leetcode.medianoftwosortedarrays;

/**
 * Created by weiwei on 5/20/14.
 */
public class Solution {

    /* Find median of two sorted arrays A, B. */
    public static double findMedianSortedArrays(int A[], int B[]) {
        return findMedianSortedArrays(A, 0, A.length, B, 0, B.length);
    }

    public static double findMedianSortedArrays(int A[], int aOffset, int m, int B[], int bOffset, int n) {
        // System.out.println(aOffset + " " + m + " " + bOffset + " " + n);
        if (m == 0) {
            return findMedianSortedArray(B, bOffset, B.length);
        } else if (n == 0) {
            return findMedianSortedArray(A, aOffset, A.length);
        } else if (m == 1) {
            return findMedianSortedArrays(A[aOffset], B, bOffset, n);
        } else if (n == 1) {
            return findMedianSortedArrays(B[bOffset], A, aOffset, m);
        } else if (m == 2) {
            return findMedianSortedArrays(A[aOffset], A[aOffset + 1], B, bOffset, n);
        } else if (n == 2) {
            return findMedianSortedArrays(B[bOffset], B[bOffset + 1], A, aOffset, m);
        } else if (A[aOffset + m / 2] <= B[bOffset + n / 2]) {
            int len = ((m % 2 == 0) ? Math.min(m / 2 - 1, n - n / 2 - 1) : Math.min(m / 2, n - n / 2 - 1));
            return findMedianSortedArrays(A, aOffset + len, m - len, B, bOffset, n - len);
        } else {
            int len = ((n % 2 == 0) ? Math.min(m - m / 2 - 1, n / 2 - 1) : Math.min(m - m / 2 - 1, n / 2));
            return findMedianSortedArrays(B, bOffset + len, n - len, A, aOffset, m - len);
        }
    }

    /* Find median in two sorted arrays in which at least one of them has only two elements. */
    private static double findMedianSortedArrays(int a, int b, int[] arr, int offset, int length) {
        if (length == 0) {
            return (a + b) / 2.0;
        } else if (length == 1) {
            if (arr[offset] < a) {
                return a;
            } else if (arr[offset] > b) {
                return b;
            } else {
                return arr[offset];
            }
        } else if (length % 2 == 0) {
            if (b < arr[offset]) {
               return findMedianSortedArrays(b, arr, offset, length - 1);
            } else if (a > arr[offset + length - 1]) {
                return findMedianSortedArrays(a, arr, offset + 1, length - 1);
            } else if (a < arr[offset] && b > arr[offset + length - 1]) {
                return findMedianSortedArray(arr, offset, length);
            } else {
                if (a < arr[offset]) {
                    return findMedianSortedArrays(b, arr, offset, length - 1);
                } else if (b > arr[offset + length - 1]) {
                    return findMedianSortedArrays(a, arr, offset + 1, length - 1);
                } else {
                    return findMedianSortedArrays(a, b, arr, offset + 1, length - 2);
                }
            }
        } else {
            if (b < arr[offset]) {
                return findMedianSortedArray(arr, offset, length - 2);
            } else if (a > arr[offset + length - 1]) {
                return findMedianSortedArray(arr, offset + 2, length - 2);
            } else if (a < arr[offset] && b > arr[offset + length - 1]) {
                return findMedianSortedArray(arr, offset, length);
            } else {
                return findMedianSortedArrays(a, b, arr, offset + 1, length - 2);
            }
        }
    }

    /* Find median in a sorted array plus a single element. */
    private static double findMedianSortedArrays(int elem, int[] arr, int offset, int length) {
        // System.out.println(elem + " " + offset + " " + length);
        if (length == 1) {
            return (elem + arr[offset]) / 2.0;
        }
        if (length % 2 == 0) {
            if (elem < arr[offset + length / 2 - 1]) {
                return arr[offset + length / 2 - 1];
            } else if (elem > arr[offset + length / 2]) {
                return arr[offset + length / 2];
            } else {
                return elem;
            }
        } else {
            int mid = offset + length / 2;
            if (elem < arr[mid - 1]) {
                return (arr[mid] + arr[mid - 1]) / 2.0;
            } else if (elem > arr[mid + 1]) {
                return (arr[mid] + arr[mid + 1]) / 2.0;
            } else {
                return (arr[mid] + elem) / 2.0;
            }
        }
    }

    /* Find median in a single sorted array. */
    private static double findMedianSortedArray(int[] arr, int offset, int length) {
        if (length % 2 == 1) {
            return arr[offset + length / 2];
        } else {
            return (arr[offset + length / 2 - 1] + arr[offset + length / 2]) / 2.0;
        }
    }

    public static void main(String[] args) {
        int[] A = {1, 5, 6, 7};
        int[] B = {2, 3, 4, 8, 9, 10};
        System.out.println(findMedianSortedArrays(A, B));
    }
}
