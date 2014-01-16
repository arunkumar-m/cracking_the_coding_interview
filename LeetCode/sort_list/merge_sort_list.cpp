/*
 * =====================================================================================
 *
 *       Filename:  merge_sort_list.cpp
 *
 *    Description:  merge sort
 *
 *        Version:  1.0
 *        Created:  11/23/2013 10:54:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {}
};

ListNode *merge(ListNode *p1, ListNode *p2) {
    ListNode *head = NULL, *p;
    while (p1 || p2) {
        if (p1 && p2 && p1->val < p2->val) {
            if (!head) {
                head = new ListNode(p1->val);
                p = head;
            }
            else {
                p->next = new ListNode(p1->val);
                p = p->next;
            }
            p1 = p1->next;
        }
        else if (p1 && p2 && p1->val >= p2->val) {
            if (!head) {
                head = new ListNode(p2->val);
                p = head;
            }
            else {
                p->next = new ListNode(p2->val);
                p = p->next;
            }
            p2 = p2->next;
        }
        else if (p1 && !p2) {
            if (!head) {
                head = new ListNode(p1->val);
                p = head;
            }
            else {
                p->next = new ListNode(p1->val);
                p = p->next;
            }
            p1 = p1->next;
        }
        else if (!p1 && p2) {
            if (!head) {
                head = new ListNode(p2->val);
                p = head;
            }
            else {
                p->next = new ListNode(p2->val);
                p = p->next;
            }
            p2 = p2->next;
        }
    }
    return head;
}

ListNode *mergesort(ListNode *head) {
    queue<ListNode *> q;
    ListNode *p = head, *next;
    while (p) {
        next = p->next;
        p->next = NULL;
        q.push(p);
        p = next;
    }

    // merge
    ListNode *p1, *p2;
    while (q.size() > 1) {
        p1 = q.front();
        q.pop();
        p2 = q.front();
        q.pop();
        q.push(merge(p1, p2));
    }

    return q.front();
}

ListNode *sortList(ListNode *head) {
    head = mergesort(head);
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
    ListNode *p1 = new ListNode(1);
    p1->next = new ListNode(3);
    p1->next->next = new ListNode(5);
    ListNode *p2 = new ListNode(2);
    p2->next = new ListNode(4);
    p1->next->next->next = p2;
    ListNode *p = mergesort(p1);
    printList(p);
    return 0;
}
