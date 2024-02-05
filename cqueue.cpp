#include <iostream>

using namespace std;

class CircularQueue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    CircularQueue(int size);
    ~CircularQueue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};

CircularQueue::CircularQueue(int size)
{
    this->size = size;
    front = 0;
    rear = 0;
    Q = new int[size];
}

CircularQueue::~CircularQueue()
{
    delete[] Q;
}

bool CircularQueue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

bool CircularQueue::isFull()
{
    if ((rear + 1) % size == front)
    {
        return true;
    }
    return false;
}

void CircularQueue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

int CircularQueue::dequeue()
{
    int x = -1;
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

void CircularQueue::display()
{

    int i = front++;
    do
    {
        cout << Q[i] << " ";
        if (i < rear)
        {
            cout << " " ;
        }
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
}



int main()
{
    int size;

    cout << "Enter the size of the Circular Queue: ";
    cin >> size;
    size++;

    CircularQueue cq(size);

    int choice, item;

    do
    {
        cout << "\nCircular Queue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to enqueue: ";
            cin >> item;
            cq.enqueue(item);
            break;

        case 2:
            item = cq.dequeue();
            if (item != -1)
            {
                cout << "Dequeued element: " << item << endl;
            }
            break;

        case 3:
            cout << "Circular Queue elements: ";
            cq.display();
            cout << endl;
            break;

        case 4:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

/*
int A[] = {1, 3, 5, 7, 9};

CircularQueue cq(sizeof(A)/sizeof(A[0]) + 1);

// Enqueue
for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
    cq.enqueue(A[i]);
}

// Display
cq.display();
cout << endl;

// Overflow
cq.enqueue(10);

// Dequeue
for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
    cq.dequeue();
}

// Underflow
cq.dequeue();

return 0;
}
*/