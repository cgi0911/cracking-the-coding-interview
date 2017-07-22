#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <iostream>
#include <cstddef>  // For identifier NULL
#include <cstdlib>

using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode*
NewNode (int inData = 0)
{
    ListNode *nnode = new ListNode;
    nnode->data = inData;
    nnode->next = NULL;
    return nnode;
}

ListNode*
AppendToNode (ListNode *curr_node, ListNode *to_append) {
    if (curr_node == NULL) {
        curr_node = to_append;
        return curr_node;
    }

    curr_node->next = to_append;
    return to_append;
}

ListNode*
AppendToNode (ListNode *curr_node, int inData)
{
    if (curr_node == NULL) {
        curr_node = NewNode (inData);
        return curr_node;
    }
    
    ListNode *nnode = NewNode (inData);
    curr_node->next = nnode;
    return nnode;
}

void
PrintList (ListNode *head)
{
    ListNode *curr = head;
    
    if (curr == NULL) {
        cout << "Empty list!" << endl;
        return;
    }
    
    while (curr != NULL)
    {
        cout << curr->data << " " ;
        curr = curr->next;
    }

    cout << endl;
    
    return;
}

ListNode*
MakeRandomList (int n, int r = 0) {
    // n: # of elements
    // r: range of each element [0..r-1]
    
    if (n <= 0) {
        return NULL;    // Empty list
    }
    
    ListNode *head = NewNode (rand () % r);
    ListNode *tail = head;
    
    for (int i = 0 ; i < n - 1 ; i++) {
        tail = AppendToNode (tail, rand () % r);
    }
    
    return head;
}

ListNode*
MakeRandomNumList (int n) {
    if (n <= 0) {
        return NULL;
    }

    if (n == 1) {
        ListNode *head = NewNode (rand () % 9 + 1);
        return head;
    }
    
    else {
        ListNode *head = NewNode (rand () % 10);
        ListNode *tail = head;
        
        for (int i = 0 ; i < n - 2 ; i++) {
            tail = AppendToNode (tail, rand () % 10);
        }
        
        tail = AppendToNode (tail, rand () % 9 + 1);
        
        return head;
    }

}

#endif //LIST_NODE_H