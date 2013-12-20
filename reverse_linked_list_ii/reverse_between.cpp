/*
 * =====================================================================================
 *
 *       Filename:  reverse_between.cpp
 *
 *        Version:  1.0
 *        Created:  12/19/2013 23:49:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {

    // no need to reverse
    if (m == n) {
        return head;
    }

    stack<ListNode *> st;
    int i = 1;
    ListNode *ptr = head;
    ListNode *prev = NULL;

    while (i < m) {
        i++;
        prev = ptr;
        ptr = ptr->next;
    }

    while (i <= n) {
        st.push(ptr);
        i++;
        ptr = ptr->next;
    }

    ListNode *curr = st.top();
    ListNode *head2 = curr;
    st.pop();
    while (!st.empty()) {
        ListNode *next = st.top();
        st.pop();
        curr->next = next;
        curr = next;
    }

    // connect three parts into one
    curr->next = ptr;
    if (prev) {
        prev->next = head2;
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
    head = reverseBetween(head, 1, 5);
    printList(head);
    return 0;
}
