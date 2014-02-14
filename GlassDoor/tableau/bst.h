/*
 * Binary Search Tree declarations
 */

//=================================
// include guard
#ifndef __BST_H__
#define __BST_H__

class TreeNode {
    private:
        int key;
        TreeNode *left, *right;
    public:
        // constructor
        TreeNode(int k) : key(k), left(NULL), right(NULL) {}
        TreeNode(int k, TreeNode *l, TreeNode *r) {
            key = k;
            left = l;
            right = r;
        }
        // access to fields
        TreeNode *getLeft() { return left; }
        TreeNode *getRight() { return right; }
        int getKey() { return key; }

        // change fields
        void setKey(int k) { key = k; }
        void setLeft(TreeNode *l) { left = l; }
        void setRight(TreeNode *r) { right = r; }
};

class BST {
    // *** fields ***
    private:
        TreeNode *root;
    // *** methods ***
    public:
        BST() : root(NULL) {}
        void insert(int key);
        void remove(int key);
        bool lookup(int key);
        void print();
};

#endif
