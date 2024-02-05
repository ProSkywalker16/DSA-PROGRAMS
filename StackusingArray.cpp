#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

struct Stack {
    int arr[MAX_SIZE];
    int top;

    Stack() {
        top = -1; // Initialize top to -1 indicating an empty stack
    }

    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push element.\n";
        } else {
            top++;
            arr[top] = value;
            cout << "Element " << value << " pushed onto the stack.\n";
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop element.\n";
        } else {
            cout << "Element " << arr[top] << " popped from the stack.\n";
            top--;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\n----- Stack Menu -----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}