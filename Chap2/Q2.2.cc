#include <iostream>
#include <cstdlib>
#include "list_node.h"

ListNode* FindKthFromLast (ListNode *head, int k)
{
    if (head == NULL || k < 1)
    {
        return NULL;    // Operation not defined
    }

    ListNode *ptr1 = head;
    ListNode *ptr2 = head;

    // First, move ptr2 forward by k-1 steps
    for (int i = 0 ; i < k - 1 ; i++) {
        if (ptr2 == NULL) {
            return NULL;    // List not long enough
        }
        ptr2 = ptr2->next;
    }
    
    // ptr1 and ptr2 move together
    while (ptr2->next != NULL) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return ptr1;
}


int main (int argc, char *argv[])
{
    srand (time(NULL));
    
    int n, r, k;
    
    cout << "Number of elements in list: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Invalid list length!" << endl;
        return 1;
    }
    
    cout << "Find kth from last: ";
    cin >> k;
    
    r = 100;
    
    ListNode *head = MakeRandomList (n, r);
    
    cout << "The original list: ";
    PrintList (head);

    // Start looking for n-th from last
    ListNode *kthFromLast = FindKthFromLast (head, k);

    if (kthFromLast) {
        cout << k << "th from last = " << kthFromLast->data << endl;
    }    
    else {
        cout << "No valid result!" << endl;
    }
}