/*
 * =====================================================================================
 *
 *       Filename:  isbalanced.cpp
 *
 *        Version:  1.0
 *        Created:  01/22/2014 01:33:13
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

int height(TreeNode *root) {
    if (!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

bool isbalanced(TreeNode *root) {
    if (!root) return true;
    return isbalanced(root->left) && isbalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
//    root->right->right = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    cout << isbalanced(root) << endl;
    return 0;
}
