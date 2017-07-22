#include <iostream>
#include "list_node.h"

using namespace std;

bool DeleteNode (ListNode *to_del) {
    if (to_del == NULL) {
        return false; // Invalid node
    }
    
    if (to_del->next == NULL) {
        return false; // Cannot delete the last node
    }
    
    // What if to_del is at end of list?
    else {
        to_del->data = to_del->next->data;
        to_del->next = to_del->next->next;
        delete to_del->next;
    }
    
    return true;
}

int main (int argc, char *argv[]) {
    int n;
    
    cout << "Input the length of the list: " ;
    cin >> n;
    
    ListNode *head = MakeRandomList (n, 100);
    
    cout << "The original list: " << endl;
    PrintList (head);
    
    int to_del = rand () % n;
    ListNode *to_del_node = head;
    
    for (int i = 0 ; i < to_del ; i++) {
        to_del_node = to_del_node->next;
    }
    
    cout << endl << "Going to delete node #" << to_del + 1 << endl;
    
    bool success = DeleteNode (to_del_node);
    
    if (success) {
        cout << endl << "After node is deleted:" << endl;
        PrintList (head);
    }
    
    else {
        cout << endl << "Cannot delete node!" << endl;
    }
    
    return 0;
}