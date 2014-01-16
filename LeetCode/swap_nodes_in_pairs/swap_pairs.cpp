/*
 * =====================================================================================
 *
 *       Filename:  swap_pairs.cpp
 *
 *        Version:  1.0
 *        Created:  11/30/2013 01:14:53
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

ListNode *swapPairs(ListNode *head) {
    if (!head)
        return NULL;
    else if (head && !head->next) {
        return head;
    }
    else {
        ListNode *rest = head->next->next;
        ListNode *p = head->next;
        p->next = head;
        head->next = swapPairs(rest);
        return p;
    }
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
    ListNode *p = swapPairs(head);
    printList(p);
    return 0;
}
