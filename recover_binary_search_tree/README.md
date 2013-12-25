# Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:

A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

## NOTE

It is quite natural to think of inorder traversal. However, it is a
little bit tricky to get it right. For example, I forgot to deal with
the case of val == -1 (the first element we run into).
