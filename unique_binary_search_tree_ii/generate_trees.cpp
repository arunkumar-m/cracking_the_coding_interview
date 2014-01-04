/*
 * =====================================================================================
 *
 *       Filename:  generate_trees.cpp
 *
 *        Version:  1.0
 *        Created:  12/16/2013 16:33:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode *> generateTreesHelper(int begin, int end) {
    vector<TreeNode *> results;
    if (begin > end) {
        results.push_back(NULL);
        return results;
    }
    if (begin == end) {
        results.push_back(new TreeNode(begin));
        return results;
    }
    vector<TreeNode *> left, right;
    for (int i = begin; i <= end; i++) {
        left = generateTreesHelper(begin, i - 1);
        right = generateTreesHelper(i + 1, end);
        for (int j = 0; j < left.size(); j++) {
            for (int k = 0; k < right.size(); k++) {
                TreeNode *root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                results.push_back(root);
            }
        }
    }
    return results;
}

vector<TreeNode *> generateTrees(int n) {
    return generateTreesHelper(1, n);
}

void printTree(TreeNode *root) {
    if (!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    vector<TreeNode *> ret = generateTrees(3);
    for (int i = 0; i < ret.size(); i++) {
        printTree(ret[i]);
        cout << endl;
    }
    return 0;
}
