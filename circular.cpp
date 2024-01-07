#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{

    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void deleteAtHead(node *&head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    node *todelete = head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
}

void deletion(node *&head, int pos)
{

    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    int count = 1;

    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void display(node *head)
{

    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{

    node *head = NULL;

    int ch;
    int value, position;
    while (ch != 6)
    {
        cout << "Enter 1 for insertion at end" << endl;
        cout << "Enter 2 for insertion at beginning" << endl;
        cout << "Enter 3 for deletion at head" << endl;
        cout << "Enter 4 for deletion at position" << endl;
        cout << "Enter 5 for display" << endl;
        cout << "Enter 6 for exit" << endl;

        cout << "Enter choice:" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter value";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 2:
            cout << "Enter value";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 3:
            deleteAtHead(head);
            break;
        case 4:
            cout << "Enter position to delete:";
            cin >> position;
            deletion(head, position);
            break;
        case 5:
            display(head);
            break;

        case 6:
            return 0;

        default:
            cout << "Wrong choice" << endl;
        }
    }

    return 0;
}
