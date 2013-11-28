/*
 * =====================================================================================
 *
 *       Filename:  reorder_list.cpp
 *
 *        Version:  1.0
 *        Created:  11/27/2013 18:35:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int count(ListNode *head) {
    int cnt = 0;
    while (head) {
        head = head->next;
        cnt++;
    }
    return cnt;
}

void splitList(ListNode *head, ListNode **left, ListNode **right) {
    *left = NULL;
    *right = NULL;
    if (!head) {
        return;
    }
    int mid = (count(head) - 1) / 2;
    int cnt = 0;

    *left = head;
    while (head && cnt < mid) {
        head = head->next;
        cnt++;
    }

    *right = head->next;
    head->next = NULL;
}

ListNode *reverseList(ListNode *head) {
    if (!head || !head->next)
        return head;

    ListNode *prev;
    ListNode *curr;
    ListNode *post;

    prev = head;
    curr = head->next;
    head->next = NULL;
    post = curr->next;

    while (curr) {
        curr->next = prev;

        prev = curr;
        if (post) {
            curr = post;
            post = post->next;
        }
        else
            break;
    }

    return curr;
}

ListNode *mergeList(ListNode *left, ListNode *right) {
    if (!left)
        return NULL;
    ListNode *head = left;
    ListNode *curr = head;
    ListNode *left_curr = left->next;
    ListNode *right_curr = right;

    while (1) {
        curr->next = right_curr;
        curr = curr->next;
        if (!right_curr)
            break;
        right_curr = right_curr->next;
        curr->next = NULL;

        curr->next = left_curr;
        curr = curr->next;
        if (!left_curr)
            break;
        left_curr = left_curr->next;
        curr->next = NULL;
    }
    return head;
}

void reorderList(ListNode *head) {
    ListNode *left, *right;
    splitList(head, &left, &right);
    right = reverseList(right);
    head = mergeList(left, right);
}

void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
//    ListNode *left, *right;
//    splitList(head, &left, &right);
//    printList(left);
//    printList(right);
//    right = reverseList(right);
//    printList(right);
//    head = mergeList(left, right);
//    printList(head);
    reorderList(head);
    printList(head);
    return 0;
}
