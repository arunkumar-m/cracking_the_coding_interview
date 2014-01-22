/*
 * =====================================================================================
 *
 *       Filename:  bst_next.cpp
 *
 *        Version:  1.0
 *        Created:  01/22/2014 00:34:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode (int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
    TreeNode (int x,  TreeNode *p, TreeNode *l = NULL, TreeNode *r = NULL) {
        val = x;
        left = l;
        right = r;
        parent = p;
    }
};

int getNext(TreeNode *node) {
    // case 1: the leftmost child of the right child
    if (node->right) {
        node = node->right;
        if (!node->left) return node->val;
        while (node->left) {
            node = node->left;
        }
        return node->val;
    }
    // case 2: navigate up the parent ancestor nodes, and when you find a parent whose left child is the node you're currently at, the parent is the inorder successor of your original node.
    else {
        TreeNode *curr = node, *prev = curr;
        if (curr->parent) {
            curr = curr->parent;
            while (curr) {
                if (curr->left == prev) {
                    return curr->val;
                }
                curr = curr->parent;
                prev = prev->parent;
            }
        }
        return node->val;
    }
}

int main() {
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2, root);
    root->right = new TreeNode(7, root);
    root->left->left = new TreeNode(1, root->left);
    root->left->right = new TreeNode(4, root->left);
    root->left->right->left = new TreeNode(3, root->left->right);
    root->left->right->right = new TreeNode(5, root->left->right);
    cout << getNext(root->right) << endl;
    return 0;
}
