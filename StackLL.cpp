#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack();
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isEmpty();
    int isFull();
    int stackTop();
    int Display();
};

Stack::Stack()
{
    top = nullptr;
}

Stack::~Stack()
{
    Node *p = top;
    while (top)
    {
        top = top->next;
        delete p;
        p = top;
    }
}

void Stack::push(int x)
{
    Node *t = new Node;
    if (t == nullptr)
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    Node *p;
    int x = -1;
    if (top == nullptr)
    {
        cout << "Stack Underflow!" << endl;
    }
    else
    {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

int Stack::isFull()
{
    Node *t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}

int Stack::isEmpty()
{
    return top ? 0 : 1;
}

int Stack::stackTop()
{
    if (top)
    {
        return top->data;
    }
    return -1;
}

int Stack::peek(int index)
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        Node *p = top;

        for (int i = 0; p != nullptr && i < index - 1; i++)
        {
            p = p->next;
        }

        if (p != nullptr)
        {
            return p->data;
        }
        else
        {
            return -1;
        }
    }
}
int Stack::Display() {
    Node* p = top;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


int main() {
    Stack stack;

    int choice, value, index;

    do {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                value = stack.pop();
                if (value != -1) {
                    cout << "Popped value: " << value << endl;
                }
                break;
            case 3:
                cout << "Enter the index to peek: ";
                cin >> index;
                value = stack.peek(index);
                if (value != -1) {
                    cout << "Value at index " << index << ": " << value << endl;
                } else {
                    cout << "Invalid index or stack is empty!" << endl;
                }
                break;
            case 4:
                cout << "Stack: ";
                stack.Display();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}