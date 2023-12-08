 #include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
}* first = nullptr;




int main()
{
    int n;
    int key;

    // Ask the user for the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Declare an array of integers of size 'n'
    int A[n];

    // Input elements from the user
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    Node *head = new Node; // creation of a new node

    Node *temp;
    Node *last;

    head->data = A[0];
    head->next = nullptr;
    last = head;

    // Creation of linked list
    for (int i = 1; i < sizeof(A) / sizeof(A[0]); i++)
    {
        // Create temporary node
        temp = new Node;

        // populate temporary node
        temp->data = A[i];
        temp->next = nullptr;

        // last's next is pointing to temp
        last->next = temp;
        last = temp;
    }
    // Display Linked List
    Node *p = head;

    while (p != nullptr)
    {
        cout << p->data << " -> " << flush;
        p = p->next;
    }


    
    return 0;
}





