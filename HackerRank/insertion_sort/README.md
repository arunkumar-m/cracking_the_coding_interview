# Insertion Sort

```
|<-   Sorted   ->|<- Unsorted ->|
|-------|--------|---|----------|
| <= x  |   > x  | x |   ...    |
|-------|--------|---|----------|
```

From [Wikipedia](http://en.wikipedia.org/wiki/Insertion_sort)

1. Suppose there exists a function called Insert designed to insert a
value into a sorted sequence at the beginning of an array. It
operates by beginning at the end of the sequence and shifting each
element one place to the right until a suitable position is found for
the new element. The function has the side effect of overwriting the
value stored immediately after the sorted sequence in the array.
2. To perform an insertion sort, begin at the left-most element of the
   array and invoke Insert to insert each element encountered into its
correct position. The ordered sequence into which the element is
inserted is stored at the beginning of the array in the set of indices
already examined. Each insertion overwrites a single value: the value
being inserted.
