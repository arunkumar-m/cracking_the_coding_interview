#include <iostream>
#include "bst.h"

void inorder(TreeNode *);

void BST::print() {
    TreeNode *ptr = root;
    inorder(root);
    std::cout << std::endl;
}

void BST::insert(int key) {

}

void BST::remove(int key) {

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
    std::cout << root << " ";
    inorder(root->getRight());
}
