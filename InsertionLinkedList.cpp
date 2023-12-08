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



void Insert(Node *p, int index, int x)
{
    Node *t;
    int i;

    t = new Node;
    t->data = x;

    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(i = 0; i < index-1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
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

    int index, x;
    cout << "Enter the index and element to insert: ";
    cin >> index >> x;
    if(index>n || index<0)
    {
        cout<<"Out of bounds"<<endl;
    }
    else
    {

    Insert(first, index, x);
    Display(first);

    delete [] A;
    }
    return 0;
}
