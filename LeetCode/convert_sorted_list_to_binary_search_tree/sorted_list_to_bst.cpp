/*
 * =====================================================================================
 *
 *       Filename:  sorted_list_to_bst.cpp
 *
 *        Version:  1.0
 *        Created:  12/15/2013 15:43:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int len(ListNode *head) {
    int cnt = 0;
    while (head) {
        head = head->next;
        cnt++;
    }
    return cnt;
}

TreeNode *sortedList2BST(ListNode *&head, int start, int end) {
    if (start > end) return NULL;
    int mid = start + (end - start) / 2;
    TreeNode *left = sortedList2BST(head, start, mid - 1);
    TreeNode *root = new TreeNode(head->val);
    root->left = left;
    head = head->next;
    root->right = sortedList2BST(head, mid + 1, end);
    return root;
}

TreeNode *sortedListToBST(ListNode *head) {
    int length = len(head);
    return sortedList2BST(head, 0, length-1);
}

void printTree(TreeNode *root) {
    queue<pair<TreeNode *, int> > q;
    q.push(make_pair(root, 1));
    while (!q.empty()) {
        TreeNode *curr = q.front().first;
        int level = q.front().second;
        q.pop();
        if (!curr) {
            cout << "# ";
            continue;
        }
        cout << curr->val << " ";
        q.push(make_pair(curr->left, level + 1));
        q.push(make_pair(curr->right, level + 1));
    }
    cout << endl;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    TreeNode *root = sortedListToBST(head);
    printTree(root);
    return 0;
}
