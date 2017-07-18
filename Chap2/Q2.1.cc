#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
    Node *front;
    Node *end;

public:
    LinkedList ();
    void PushBack (int inData);
    void PrintList (void);
    void DeDup (void);
};

LinkedList::LinkedList ()
{
    front = NULL;
    end = NULL;
}

void
LinkedList::PushBack (int inData)
{
    if (front == NULL)
    {
        Node *temp = new Node;
        temp->data = inData;
        temp->next = NULL;
        front = temp;
        end = temp;
    }

    else
    {
        Node *temp = new Node;
        temp->data = inData;
        temp->next = NULL;
        end->next = temp;
        end = temp;
    }

    return;
}


void
LinkedList::DeDup ()
{
    if (front == NULL){
        return;     // No operation for NULL list
    }

    Node *curr = front->next;

    while (curr != NULL)
    {
        bool isDup = 0;
        Node *ite = front;

        while (ite != curr){
            if (ite->data == curr->data)
            {
                isDup = 1;
                break;
            }

            ite = ite->next;
        }

        if (isDup)
        {
            Node *toDel = curr->next;
            curr->data = curr->next->data;
            curr->next = curr->next->next;
            delete toDel;
        }

        else
        {
            curr = curr->next;
        }
    }

    return;
}


void
LinkedList::PrintList ()
{
    Node *curr = front;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
    return;
}

int main (int argc, char *argv[])
{
    srand (time(NULL));

    LinkedList myList;

    for (int i = 0 ; i < 100 ; i++)
    {
        int temp = rand () % 10;
        myList.PushBack (temp);
    }

    cout << "The original list:" << endl;
    myList.PrintList ();

    myList.DeDup();

    cout << "The de-duped list:" << endl;
    myList.PrintList ();
}