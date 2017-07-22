#include <iostream>
#include <cstdlib>
#include "list_node.h"

using namespace std;

ListNode* Sum (ListNode *head1, ListNode *head2) {
    int carry = 0;
    
    ListNode *res_head = NULL;
    ListNode *res_tail = NULL;
    ListNode *runner1 = head1;
    ListNode *runner2 = head2;
    
    while (runner1 || runner2 || carry) {
        int d1 = 0;
        int d2 = 0;
        int sum;
        
        if (runner1) {
            d1 = runner1->data;
            runner1 = runner1->next;
        }
        
        if (runner2) {
            d2 = runner2->data;
            runner2 = runner2->next;
        }
        
        sum = (d1 + d2 + carry) % 10;
        carry = (d1 + d2 + carry) / 10;
        
        if (res_head == NULL) {
            res_head = NewNode (sum);
            res_tail = res_head;
        }
        else {
            res_tail = AppendToNode (res_tail, sum);
        }
    }
    
    return res_head;
}

int main (int argc, char *argv[]) {
    srand (time (NULL));
    int l1 = rand () % 10 + 1;
    int l2 = rand () % 10 + 1;
    
    ListNode *head1 = MakeRandomNumList (l1);
    cout << "Number #1: ";
    PrintList (head1);
    
    ListNode *head2 = MakeRandomNumList (l2);
    cout << "Number #2: ";
    PrintList (head2);
    
    ListNode *res_head = Sum (head1, head2);
    
    cout << "Sum of two numbers: ";
    PrintList (res_head);
    
    return 0;
}