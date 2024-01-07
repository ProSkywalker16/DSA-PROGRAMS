#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*first = nullptr;



void create(int A[], int n)
{
    int i;
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for(i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void SortedInsert(Node *p, int x)
{
    Node *t, *q = nullptr;
    t = new Node;
    t->data = x;
    t->next = nullptr;

    if(first == nullptr)
        first = t;
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

void Display(Node *p)
{
    while(p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *A = new int[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    create(A, n);

    int x;
    cout << "Enter the element to insert: ";
    cin >> x;

    SortedInsert(first, x);
    Display(first);

    delete [] A;
    return 0;
}