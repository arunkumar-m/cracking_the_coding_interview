/*
 * =====================================================================================
 *
 *       Filename:  del.cpp
 *
 *        Version:  1.0
 *        Created:  01/24/2014 13:21:56
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

void del(ListNode **head, int val) {
    ListNode *p = *head;
    if (!p) return;
    ListNode *prev = NULL;
    while (p) {
        if (p->val == val) {
            if (prev) {
                prev->next = p->next;
                delete p;
            }
            else {
                delete *head;
                *head = (*head)->next;
            }
            return;
        }
        prev = p;
        p = p->next;
    }
}

int main() {
    return 0;
}
