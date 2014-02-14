#include <iostream>
#include "bst.h"

void inorder(TreeNode *);
void insertNode(TreeNode *, int);
TreeNode *smallestNode(TreeNode *);

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
    return false;
}

/*
 * help functions defined here
 */

void inorder(TreeNode *root) {
    if (!root) return;
    inorder(root->getLeft());
    std::cout << root->getKey() << " ";
    inorder(root->getRight());
}

void insertNode(TreeNode *root, int key) {
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

TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == NULL) return NULL;
    if (root->getKey() == key) {
        // root is the node to be removed
        if (root->getLeft() == NULL && root->getRight() == NULL) return NULL;
        if (root->getLeft() == NULL) return root->getRight();
        if (root->getRight() == NULL) return root->getLeft();

        // if root has 2 children
        // TODO: test it
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
 * return the smallest node in the binary search tree
 */
TreeNode *smallestNode(TreeNode *root) {

}
