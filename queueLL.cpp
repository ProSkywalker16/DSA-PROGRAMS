#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    void display();
};

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

void Queue::enqueue(int x)
{
    Node *t = new Node;
    if (t == nullptr)
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        t->data = x;
        t->next = nullptr;
        if (front == nullptr)
        {
            front = t;
            rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::dequeue()
{
    int x = -1;
    Node *p;
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

bool Queue::isEmpty()
{
    if (front == nullptr)
    {
        return true;
    }
    return false;
}

Queue::~Queue()
{
    Node *p = front;
    while (front)
    {
        front = front->next;
        delete p;
        p = front;
    }
}

void Queue::display()
{
    Node *p = front;
    while (p)
    {
        cout << p->data << flush;
        p = p->next;
        if (p != nullptr)
        {
            cout << " <- " << flush;
        }
    }
    cout << endl;
}

int main() {
    Queue q;
    int option, value;

    do {
        cout << "\n\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        switch(option) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                if (!q.isEmpty()) {
                    value = q.dequeue();
                    cout << "Dequeued value is: " << value << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 3:
                if (!q.isEmpty()) {
                    q.display();
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }

    } while(option != 4);

    return 0;
}
