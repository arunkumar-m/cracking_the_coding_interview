/*
 * =====================================================================================
 *
 *       Filename:  rotate_right.cpp
 *
 *        Version:  1.0
 *        Created:  12/24/2013 11:04:14
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

int getLength(ListNode *head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

ListNode *find(ListNode *head, int pos) {
    ListNode *ptr = head, *prev = NULL;
    int cnt = 0;
    while (ptr) {
        cnt++;
        if (cnt == pos) {
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev) {
        prev->next = NULL;
    }
    return ptr;
}

ListNode *getTail(ListNode *head) {
    while (head->next) {
        head = head->next;
    }
    return head;
}

ListNode *rotateRight(ListNode *head, int k) {
    int len = getLength(head);
    if (len == 0) return NULL;
    k = k % len;
    if (k == 0) return head;
    ListNode *node = find(head, len - k + 1);
    ListNode *tail = getTail(node);
    tail->next = head;
    return node;
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
    printList(head);
    head = rotateRight(head, 7);
    printList(head);
    return 0;
}
