#!/bin/python

def shiftright(ar, i, V):
    if ar[i] < V:
        ar[i + 1] = V
        return True
    else:
        ar[i + 1] = ar[i]
        return False

def printArr(ar):
    for i in ar:
        print i,
    print

def insertionSort(ar):    
    V = ar[-1]
    length = len(ar)
    for i in range(length - 2, -1, -1):
        if shiftright(ar, i, V):
            printArr(ar)
            return
        printArr(ar)
    ar[0] = V
    printArr(ar)

m = input()
ar = [int(i) for i in raw_input().strip().split()]
insertionSort(ar)
