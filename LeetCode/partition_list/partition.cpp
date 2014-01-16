/*
 * =====================================================================================
 *
 *       Filename:  partition.cpp
 *
 *        Version:  1.0
 *        Created:  12/19/2013 15:47:09
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

void swap(ListNode *x, ListNode *y) {
    int tmp = x->val;
    x->val = y->val;
    y->val = tmp;
}

ListNode *partition(ListNode *head, int x) {
    ListNode *prev = NULL;
    ListNode *lt = head;
    while (lt) {
        if (lt->val < x) {
            break;
        }
        prev = lt;
        lt = lt->next;
    }
    if (lt) {
        if (prev) {
            prev->next = lt->next;
            lt->next = NULL;
        }
        else {
            head = lt->next;
            lt->next = NULL;
        }
    }
    prev = NULL;
    ListNode *geq = head;
    while (geq) {
        if (geq -> val >= x) {
            break;
        }
        prev = geq;
        geq = geq->next;
    }
    if (geq) {
        if (prev) {
            prev->next = geq->next;
            geq->next = NULL;
        }
        else {
            head = geq->next;
            geq->next = NULL;
        }
    }
    ListNode *lp = lt;
    ListNode *gp = geq;
    ListNode *p = head, *next;
    while (p) {
        next = p->next;
        if (p->val < x) {
            lp->next = p;
            p->next = NULL;
            lp = lp->next;
        }
        else {
            gp->next = p;
            p->next = NULL;
            gp = gp->next;
        }
        p = next;
    }
    if (lt) {
        lp->next = geq;
        return lt;
    }
    else if (geq) {
        return geq;
    }
    else {
        return NULL;
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
    //head->next = new ListNode(4);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(2);
    //head->next->next->next->next = new ListNode(5);
    //head->next->next->next->next->next = new ListNode(2);
    head = partition(head, 0);
    printList(head);
    return 0;
}
