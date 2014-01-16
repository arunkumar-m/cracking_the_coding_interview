/*
 * =====================================================================================
 *
 *       Filename:  connect.cpp
 *
 *        Version:  1.0
 *        Created:  12/04/2013 13:44:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL) {}
};

void connect (TreeLinkNode *root) {
    queue<pair<TreeLinkNode *, int> > q;
    q.push(make_pair(root, 1));
    TreeLinkNode *prev = NULL, *curr = NULL;
    int curr_level = 0, prev_level = 0;
    while (!q.empty()) {
        curr = q.front().first;
        curr_level = q.front().second;
        q.pop();
        if (!curr) {
            continue;
        }
        if (prev) {
            if (prev_level == curr_level) {
                prev->next = curr;
            }
        }
        prev = curr;
        prev_level = curr_level;
        q.push(make_pair(curr->left, curr_level+1));
        q.push(make_pair(curr->right, curr_level+1));
    }
}

void printTree(TreeLinkNode *root) {
    queue<TreeLinkNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeLinkNode *curr = q.front();
        q.pop();
        if (curr) {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        }
        else {
            cout << "# ";
        }
    }
    cout << endl;
}

int main() {
    TreeLinkNode *root = new TreeLinkNode(2);
    root->left = new TreeLinkNode(1);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(0);
    root->left->right = new TreeLinkNode(7);
    root->right->left = new TreeLinkNode(9);
    root->right->right = new TreeLinkNode(1);
    root->left->left->left = new TreeLinkNode(2);
    root->left->right->left = new TreeLinkNode(1);
    root->left->right->right = new TreeLinkNode(0);
    root->right->right->left = new TreeLinkNode(8);
    root->right->right->right = new TreeLinkNode(8);
    root->left->right->right->left = new TreeLinkNode(7);
    printTree(root);
    connect(root);
    cout << root->right->left->next << endl;
    cout << root->left->right->right->next << endl;
    return 0;
}
