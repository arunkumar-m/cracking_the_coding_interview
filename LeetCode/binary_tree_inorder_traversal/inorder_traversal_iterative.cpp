/*
 * =====================================================================================
 *
 *       Filename:  inorder_traversal_iterative.cpp
 *
 *        Version:  1.0
 *        Created:  11/27/2013 16:01:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    TreeNode *current = root;
    stack<TreeNode *> st;
    while (current || !st.empty()) {
        if (current) {
            st.push(current);
            current = current->left;
        }
        else {
            current = st.top();
            st.pop();
            result.push_back(current->val);
            current = current->right;
        }
    }
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
