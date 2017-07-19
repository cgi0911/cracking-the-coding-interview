#include <iostream>
#include <cstdlib>
#include "list_node.h"

using namespace std;

void
DeDup (ListNode *head)
{
    if (head == NULL)
    {
        return; // No action taken for an empty list
    }

    ListNode *curr = head->next;
    ListNode *prev = head;

    while (curr != NULL)
    {
        bool isDup = false;
        ListNode *run = head;

        while (run != curr)
        {
            if (run->data == curr->data)
            {
                isDup = true;
                break;
            }

            run = run->next;
        }

        if (isDup)
        {
            ListNode *toDel = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete toDel;
        }

        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return;
}

int main (int argc, char *argv[])
{
    srand (time(NULL));

    ListNode *head = NewNode (rand () % 100);
    ListNode *tail = head;

    for (int i = 0 ; i < 1000 - 1 ; i++)
    {
        tail = Append(tail, rand () % 100);
    }

    // Print original list
    cout << "The original list: " << endl;
    PrintList (head);

    // Do dedup
    cout << endl << "Deduplicate the list..." << endl;
    DeDup (head);

    // Print deduped list
    cout << endl << "The deduped list: " << endl;
    PrintList (head);

    return 0;
}