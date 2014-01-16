/*
 * =====================================================================================
 *
 *       Filename:  reverse_between_im.cpp
 *
 *        Version:  1.0
 *        Created:  12/20/2013 00:28:08
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

ListNode *reverseBetween(ListNode *head, int m, int n) {
    int i = 1;
    ListNode *tail1 = NULL, *head2, *tail2, *ptr = head, *next;
    while (i <= n) {
        next = ptr->next;
        if (i == m) {
            head2 = ptr;
            tail2 = ptr;
            head2->next = NULL;
        }
        else if (i > m) {
            ptr->next = head2;
            head2 = ptr;
        }
        else {
            tail1 = ptr;
        }
        i++;
        ptr = next;
    }

    tail2->next = ptr;
    if (tail1) {
        tail1->next = head2;
    }
    else {
        return head2;
    }
    return head;
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
    head = reverseBetween(head, 2, 5);
    printList(head);
    return 0;
}
