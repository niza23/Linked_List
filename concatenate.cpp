#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
}*first=NULL, *second=NULL, *third=NULL;

void create1(int a[],int n)
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

void create2(int a[],int n)
{
    int i;
    struct node *t, *last;
    second=new node;

    second->data=a[0];
    second->next=NULL;
    last=second;

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
    while(p!=NULL)
    {
        cout<<"data is "<<p->data<<endl;
        p=p->next;
    }
}

void concatenate(struct node *p, struct node*q)
{
    third=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
}


int main()
{

    int a[]={3,4,5,6,7,8};
    int b[]={9,10,11,12,13,14};
    create1(a,6);
    create2(b,6);
    display(first);
    cout<<endl;
    display(second);
    cout<<endl;
    concatenate(first,second);
    display(third);
    return 0;
}
