/*
 * =====================================================================================
 *
 *       Filename:  inorder_traversal.cpp
 *
 *        Version:  1.0
 *        Created:  11/27/2013 15:39:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode *root, vector<int> &result) {
    if (!root)
        return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    inorder(root, result);
    return result;
}

void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> result = inorderTraversal(root);
    printVector(result);
    return 0;
}
