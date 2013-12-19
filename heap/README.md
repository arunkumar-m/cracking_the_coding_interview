# Heap

- A container of objects that have keys
  - employer records, network edges, events, etc.

## Supported Operations

INSERT: add a new object to a heap
  - Running time: O(log n)

EXTRACT-MIN: remove an object in heap with a minimum key value. [ties
broken randomly]
  - Running time: O(log n)

Also: HEAPIFY (n batched Inserts in O(n) time), DELETE (O(log n) time)

## The Heap Property

Conceptually: think of a heap as a tree
- rooted, binary, as complete as possible

Heap property: at every node x, key[x] <= all keys of x's children

Consequence: object at root must have minimum key value

## Array Implementation

parent(i) = i / 2 if i is even = floor(i / 2) if i is odd

children of i are 2i, 2i + 1

## Insert and Bubble-Up

Implementation of Insert (given key k)

    1. stick k at end of last level
    2. bubble-up k until heap property is restored

Check:
- bubbling up process must stop with heap property restored
- runtime = O(log n)

## Extract-Min and Bubble-Down

Implementation of Extract-Min

    1. delete root
    2. move last leaf to be new root
    3. Iteractively bubble-down until heap property has been restored

Check:
- only bubble-down once per level, halt with a heap
- runtime = O(log n)
