#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <iostream>
#include <cstddef>  // For identifier NULL

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
Append (ListNode *curr_node, int inData)
{
    ListNode *nnode = NewNode (inData);
    curr_node->next = nnode;
    return nnode;
}

void
PrintList (ListNode *head)
{
    ListNode *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " " ;
        curr = curr->next;
    }

    cout << endl;
}

#endif //LIST_NODE_H