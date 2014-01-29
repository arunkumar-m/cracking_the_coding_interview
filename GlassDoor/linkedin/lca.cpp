/*
 * =====================================================================================
 *
 *       Filename:  lca.cpp
 *
 *        Version:  1.0
 *        Created:  01/28/2014 21:13:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

// lowest common ancestor
TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) return NULL;
    if (root == p || root == q) return root;
    TreeNode *left = lca(root->left, p, q);
    TreeNode *right = lca(root->right, p, q);
    if (left && right) {
        return root;
    }
    else if (left == p || left == q) {
        if (root == p || root == q) {
            return root;
        }
    }
    else if (right == p || right == q) {
        if (root == p || root == q) {
            return root;
        }
    }
    return left ? left : right;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->left->left->right = new TreeNode(6);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);
    assert(lca(root, root->right->right->left, root->right->right->right) == root->right->right);
    assert(lca(root, root->left->right, root->right) == root);
    assert(lca(root, root->left->left->left, root->left->right) == root->left);
    assert(lca(root, root->left->left->left, root->left->left->right) == root->left->left);
    return 0;
}
