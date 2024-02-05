#include <iostream>
#include <stdio.h>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;

        Q = new Node *[size];
    }
    void enqueue(Node *x);
    Node *dequeue();
    int isEmpty()
    {
        return front == rear;
    }
};

void Queue::enqueue(Node *x)
{
    if (rear == size - 1)
        cout<<"Queue Full!"<<endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    Node *x = NULL;
    if (front == rear)
        cout<<"Queue is Empty"<<endl;
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

class Tree
{
    Node *root;

public:
    Tree() { root = NULL; }
    void CreateTree();
    void Preorder() { Preorder(root); }
    void Preorder(Node *p);
    void Postorder() { Postorder(root); }
    void Postorder(Node *p);
    void Inorder() { Inorder(root); }
    void Inorder(Node *p);
    void Levelorder() { Levelorder(root); }
    void Levelorder(Node *p);
    int Height() { return Height(root); }
    int Height(Node *root);
};

void Tree::CreateTree()
{
    Node *p, *t = NULL;
    int x;
    Queue q(100);
    cout<<"enter root value:";
    //printf("Enter root value ");
    cin >> x;
    //scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        //printf("Enter left child of %d (or -1 for no left child): ", p->data);
        cout<<"Enter left child of "<<p->data<<"(or -1  for no left child):";
        cin>>x;
        //scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout<<"Enter the right child of "<<p->data<<"(or -1 if no left child):";
        //printf("Enter right child of %d (or -1 for no right child): ", p->data);

         cin>>x; 
        //scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(struct Node *p)
{
    if (p)
    {
        cout<<p->data;
        //printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout<<p->data;
        //printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void Tree::Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data;
        //printf("%d ", p->data);
    }
}

void Tree::Levelorder(struct Node *p)
{
    Queue q(100);
    
    //printf("%d ", root->data);
    q.enqueue(root);
    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            cout<<root->lchild->data;
            //printf("%d ", root->lchild->data);
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {   cout<<root->rchild->data;
            //printf("%d ", root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
}

int Tree::Height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int main()
{
    Tree tree;
    int choice;

    do
    {
        cout << "\n\nBinary Tree Operations:\n";
        cout << "1. Create Tree\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Levelorder Traversal\n";
        cout << "6. Height of the Tree\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tree.CreateTree();
            break;
        case 2:
            cout << "Preorder Traversal: ";
            tree.Preorder();
            break;
        case 3:
            cout << "Inorder Traversal: ";
            tree.Inorder();
            break;
        case 4:
            cout << "Postorder Traversal: ";
            tree.Postorder();
            break;
        case 5:
            cout << "Levelorder Traversal: ";
            tree.Levelorder();
            break;
        case 6:
            cout << "Height of the Tree: " << tree.Height();
            break;
        case 7:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.";
        }
    } while (choice != 7);

    return 0;
}
