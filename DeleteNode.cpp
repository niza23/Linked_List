#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
}*first=NULL;

void create(int a[],int n)
{
    int i;
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

void display(struct node *p)
{
    while(p)
    {
        cout<<"data is "<<p->data<<endl;
        p=p->next;
    }
}

int count(struct node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}

int del(struct node *p, int index)
{
    struct node *q;
    int x=-1;

    if(index<1 || index>count(p))
    {
        return 0;
    }
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        delete q;
        return x;

    }
    else{
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        return x;
    }
}

int main()
{

    int a[]={3,4,5,6,7,8};
    create(a,6);
    cout<<"deleted item is "<<del(first,3)<<endl;
    display(first);
    return 0;
}