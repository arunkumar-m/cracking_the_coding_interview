/*
 * =====================================================================================
 *
 *       Filename:  linked_list.h
 *
 *        Version:  1.0
 *        Created:  12/06/2013 22:47:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

void deleteNode(ListNode **head, int val) {
    ListNode *curr, *prev = NULL;
    for (curr = *head; curr; prev = curr, curr = curr->next) {
        if (curr->val == val) {
            if (prev == NULL) {
                *head = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            delete curr;
            break;
        }
    }
}

void insertNode(ListNode **head, int val) {
    ListNode *ptr = new ListNode(val);
    ptr->next = *head;
    *head = ptr;
}

void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

#endif
