/*
 * =====================================================================================
 *
 *       Filename:  reverselistrecursive.cpp
 *
 *        Version:  1.0
 *        Created:  01/21/2014 15:44:46
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

ListNode *reverseList(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *newhead = reverseList(head->next);
    ListNode *ptr = newhead;
    while (ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = head;
    head->next = NULL;
    return newhead;
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
    printList(reverseList(head));
    return 0;
}
