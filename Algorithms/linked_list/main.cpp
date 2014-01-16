/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *        Version:  1.0
 *        Created:  12/06/2013 22:54:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include "list.h"
using namespace std;

int main() {
    ListNode *head = NULL;
    int i, count = 10;
    for (i = 0; i < count; i++) {
        insertNode(&head, 3 * i - 1);
    }
    printList(head);
    for (i = 0; i < count; i++) {
        deleteNode(&head, 2 * i - 1);
    }
    printList(head);
    return 0;
}
