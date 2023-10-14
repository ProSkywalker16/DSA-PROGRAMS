#include <iostream>

// Define a Node structure for the singly linked list
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
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
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *current = head;
        int currentPosition = 0;
        while (current != nullptr && currentPosition < position - 1)
        {
            current = current->next;
            currentPosition++;
        }
        if (current == nullptr)
        {
            std::cout << "Invalid position. Position exceeds the length of the list." << std::endl;
            delete newNode;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to display the linked list
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    LinkedList myList;

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
            std::cout << "Linked List: ";
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
