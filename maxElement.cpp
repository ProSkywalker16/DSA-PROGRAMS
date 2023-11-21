#include <iostream>
#include <limits> // for INT_MIN
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} * first = nullptr;

void create(int A[], int n)
{
    int i;
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

int Max(Node *p)
{
    int max = INT32_MIN;

    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int main()
{
    int n;

    // Ask the user for the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Declare an array of integers of size 'n'
    int *A = new int[n];

    // Input elements from the user
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    create(A, n);

    // Display Linked List
    Node *p = first;

    while (p != nullptr)
    {
        cout << p->data << " -> ";
        p = p->next;
    }

    cout << "\nMax is: " << Max(first) << endl;

    // Clean up dynamic memory
    delete[] A;

    return 0;
}
