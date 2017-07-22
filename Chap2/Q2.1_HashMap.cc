#include <iostream>
#include <cstdlib>
#include <unordered_set>
#include "list_node.h"

using namespace std;

void DeDup (ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return;     // No action needed
    }
    
    unordered_set<int> keys;
    keys.insert (head->data);
    
    ListNode *tail = head;
    ListNode *runner = head->next;
    
    while (runner != NULL) {
        if (keys.find (runner->data) == keys.end ()) {
            // Not a duplicate
            keys.insert (runner->data);
            tail->next->data = runner->data;
            tail = tail->next;
            runner = runner->next;
        }
        
        else {
            // A duplicate
            runner = runner->next;
        }
    }
    
    tail->next = NULL;  // Don't forget to end the line!
}


int main (int argc, char *argv[]){
    srand (time(NULL));
    
    int n, r;
    
    cout << "Number of elements in list: ";
    cin >> n;
    cout << "Range of numbers [1..r]: ";
    cin >> r;
    
    ListNode *head = MakeRandomList (n, r);
    
    cout << "The original list: ";
    PrintList (head);
    
    DeDup (head);
 
    cout << endl << "The deduped list: ";
    PrintList (head);
    
    return 0;
}