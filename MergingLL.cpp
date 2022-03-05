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

void Merge(struct node *p,struct node *q)
{
    struct node *last;
    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;

    }

    while(p && q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;

        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }

    if(p)
    {
        last->next=p;
    }
    if(q)
    {
        last->next=q;
    }
    
}



int main()
{

    int a[]={3,4,45};
    int b[]={9,12,23};
    create1(a,3);
    create2(b,3);
    display(first);
    cout<<endl;
    display(second);
    cout<<endl;

    Merge(first,second);
    display(third);
    
    return 0;
}