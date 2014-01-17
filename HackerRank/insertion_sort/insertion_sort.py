#!/bin/python

# Head ends here
def printArr(ar):
    for i in ar:
        print i,
    print

def insertionSort(ar):    
    for i in range(1, len(ar)):
        j = i
        while j > 0 and ar[j - 1] > ar[j]:
            ar[j - 1], ar[j] = ar[j], ar[j - 1]
            j = j - 1
        printArr(ar)

# Tail starts here

m = input()
ar = [int(i) for i in raw_input().strip().split()]
insertionSort(ar)
