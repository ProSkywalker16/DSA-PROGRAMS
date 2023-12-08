#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

//Creation of the Linked List
Node* createLinkedList(int A[], int n)
{
    Node *head = new Node;
    Node *last, *temp;

    head->data = A[0];
    head->next = nullptr;
    last = head;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
    return head;
}

//The linear search of the linked list
Node* LSearch(Node *p, int key)
{
    while(p != nullptr) 
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return nullptr;
}

int main()
{
    int n;
    int key;

    cout << "Enter the size of the array: ";
    cin >> n;

    int A[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    Node *first = createLinkedList(A, n);

    Node *p = first;
    while (p != nullptr)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "end" << endl;

    cout << "Enter value to be searched: ";
    cin >> key;
    Node *temp = LSearch(first, key);
    if(temp)
        cout << "key Found " << key<< endl;
    else
        cout << "Key not found" << endl;

    return 0;
}