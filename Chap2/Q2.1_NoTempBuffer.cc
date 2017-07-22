#include <iostream>
#include <cstdlib>
#include <unordered_set>
#include "list_node.h"

using namespace std;

void DeDup (ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return;     // No action needed
    }
    
    ListNode *tail = head;
    ListNode *runner = head->next;
    ListNode *checker;
    
    while (runner != NULL) {
        checker = head;
        bool isDup = false;
        
        while (checker != tail->next) {
            if (runner->data == checker->data) {
                isDup = true;
                break;
            }
            checker = checker->next;
        }
        
        if (isDup) {
            runner = runner->next;
        }
        
        else {
            tail->next->data = runner->data;
            runner = runner->next;
            tail = tail->next;
        }
    }
    
    tail->next = NULL; // Don't forget to end the list!
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