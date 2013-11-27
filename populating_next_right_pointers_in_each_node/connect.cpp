/*
 * =====================================================================================
 *
 *       Filename:  connect.cpp
 *
 *        Version:  1.0
 *        Created:  11/27/2013 01:01:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

struct TreeLinkNode {
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
};

void connect(TreeLinkNode *root) {
    if (!root || (!root->left && !root->right))
        return;
    root->left->next = root->right;
    if (root->next) {
        root->right->next = root->next->left;
    }
    connect(root->left);
    connect(root->right);
}

int main() {
    return 0;
}
