#include <iostream>

// Define a Node structure for the circular singly linked list
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            newNode->next = newNode; // Circular reference to itself
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            newNode->next = head;
            current->next = newNode;
            head = newNode;
        }
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            newNode->next = newNode; // Circular reference to itself
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            newNode->next = head;
            current->next = newNode;
        }
    }

    // Function to insert a new node at a specific position in the list
    void insertAtPosition(int val, int position)
    {
        if (position < 0)
        {
            std::cout << "Invalid position. Position should be non-negative." << std::endl;
            return;
        }
        Node *newNode = new Node(val);
        if (position == 0)
        {
            if (head == nullptr)
            {
                newNode->next = newNode; // Circular reference to itself
                head = newNode;
            }
            else
            {
                Node *current = head;
                while (current->next != head)
                {
                    current = current->next;
                }
                newNode->next = head;
                current->next = newNode;
                head = newNode;
            }
            return;
        }
        Node *current = head;
        int currentPosition = 0;
        while (current->next != head && currentPosition < position - 1)
        {
            current = current->next;
            currentPosition++;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to display the circular linked list
    void display()
    {
        if (head == nullptr)
        {
            std::cout << "Circular Linked List is empty." << std::endl;
            return;
        }
        Node *current = head;
        do
        {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
};

int main()
{
    CircularLinkedList myList;

    int choice;
    int value;
    int position;

    while (true)
    {
        std::cout << "Choose an operation:" << std::endl;
        std::cout << "1. Insert at the beginning" << std::endl;
        std::cout << "2. Insert at the end" << std::endl;
        std::cout << "3. Insert at a specific position" << std::endl;
        std::cout << "4. Display the list" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter the value to insert at the beginning: ";
            std::cin >> value;
            myList.insertAtBeginning(value);
            break;
        case 2:
            std::cout << "Enter the value to insert at the end: ";
            std::cin >> value;
            myList.insertAtEnd(value);
            break;
        case 3:
            std::cout << "Enter the value to insert: ";
            std::cin >> value;
            std::cout << "Enter the position to insert (0-indexed): ";
            std::cin >> position;
            myList.insertAtPosition(value, position);
            break;
        case 4:
            std::cout << "Circular Linked List: ";
            myList.display();
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}
