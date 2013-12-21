/*
 * =====================================================================================
 *
 *       Filename:  build_tree.cpp
 *
 *        Version:  1.0
 *        Created:  12/20/2013 20:02:16
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTreeHelper(vector<int> &preorder, int iBegin1, int iEnd1, vector<int> &inorder, int iBegin2, int iEnd2) {
    // cout << "buildTreeHelper(" << iBegin1 << ", " << iEnd1 << ", " << iBegin2 << ", " << iEnd2 << ")" << endl;
    if (iBegin1 > iEnd1) {
        return NULL;
    }
    else if (iBegin1 == iEnd1) {
        return new TreeNode(preorder[iBegin1]);
    }
    TreeNode *root = new TreeNode(preorder[iBegin1]);
    vector<int>::iterator it = find(inorder.begin(), inorder.end(), preorder[iBegin1]);
    TreeNode *left = buildTreeHelper(preorder, iBegin1 + 1, it - inorder.begin() - iBegin2 + iBegin1, inorder, iBegin2, it - inorder.begin() - 1);
    TreeNode *right = buildTreeHelper(preorder, it - inorder.begin() - iBegin2 + iBegin1 + 1, iEnd1, inorder, it - inorder.begin() + 1, iEnd2);
    root->left = left;
    root->right = right;
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    TreeNode *root = buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
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
            cout << "# ";
        }
    }
    cout << endl;
}

int main() {
    vector<int> preorder, inorder;
    int pre[] = {1,2,4,5,3,6};
    int in[] = {4,2,5,1,3,6};
    preorder.assign(pre, pre + 6);
    inorder.assign(in, in + 6);
    TreeNode *root = buildTree(preorder, inorder);
    printTree(root);
    return 0;
}
