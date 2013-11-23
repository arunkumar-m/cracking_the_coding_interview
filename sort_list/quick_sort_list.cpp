/*
 * =====================================================================================
 *
 *       Filename:  sort_list.cpp
 *
 *    Description:  sort a linked list in O(n log n) time using constant space complexity
 *
 *        Version:  1.0
 *        Created:  11/23/2013 00:09:24
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

void swap(ListNode *a, ListNode *b) {
    int val = a->val;
    a->val = b->val;
    b->val = val;
}

ListNode * partition(ListNode *head, ListNode **left, ListNode **right) {

    if (!head)
        return NULL;

    *left = NULL;
    *right = NULL;

    ListNode *pivot = head;

    ListNode *tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    // swap(head, tail);
    int pivotValue = tail->val;

    ListNode *p = head;
    while (p != tail) {
        if (p->val < pivotValue) {
            swap(pivot, p);
            pivot = pivot->next;
        }
        p = p->next;
    }

    ListNode *prev = head;
    if (pivot != head) {
        while (prev->next != pivot) {
            prev = prev->next;
        }
        prev->next = NULL;
        *left = head;
    }

    swap(pivot, tail);
    *right = pivot->next;

    return pivot;
}

void qsort(ListNode *head) {
    if (!head)
        return;
    ListNode *left, *right, *pivot;
    pivot = partition(head, &left, &right);
    qsort(left);
    qsort(right);

    if (left) {
        ListNode *p = left;
        while (p->next) {
            p = p->next;
        }
        p->next = pivot;
        pivot->next = right;
    }
    else {
        head = pivot;
        pivot->next = right;
    }
}

ListNode *sortList(ListNode *head) {
    qsort(head);
    return head;
}

void printList(ListNode *head) {
    ListNode *p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    ListNode *head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(20);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(100);

    qsort(head);

    printList(head);

    return 0;
}
