# Amazon

## Arithmetic

- Pow
- Div

## Longest Repeated Substring

[http://introcs.cs.princeton.edu/java/42sort/LRS.java.html](http://introcs.cs.princeton.edu/java/42sort/LRS.java.html)

First form N suffixes, then sort them and compute the longest common
substring of adjacent sorted suffixes.

## Binary Search Tree

- Given a node, find the next highest value in the BST
- To tell whether a BST is balanced
  - One thing to note is that left tree and right tree should be height
    balanced as well!!
- maximum path sum in binary search tree
  - left tree path plus current root
  - right tree path plus current root
  - path passes through the root: left path + current root + right path
- tell if a tree is a binary search tree
  - inorder traversal
  - isBSThelper(root, low, high)

## Deep Copy of a List

- DFS
- Use a map that maps old node to new node
- the map is also served as visited
