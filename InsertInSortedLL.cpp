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

void Sortedinsert(struct node *p,int x)
{
    struct node *t, *q=NULL;  //q is following pointer to p

    t= new node;

    t->data=x;
    t->next=NULL;

    if(first==NULL)  //if first is empty
    {
        first=t;
    }
    else{
        while(p && p->data<x)  
        {
            q=p;
            p=p->next;
        }
        if(p==first){   //add befor first node
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
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

int main()
{

    int a[]={3,4,5,10};
    create(a,4);
    Sortedinsert(first,0);
    display(first);
    return 0;
}
