#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

};

class LinkedList
{
    private:
        node *first;
    public:
    LinkedList()
    {
        first=NULL;
    }
    LinkedList(int a[],int n);
    ~LinkedList();


    void display();
    void insert(int pos,int x);
    int del(int index);
    int count();
};

LinkedList :: LinkedList(int a[], int n)
{
    
    int i=0;
    struct node *t, *last;
    first=new node;

    first->data=a[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t= new node;
        t->data=a[i];
        t->next=NULL;

        last->next=t;
        last=t; 
    }
}

LinkedList :: ~LinkedList()
{
    node *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}

void LinkedList :: display()   // no need of parameter in c++
{
    node *p=first;   //local pointer to first
    while(p)
    {
        cout<<"data is "<<p->data<<endl;
        p=p->next;
    }
}

int LinkedList :: count()
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

void LinkedList :: insert(int pos,int x)
{
    node *t, *p=first;
    if(pos<0 || pos > count())
    {
        cout<<"invalid "<<endl;
        return;
    }
    t=new node;
    t->data=x;

    if(pos==0)
    {
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;

    }

}

int LinkedList :: del(int index)
{
    struct node *q=NULL, *p;
    int x=-1;

    if(index<1 || index>count())
    {
        return 0;
    }
    if(index==1)
    {
        p=first;
        x=first->data;
        first=first->next;
        delete p;

    }
    else{
        p=first;
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        
    }
    return x;
}

int main()
{
    int a[]={1,2,3,4,5};

    LinkedList l(a,5);

    l.display();
    cout<<endl;
    l.insert(3,6);
    l.display();
    cout<<endl;
    cout<<l.del(3);
    l.display();

    return 0;
}
