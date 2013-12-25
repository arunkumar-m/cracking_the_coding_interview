/*
 * =====================================================================================
 *
 *       Filename:  merge_k_list.cpp
 *
 *        Version:  1.0
 *        Created:  12/25/2013 10:58:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
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

void insert(ListNode *&list, ListNode *node) {
    node->next = list;
    list = node;
}

void remove(vector<ListNode *> &lists, int index) {
    if (lists[index] == NULL) {
        lists.erase(lists.begin() + index);
    }
    else {
        lists[index] = (lists[index])->next;
        if (lists[index] == NULL) {
            lists.erase(lists.begin() + index);
        }
    }
}

void reverse(ListNode *&list) {
    if (!list) return;
    ListNode *ptr = list->next, *next = NULL;
    if (!ptr) return;
    ListNode *head = list, *tail = list;
    head->next = NULL;
    while (ptr) {
        next = ptr->next;
        ptr->next = head;
        head = ptr;
        ptr = next;
    }
    list = head;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *head = NULL;
    while (lists.size() != 0) {
        int min_so_far = INT_MAX;
        ListNode *node = NULL;
        int index = 0;
        for (int i = 0; i < lists.size(); i++) {
            ListNode *p = lists[i];
            if (p) {
                if (p->val < min_so_far) {
                    index = i;
                    node = p;
                    min_so_far = p->val;
                }
            }
            else {
                remove(lists, i);
                i--;
            }
        }
        if (node) {
            remove(lists, index);
            insert(head, node);
        }
    }
    reverse(head);
    return head;
}

int main() {
    ListNode *head1 = NULL;
    insert(head1, new ListNode(2));
//    insert(head1, new ListNode(3));
//    insert(head1, new ListNode(1));
//    printList(head1);
    ListNode *head2 = NULL;
//    insert(head2, new ListNode(6));
//    insert(head2, new ListNode(4));
//    insert(head2, new ListNode(2));
//    printList(head2);
    ListNode *head3 = NULL;
    insert(head3, new ListNode(-1));
//    insert(head3, new ListNode(8));
//    insert(head3, new ListNode(6));
//    insert(head3, new ListNode(4));
//    printList(head3);
//    ListNode *head4 = NULL;
//    printList(head4);
    vector<ListNode *> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);
//    lists.push_back(head4);
    ListNode *head = mergeKLists(lists);
    printList(head);
    // printList(lists[0]);
    // printList(lists[1]);
    return 0;
}
