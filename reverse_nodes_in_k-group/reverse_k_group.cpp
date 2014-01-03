/*
 * =====================================================================================
 *
 *       Filename:  reverse_k_group.cpp
 *
 *        Version:  1.0
 *        Created:  01/03/2014 13:48:32
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

void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int getLength(ListNode *head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

ListNode *reverseFirstKNode(ListNode *&head, int k) {
    ListNode *rhead = NULL, *curr = head, *next;
    if (!head) {
        return NULL;
    }
    else if (!head->next) {
        rhead = head;
        head = NULL;
        return rhead;
    }
    int cnt = 0;
    while (cnt < k && curr) {
        next = curr->next;

        curr->next = rhead;
        rhead = curr;

        curr = next;
        head = next;
        cnt++;
    }
    return rhead;
}

ListNode *getTail(ListNode* head) {
    if (!head) return NULL;
    while (head->next) {
        head = head->next;
    }
    return head;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *curr, *tail;
    ListNode *retHead = NULL, *retTail = NULL;
    int len = getLength(head);
    if (len == 0) return NULL;
    if (len < k) return head;
    for (int i = 0; i < len / k; i++) {
        curr = reverseFirstKNode(head, k);
        // printList(curr);
        // printList(head);
        if (!retHead) {
            retHead = curr;
            retTail = getTail(curr);
        }
        else {
            retTail->next = curr;
            retTail = getTail(curr);
        }
    }
    if (len % k != 0) retTail->next = head;
    return retHead;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    // printList(reverseKGroup(head, 1));
    // printList(reverseKGroup(head, 2));
    printList(reverseKGroup(head, 4));
    // printList(reverseKGroup(head, 4));
    // printList(reverseKGroup(head, 5));
    return 0;
}
