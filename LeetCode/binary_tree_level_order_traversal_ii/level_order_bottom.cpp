/*
 * =====================================================================================
 *
 *       Filename:  level_order_bottom.cpp
 *
 *        Version:  1.0
 *        Created:  11/30/2013 15:08:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > result;
    queue<pair<TreeNode *, int> > q;
    q.push(make_pair(root, 1));
    while (!q.empty()) {
        TreeNode *curr = q.front().first;
        int level = q.front().second;
        q.pop();
        if (!curr) {
            continue;
        }
        if (result.size() < level) {
            vector<int> row;
            row.push_back(curr->val);
            result.push_back(row);
        }
        else {
            result[level - 1].push_back(curr->val);
        }
        q.push(make_pair(curr->left, level + 1));
        q.push(make_pair(curr->right, level + 1));
    }
    vector<vector<int> > reverse;
    for (int i = result.size() - 1; i >= 0; i--) {
        reverse.push_back(result[i]);
    }
    return reverse;
}

void printVV(vector<vector<int> > result) {
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int> > result = levelOrderBottom(root);
    printVV(result);
    return 0;
}
