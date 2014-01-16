/*
 * =====================================================================================
 *
 *       Filename:  merge_k_lists_heap.cpp
 *
 *        Version:  1.0
 *        Created:  12/25/2013 12:18:47
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

class comp {
    public:
        bool operator() (const ListNode *l, const ListNode *r) const {
            return (l->val > r->val);
        }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    vector<ListNode *>::iterator it = lists.begin();
    while (it != lists.end()) {
        if (*it == NULL) lists.erase(it);
        else ++it;
    }
    if (lists.size() < 1) return NULL;
    if (lists.size() == 1) return lists[0];

    ListNode *head = NULL, *curr = NULL;
    make_heap(lists.begin(), lists.end(), comp());
    while (lists.size() > 0) {
        if (head == NULL) head = curr = lists[0];
        else curr = curr->next = lists[0];

        pop_heap(lists.begin(), lists.end(), comp());
        int last = lists.size() - 1;
        if (lists[last]->next != NULL) {
            lists[last] = lists[last]->next;
            push_heap(lists.begin(), lists.end(), comp());
        }
        else lists.pop_back();
    }
    return head;
}

int main() {
    ListNode *head1 = NULL;
    insert(head1, new ListNode(5));
    insert(head1, new ListNode(3));
    insert(head1, new ListNode(1));
    printList(head1);
    ListNode *head2 = NULL;
    insert(head2, new ListNode(6));
    insert(head2, new ListNode(4));
    insert(head2, new ListNode(2));
    printList(head2);
    ListNode *head3 = NULL;
    insert(head3, new ListNode(10));
    insert(head3, new ListNode(8));
    insert(head3, new ListNode(6));
    insert(head3, new ListNode(4));
    printList(head3);
    ListNode *head4 = NULL;
    printList(head4);
    vector<ListNode *> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);
    lists.push_back(head4);
    ListNode *head = mergeKLists(lists);
    printList(head);
    return 0;
}
