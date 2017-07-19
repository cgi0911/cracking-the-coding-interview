#include <iostream>
#include <cstdlib>
#include "list_node.h"

ListNode* FindNthFromLast (ListNode *head, int n)
{
    if (head == NULL || n < 1)
    {
        return NULL;    // Cannot operate
    }

    ListNode *ptr1 = head;
    ListNode *ptr2 = head;

    // Move ptr2 n-1 steps forward
    for (int i = 0 ; i < n - 1 ; i++)
    {
        if (ptr2 == NULL)
        {
            return NULL; // Less than n elements long
        }
        ptr2 = ptr2->next;
    }

    // Now move together
    while (ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1;
}


int main (int argc, char *argv[])
{
    srand (time(NULL));

    ListNode *head = NewNode (rand () % 100);
    ListNode *tail = head;

    for (int i = 0 ; i < 8 - 1 ; i++)
    {
        tail = Append (tail, rand () % 100);
    }

    // Print the list
    PrintList (head);

    // Start looking for n-th from last
    ListNode *nthFromLast = FindNthFromLast (head, 10);

    cout << "10th from last = " << nthFromLast->data << endl;
}