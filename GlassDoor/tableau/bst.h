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
        // access to fields
        TreeNode *getLeft() { return left; }
        TreeNode *getRight() { return right; }

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
        void insert(int key);
        void remove(int key);
        bool lookup(int key);
        void print();
};

#endif
