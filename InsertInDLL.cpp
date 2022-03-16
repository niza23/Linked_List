#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
    node *prev;

};

class DoublyLinkedList
{
    private:
        node *first, *prev;
    public:
    DoublyLinkedList()
    {
        first=prev=NULL;
    }
    DoublyLinkedList(int a[],int n);
    ~DoublyLinkedList();


    
    void display();
    int length();
    void insert(int a[],int index,int x);
    
    
};

DoublyLinkedList :: DoublyLinkedList(int a[], int n)
{
    
    int i=0;
    struct node *t, *last;

    first=new node;

    first->data=a[0];
    first->prev=first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t= new node;
        t->data=a[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t; 
    }
}

DoublyLinkedList :: ~DoublyLinkedList()
{
    node *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}

void DoublyLinkedList :: display()  
{
    node *p=first;  
    while(p)
    {
        cout<<"data is "<<p->data<<endl;
        p=p->next;
    }
}
int DoublyLinkedList :: length()
{
    node *p=first;
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;

}

void DoublyLinkedList :: insert(int a[],int index,int x)
{
    struct node *t;
    node *p=first;
    int i;
    if(index<0 || index>length())
    {
        return;
    }
    if(index==0)
    {
        t=new node;
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t=new node;
        t->data=x;

        t->prev=p;
        t->next=p->next;

        if(p->next)  //if next null is there
        {
            p->next->prev=t;
        }
        p->next=t;
    }
}


int main()
{
    int a[]={1,2,3,4,5};

    DoublyLinkedList l(a,5);
    l.insert(a,4,25);

    l.display();
    

    return 0;
}