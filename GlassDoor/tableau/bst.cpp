#include <iostream>
#include "bst.h"

static void inorder(TreeNode *);
static void insertNode(TreeNode *, int);
static TreeNode *deleteNode(TreeNode *, int);
static TreeNode *smallestNode(TreeNode *);
static bool lookupKey(TreeNode *, int);

void BST::print() {
    TreeNode *ptr = root;
    inorder(root);
    std::cout << std::endl;
}

void BST::insert(int key) {
    // if root is null
    if (!root) {
        root = new TreeNode(key);
    }
    // if root is not null
    else {
        insertNode(root, key);
    }
}

void BST::remove(int key) {
    root = deleteNode(root, key);
}

bool BST::lookup(int key) {
    return lookupKey(root, key);
}

/*
 * help functions defined here
 */

static void inorder(TreeNode *root) {
    if (!root) return;
    inorder(root->getLeft());
    std::cout << root->getKey() << " ";
    inorder(root->getRight());
}

static void insertNode(TreeNode *root, int key) {
    if (root->getKey() == key) {
        std::cout << "DUPLICATE KEY" << std::endl;
        return;
    }
    // insert the node in the left subtree
    if (key < root->getKey()) {
        if (!root->getLeft()) {
            std::cout << "set left" << std::endl;
            root->setLeft(new TreeNode(key));
        } else {
            std::cout << "insert into the left subtree" << std::endl;
            insertNode(root->getLeft(), key);
        }
    }
    // insert the node in the right subtree
    else {
        if (!root->getRight()) {
            std::cout << "set right" << std::endl;
            root->setRight(new TreeNode(key));
        } else {
            std::cout << "insert into the right subtree" << std::endl;
            insertNode(root->getRight(), key);
        }
    }
}

static TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == NULL) return NULL;
    if (root->getKey() == key) {
        // root is the node to be removed
        if (root->getLeft() == NULL && root->getRight() == NULL) return NULL;
        if (root->getLeft() == NULL) return root->getRight();
        if (root->getRight() == NULL) return root->getLeft();

        // if root has 2 children
        int smallest = smallestNode(root->getRight())->getKey();
        root->setKey(smallest);
        root->setRight(deleteNode(root->getRight(), smallest));
    } else if (key < root->getKey()) {
        // go left
        root->setLeft(deleteNode(root->getLeft(), key));
        return root;

    } else {
        // go right
        root->setRight(deleteNode(root->getRight(), key));
        return root;
    }
}

/*
 * lookup if value exists in the binary search tree
 */
static bool lookupKey(TreeNode *root, int key) {
  if (!root) return false;
  if (root->getKey() == key)
      return true;
  else {
      if (key < root->getKey()) {
          return lookupKey(root->getLeft(), key);
      }
      else {
          return lookupKey(root->getRight(), key);
      }
  }
}

/*
 * return the smallest node in the binary search tree
 */
static TreeNode *smallestNode(TreeNode *root) {
    if (!root) return NULL;
    while (root->getLeft()) {
        root = root->getLeft();
    }
    return root;
}
