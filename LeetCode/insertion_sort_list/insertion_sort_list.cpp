/*
 * =====================================================================================
 *
 *       Filename:  insertion_sort_list.cpp
 *
 *    Description:  Sort a linked list using insertion sort
 *
 *        Version:  1.0
 *        Created:  11/24/2013 01:19:35
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

void insert(ListNode **head, int val) {
    ListNode *p = *head;
    while (p) {
        if (p->val <= val)
            p = p->next;
        else
            break;
    }

    if (p == *head) {
        p = new ListNode(val);
        p->next = *head;
        *head = p;
    }
    else{
        ListNode *prev = *head;
        while (prev) {
            if (prev->next == p) {
                break;
            }
            prev = prev->next;
        }
        p = new ListNode(val);
        p->next = prev->next;
        prev->next = p;
    }
}

ListNode *insertionSortList(ListNode *head) {
    if (!head) {
        return NULL;
    }
    ListNode *result = new ListNode(head->val);
    ListNode *p = head->next;

    while (p) {
        insert(&result, p->val);
        p = p->next;
    }
    
    return result;
}

void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(-10);
    printList(head);
    ListNode *result = insertionSortList(head);
    printList(result);
    return 0;
}
