#include<iostream>
using namespace std;
 
class node {
public:
    int data;
    node* next;
    node* prev;
    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
 
void insertAtHead(node* &head, int val) {
 
    node* n = new node(val);
    n->next = head;
    if (head != NULL) {
        head->prev = n;
    }
 
    head = n;
}
 
void insertAtTail(node* &head, int val) {
 
    if (head == NULL) {
        insertAtHead(head, val);
        return;
    }
 
    node* n = new node(val);
    node* temp = head;
 
    while (temp->next != NULL) {
        temp = temp->next;
    }
 
    temp->next = n;
    n->prev = temp;
 
}
 

 
void deleteAtHead(node* &head) {
 
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
 
    delete todelete;
}
 
void deletion(node* &head, int pos) {
 
    if (pos == 1) {
        deleteAtHead(head);
        return;
    }
 
    node* temp = head;
    int count = 1;
 
    while (temp != NULL && count != pos) {
        temp = temp->next;
        count++;
    }
 
    temp->prev->next = temp->next;
 
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
 
 
    delete temp;
 
}
void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
 
int main() {
    /*
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    insertAtHead(head, 5);
    display(head);
    deletion(head, 1);
    display(head);
    */
    node* head = NULL;
    int value, ch, position;
    while(ch!=6)
    {
        cout << "Enter 1 for insertion at end" << endl;
        cout << "Enter 2 for insertion at beginning" << endl;
        cout << "Enter 3 for deletion at head" << endl;
        cout << "Enter 4 for deletion at position" << endl;
        cout << "Enter 5 for display" << endl;
        cout << "Enter 6 for exit" << endl;

        cout << "Enter choice:" << endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter value:";
                cin>>value;
                insertAtHead(head, value);
                break;
            case 2:
                cout<<"Enter value:";
                cin>>value;
                insertAtTail(head, value);
                break;
            case 3:
                deleteAtHead(head);
                break;
            case 4:
                cout<<"Enter position:";
                cin>>position;
                deletion(head, position);
                break;
            case 5:
                display(head);
                break;
            case 6:
                return 0;
            default:
                cout<<"Wrong choice"<<endl;
                

        }
    }
 
    return 0;
}