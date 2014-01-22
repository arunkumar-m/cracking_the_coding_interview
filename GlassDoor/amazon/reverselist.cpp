/*
 * =====================================================================================
 *
 *       Filename:  reverselist.cpp
 *
 *        Version:  1.0
 *        Created:  01/21/2014 01:46:23
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
    ListNode (int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head) {
    ListNode *newhead = NULL;
    while (head) {
        ListNode *next = head->next;
        head->next = newhead;
        newhead = head;
        head = next;
    }
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
    head->next->next->next = new ListNode(4);
    head = reverseList(head);
    printList(head);
    return 0;
}
