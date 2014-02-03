/*
 * =====================================================================================
 *
 *       Filename:  conv_sorted_array_to_bbst.cpp
 *
 *        Version:  1.0
 *        Created:  02/03/2014 11:12:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *sortedArray2BBST(int arr[], int left, int right) {
    if (left > right) return NULL;
    if (left == right) return new TreeNode(arr[left]);
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(arr[mid]);
    TreeNode *leftchild = sortedArray2BBST(arr, left, mid - 1);
    TreeNode *rightchild = sortedArray2BBST(arr, mid + 1, right);
    root->left = leftchild;
    root->right = rightchild;
    return root;
}

void printTree(TreeNode *root) {
    if (!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

void levelOrderTraversal(TreeNode *root) {
    queue<TreeNode *> currlevel;
    queue<TreeNode *> nextlevel;
    currlevel.push(root);
    while (!currlevel.empty()) {
        TreeNode *curr = currlevel.front();
        currlevel.pop();
        if (!curr) continue;
        cout << curr->val << " ";
        nextlevel.push(curr->left);
        nextlevel.push(curr->right);
        if (currlevel.empty()) {
            cout << endl;
            currlevel = nextlevel;
            nextlevel = queue<TreeNode*>();
        }
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    TreeNode *root = sortedArray2BBST(arr, 0, 8);
    cout << "in-order traversal" << endl;
    printTree(root);
    cout << endl;
    cout << "level order traversal" << endl;
    levelOrderTraversal(root);
    return 0;
}
