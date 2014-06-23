#include <iostream>
using namespace std;

static const int kMaxInt = 0x7fffffff;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int v) : val(v), left(NULL), right(NULL) {}
  TreeNode(int v, TreeNode *l, TreeNode *r) : val(v), left(l), right(r) {}
};

static inline int abs(int x) {
  return x >= 0 ? x : -x;
}

static inline int max(int x, int y) {
  return x >= y ? x : y;
}

static int IsBalancedHelper(TreeNode *root, int level) {
  if (!root)
    return level;
  int l = IsBalancedHelper(root->left, level);
  int r = IsBalancedHelper(root->right, level);
  if (abs(l - r) > 1)
    return kMaxInt;
  else
    return max(l, r) + 1;
}

bool IsBalanced(TreeNode *root) {
  return IsBalancedHelper(root, 0) < kMaxInt;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->right->left = new TreeNode(7);
  cout << "IsBalanced: " << IsBalanced(root) << endl;
  return 0;
}
