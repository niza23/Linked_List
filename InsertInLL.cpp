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
int count(struct node *p)   //length of LL
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}

void insert(struct node *p, int pos, int x)
{
    struct node *t;
    if(pos<0 || pos > count(p))
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

void display(struct node *p)
{
    while(p)
    {
        cout<<"data is "<<p->data<<endl;
        p=p->next;
    }
}

int main()
{

    int a[]={3,4,5};
    create(a,3);
    insert(first,0,100);
    insert(first,2,10);
    insert(first,5,100);
    display(first);
    return 0;
}
