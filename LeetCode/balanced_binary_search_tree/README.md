# Balanced Binary Search Tree

## Sorted Arrays: Supported Operations

SEARCH (binary search) O(log n)
SELECTION              O(1)
MIN/MAX                O(1)
PRED/SUCC              O(1)
RANK                   O(log n)
OUTPUT IN SORTED ORDER O(n)

But what about insertions and deletions?

INSERT                 O(n)
DELETE                 O(n)

## Balanced Search Trees: Supported Operations

like sorted arrays + fast (logarithmic) inserts + deletes!

SEARCH                 O(log n)
SELECT                 O(log n)
MIN/MAX                O(log n)
PRED/SUCC              O(log n)
RANK                   O(log n)
OUTPUT IN SORTED ORDER O(n)
INSERT                 O(log n)
DELETE                 O(log n)

## Binary Search Tree Structure

- exactly one node per key
- most basic version, each node has
  - left child pointer
  - right child pointer
  - parent pointer

SEARCH TREE PROPERTY
- all keys in left subtree are less than x
- all keys in the right subtree are larger than x

## The Height of a BST

Note: many possible trees for a set of keys
Note: height could be anywhere from log n to n

## Searching and Inserting

To SEARCH for key k in tree T

    - start at the root
    - traverse left/right child pointers as needed
    - return node with key k or NULL, as appropriate

To INSERT a new key k into a tree T

    - search for k
    - rewire final NULL ptr to point to new node with key k

Exercise: insertions preserves search tree property!

## Min, Max, Pred, and Succ

To compute the minimum key of a tree

    - start at root
    - follow left child pointers until you can't anymore (return last
      key found)

To compute the predecessor of key k

    - easy case: if k's left subtree nonempty, return max key in left
      subtree
    - otherwise: follow parent pointers until you get to a key less than
      k

## In-Order Traversal

To print out keys in increasing order

    - let r = root of search tree, with subtrees Tl and Tr
    - recurse on Tl
    [ by recursion/induction, prints out keys of Tl in increasing order ]
    - print out r's key
    - recurse on Tr
    [ prints out keys of Tr in increasing order ]

Running time is O(n)

## Deletion

To delete a key k from a search tree
    - search for k
    Easy case (k has no children)
    - just delete k's node from tree, done
    Medium case (k's node has one child)
    - just "splice out" k's node (unique child assumes position previously held by k's node)
    Difficult case (k's node has 2 children)
    - compute k's predecessor l
    [ traverse k's non-NULL left child ptr, then right child ptrs until
    no longer possible :]
    - swap k and l

Note: in its new position, k has no right child! => easy to delete or
splice out k's new node.

Exercise: at end, have a valid search tree!

Running time: O(log n)

## Select and Rank

Idea: store a little bit of extra info at each tree node about the tree
itself

Example Augmentation: size(x) = # of tree nodes in subtree rooted at x.
      
Note: if x has children y and z, then size(y) + size(z) + 1 = size(x)

How to SELECT ith order statistic from announced search tree (with
subtree sizes)
    - start at root x, with children y and z
    - let a = size(y) [a = 0 if x has no left child]
    - if a = i - 1 return x's key
    - if a >= i recursively compute ith order statistic of search tree
      rooted at y
    - if a < i - 1 recursively compute (i - a - 1)th order statistic of
      search tree rooted at z
