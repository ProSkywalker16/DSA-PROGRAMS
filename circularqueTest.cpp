
/*
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, maxSize;
    int *arr;

public:
    CircularQueue(int size) {
        maxSize = size;
        arr = new int[maxSize];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % maxSize == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSize;
        }

        arr[rear] = value;
        cout << value << " enqueued to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << arr[front] << " dequeued from the queue." << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Elements in the queue: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % maxSize;
        } while (i != (rear + 1) % maxSize);
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the circular queue: ";
    cin >> size;

    CircularQueue cq(size);

    int choice, value;
    do {
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;

            case 2:
                cq.dequeue();
                break;

            case 3:
                cq.display();
                break;

            case 4:
                cout << "Exiting the program\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
*/


#include <iostream>
using namespace std;
#define size 100
class cqueue
{
    int q[size];
    int front,rear;
    public://important or queue will not accept top
    cqueue()
    {
         front=rear=-1;
    }
   void insert(int item)
   {
       if(front==0 &&rear==size-1||front==rear+1)
       { 
        cout<<"Queue overflows\n"; 
        return;
        }//give return for all
        else if(front==-1)
       { front=0;
       rear=0;}

       else if(rear==size-1)
       rear=0;
       else
       {
           q[rear++]=item;
           cout<<"Item Inserted\n";
       }
   }
   void Delete()
   {
       if(front==-1)
       {cout<<"Queue Underflows\n";
       return;
       }
       else if(front==rear)
       {
        front=-1,rear=-1;
        }
       else if(front==size-1)
       front=0;
       else
       {
           int item=q[front++];
           cout<<"Item deleted:"<<item<<endl;
       }
   }
   void Display()
   {
       if(front==-1)
        cout<<"Queue is empty\n";
       else
       {
           cout<<"Queue elements are: \n";
           if(front<=rear)
           {
               for(int i=front;i<=rear;i++)
                cout<<q[i]<<endl;
           }
           else
           {
               for(int i=front;i<=size-1;i++)
                cout<<q[i]<<endl;
                front=0;
                for(int i=front;i<=rear;i++)
                cout<<q[i]<<endl;
           }    
       }
   }
};
int main()
{
    cqueue q;
    int ch,item;
    do
    {   
    cout<<"Enter 1 for insertion\n";
    cout<<"Enter 2 for deletion\n";
    cout<<"Enter 3 for display\n";
    cout<<"Enter 4 for exit\n";
    cout<<"Enter your choice\n";
    cin>>ch;
    switch(ch)
    {
        case 1: cout<<"Enter number to insert\n";
                cin>>item;
                q.insert(item);
                break;
        case 2: q.Delete();
                break;
        case 3:q.Display();
                break;
        case 4:cout<<"Exiting\n";
                break;
        default:cout<<"Wrong choice";
    }
    }while(ch!=4);
    return 0;
   }



