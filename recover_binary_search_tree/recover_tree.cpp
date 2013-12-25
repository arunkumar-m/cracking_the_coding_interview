/*
 * =====================================================================================
 *
 *       Filename:  recover_tree.cpp
 *
 *        Version:  1.0
 *        Created:  12/25/2013 13:32:34
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


TreeNode *find(TreeNode *root, int val) {
    if (!root) return NULL;
    if (root->val == val)
        return root;
    else {
        TreeNode *ret = find(root->left, val);
        if (ret)
            return ret;
        ret = find(root->right, val);
        if (ret)
            return ret;
        return NULL;
    }
}

void inorderTraversal(TreeNode *root, int &val, int &ret1, int &ret2) {
    if (!root)
        return;
    inorderTraversal(root->left, val, ret1, ret2);
    if (val == -1) {
        val = root->val;
    }
    else {
        if (root->val < val) {
            if (ret1 == -1) {
                ret1 = val;
                ret2 = root->val;
            }
            else {
                ret2 = root->val;
            }
        }
        val = root->val;
    }
    inorderTraversal(root->right, val, ret1, ret2);
}

void recoverTree(TreeNode *root) {
    int val = -1;
    int ret1 = -1, ret2 = -1;
    inorderTraversal(root, val, ret1, ret2);
    TreeNode *node1 = find(root, ret1);
    TreeNode *node2 = find(root, ret2);
    int tmp = node1->val;
    node1->val = node2->val;
    node2->val = tmp;
}

void printTree(TreeNode *root) {
    if (!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    printTree(root);
    cout << endl;
    recoverTree(root);
    printTree(root);
    cout << endl;
    return 0;
}
