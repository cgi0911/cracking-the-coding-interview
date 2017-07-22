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
NewNode ()
{
    ListNode *nnode = new ListNode;
    nnode->data = 0;
    nnode->next = NULL;
    return nnode;
}

ListNode*
NewNode (int inData)
{
    ListNode *nnode = new ListNode;
    nnode->data = inData;
    nnode->next = NULL;
    return nnode;
}

ListNode*
AppendToNode (ListNode *curr_node, int inData)
{
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
MakeRandomList (int n, int r) {
    // n: # of elements
    // r: range of each element [1..r]
    if (n <= 0) {
        return NULL;    // Empty list
    }
    
    srand (time (NULL));
    
    ListNode *head = NewNode (rand () % r + 1);
    ListNode *tail = head;
    
    for (int i = 0 ; i < n - 1 ; i++) {
        AppendToNode (tail, rand () % r + 1);
        tail = tail->next;
    }
    
    return head;
}

#endif //LIST_NODE_H