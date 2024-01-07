#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* first=NULL;

void create(int n)
{
    Node *t, *last;
    first=new Node;
    cout<<"Enter data for node 1:";
    cin>>first->data;
    first->next=NULL;
    last=first;

    for(int i=1; i<n; i++)
    {
        t=new Node;
        cout<<"Enter data for node:"<<i+1<<":";
        cin>>t->data;
        t->next=NULL;
        last->next=t;
        last=t;
   }
}

void display(Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void reverse()
{
    int count=0;
    Node *p=first;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    int *A=new int[count];
    p=first;
    int i=0;
    while(p!=NULL)
    {
        A[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;
    i--;
    while(p!=NULL)
    {
        p->data=A[i];
        p=p->next;
        i--;
    }
    
}

int main()
{
    int n;
    cout<<"Enter no of nodes:";
    cin>>n;
    create(n);
    cout<<"Original list:";
    display(first);
    reverse();
    cout<<"Reversed list:";
    display(first);
    return 0;
}
