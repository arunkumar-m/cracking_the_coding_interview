/*
 * =====================================================================================
 *
 *       Filename:  buildTree.cpp
 *
 *        Version:  1.0
 *        Created:  12/20/2013 15:00:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* memory limit exceeded */
/*
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size() == 0) {
        return NULL;
    }
    int rootValue = postorder[postorder.size() - 1];
    TreeNode *root = new TreeNode(rootValue);
    vector<int>::iterator it = find(inorder.begin(), inorder.end(), rootValue);
    vector<int> left_inorder, right_inorder, left_postorder, right_postorder;
    left_inorder.assign(inorder.begin(), it);
    right_inorder.assign(it + 1, inorder.end());
    left_postorder.assign(postorder.begin(), postorder.begin() + left_inorder.size());
    right_postorder.assign(postorder.begin() + left_inorder.size(), postorder.end() - 1);
    TreeNode *left = buildTree(left_inorder, left_postorder);
    TreeNode *right = buildTree(right_inorder, right_postorder);
    root->left = left;
    root->right = right;
    return root;
}
*/

TreeNode *buildTree(vector<int> &inorder, int left1, int right1, vector<int> &postorder, int left2, int right2) {
    // cout << left1 << " " << right1 << " " << left2 << " " << right2 << endl;
    if (left1 > right1) {
        return NULL;
    }
    else if (left1 == right1) {
        return new TreeNode(inorder[left1]);
    }
    int rootValue = postorder[right2];
    TreeNode *root = new TreeNode(rootValue);
    vector<int>::iterator it = find(inorder.begin() + left1, inorder.end() + right1 + 1, rootValue);
    int new_left1 = left1, new_right1 = it - inorder.begin() - 1;
    int new_left2 = left2, new_right2 = new_left2 + new_right1 - new_left1;
    // cout << new_left1 << " " << new_right1 << " " << new_left2 << " " << new_right2 << endl;
    TreeNode *left = buildTree(inorder, new_left1, new_right1, postorder, new_left2, new_right2);
    new_left1 = it - inorder.begin() + 1;
    new_right1 = right1;
    new_left2 = new_right2 + 1;
    new_right2 = right2 - 1;
    // cout << new_left1 << " " << new_right1 << " " << new_left2 << " " << new_right2 << endl;
    TreeNode *right = buildTree(inorder, new_left1, new_right1, postorder, new_left2, new_right2);
    root->left = left;
    root->right = right;
    return root;
}

void printTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();
        if (curr) {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        }
        else {
            cout << "#" << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<int> inorder, postorder;
    int in_arr[] = {4,2,5,1,3,6};
    int post_arr[] = {4,5,2,6,3,1};
    inorder.assign(in_arr, in_arr + 6);
    postorder.assign(post_arr, post_arr + 6);
    TreeNode *root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    printTree(root);
    return 0;
}
