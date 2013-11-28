/*
 * =====================================================================================
 *
 *       Filename:  reorder_list.cpp
 *
 *        Version:  1.0
 *        Created:  11/27/2013 16:57:53
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

void reorderList(ListNode *head) {
    if (!head)
        return;
    ListNode *tail = head;
    ListNode *prev = NULL;
    while (tail->next) {
        prev = tail;
        tail = tail->next;
    }
    if (prev)
        prev->next = NULL;
    else {
        return;
    }
    ListNode *rest = head->next;
    head->next = tail;
    tail->next = rest;
    reorderList(rest);
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
    reorderList(head);
    printList(head);
    return 0;
}
