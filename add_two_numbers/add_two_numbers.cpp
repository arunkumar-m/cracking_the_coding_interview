/*
 * =====================================================================================
 *
 *       Filename:  add_two_numbers.cpp
 *
 *        Version:  1.0
 *        Created:  12/20/2013 23:52:02
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

ListNode *reverse(ListNode *l) {
    if (!l) {
        return NULL;
    }
    ListNode *head = l, *p = l->next, *next;
    head->next = NULL;
    while (p) {
        next = p->next;
        p->next = head;
        head = p;
        p = next;
    }
    return head;
}

void insert(ListNode *&head, int val) {
    ListNode *ptr = new ListNode(val);
    ptr->next = head;
    head = ptr;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *result = NULL;
    int carry = 0, val;
    while (1) {
        if (l1 && l2) {
            val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1) {
            val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
        }
        else if (l2) {
            val = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
        }
        else {
            break;
        }
        insert(result, val);
    }
    if (carry == 1) {
        insert(result, 1);
    }
    return reverse(result);
}

void printList(ListNode *ptr) {
    while (ptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    ListNode *l1 = NULL;
    insert(l1, 1);
    // insert(l1, 4);
    // insert(l1, 2);
    printList(l1);
    ListNode *l2 = NULL;
    insert(l2, 9);
    insert(l2, 9);
    // insert(l2, 5);
    printList(l2);
    ListNode *l3 = addTwoNumbers(l1, l2);
    printList(l3);
    return 0;
}
