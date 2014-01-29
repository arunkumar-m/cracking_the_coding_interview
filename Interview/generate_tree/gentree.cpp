/*
 * =====================================================================================
 *
 *       Filename:  gentree.cpp
 *
 *        Version:  1.0
 *        Created:  01/28/2014 16:59:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

class dataholder{
public void* data;
public const int depth;
}

(1,A)
(2,B)
(2,C)
(3,D)
(2,E)
(4,F)

     A
    /\  \
    B  C E
       |
       D
       |
       F

struct ListNode {
    dataholder val;
    ListNode *next;
    ListNode (dataholder v) : val(v), next(NULL) {}
};

struct TreeNode {
    TreeNode *next;
    ListNode *head;
    ListNode *tail;
    dataholder val;
    TreeNode(void *data) : head(NULL), tail(NULL), val(data) {}
};

map<int, TreeNode *> m;

void insert(TreeNode *head, dataholder val) {
    if (!head->head) {
        head->head = new ListNode(val);
        head->tail = head->head;
        return;
    }
    ListNode *ptr = head->tail;
    ptr->next = new ListNode(val);
    head->tail = ptr->next;
}

m[1] = TreeNode(1);
2, B
m[2] = TreeNode(2);
TreeNode(1): list 2 B->NULL
2, C
TreeNode(1): list (2 B)->(2 C)->NULL

next: TreeNode(2 B) -> TreeNode(2 C) -> NULL

3, D
m[3] = TreeNode(3, D)
TreeNode(2, C): list (3, D) -> NULL

2, E

TreeNode* genTree(ListNode *head) {
    while (head) {
        if (m.find(head->val.depth) == m.end()) {
            m[head->val.depth] = new TreeNode(head->val.depth);
            if (m.find(head->val.depth - 1) != m.end()) {
                map<int, TreeNode *>::it = m.find(head->val->data);
                insert(it->second, head);
            }
            else if (head->val.depth != 1) {
                return NULL;
            }
        }
        else {
            // add a treenode into the map
            map<int, TreeNode *>::it = m.find(head->val.depth);
            TreeNode *curr = it->second;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = new TreeNode(head->val->data);
            
            if (m.find(head->val.depth - 1) != m.end()) {
                map<int, TreeNode *> ::it = m.find(head->val.depth - 1);
                insert(it->second, head->val->data);
            }
            else {
                return NULL;
            }
        }
        prev = head;
        head = head->next;
    }
    map<int, TreeNode *>::it = m.find(1);
    return it->second;
}
