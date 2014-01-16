/*
 * =====================================================================================
 *
 *       Filename:  flatten.cpp
 *
 *        Version:  1.0
 *        Created:  12/19/2013 16:41:02
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode *root) {
    if (!root) return;

    TreeNode *left = root->left;
    TreeNode *right = root->right;

    flatten(left);
    flatten(right);

    root->left = NULL;
    if (left) {
        root->right = left;
        TreeNode *ptr = left;
        while (ptr->right) {
            ptr = ptr->right;
        }
        ptr->right = right;
    }
    else {
        root->right = right;
    }
}

void printTree(TreeNode *root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    flatten(root);
    printTree(root);
    return 0;
}
