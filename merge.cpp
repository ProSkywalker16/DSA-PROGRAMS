#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void Display(Node *p)
{
    while(p!=NULL)
    {
        cout << p->data << " ";
        p=p->next;
    }
}

void create(Node** node, int n)
{
    int i;
    Node *t,*last;
    *node = new Node;
    cout << "Enter the first element: ";
    cin >> (*node)->data;
    (*node)->next=NULL;
    last=*node;
 
    for(i=1;i<n;i++)
    {
        t=new Node;
        cout << "Enter the next element: ";
        cin >> t->data;
        t->next=NULL;
        last->next=t;
        last=t;
    }
} 

void Merge(Node *p, Node *q)
{
    Node *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p) last->next=p;
    if(q) last->next=q;
}

int main()
{
    int n1, n2;
    cout << "Enter the size of the first list: ";
    cin >> n1;
    create(&first, n1);
    
    cout << "Enter the size of the second list: ";
    cin >> n2;
    create(&second, n2);
    
    Merge(first, second); 
    Display(third); 

    return 0;
}