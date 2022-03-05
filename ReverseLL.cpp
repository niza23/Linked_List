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

void display(struct node *p)
{
    while(p)
    {
        cout<<"data is "<<p->data<<endl;
        p=p->next;
    }
}

void reverse1(struct node *p)
{
    int i=0;
    struct node*q=p;

    int *b;
    b=new int[count(p)];

    while(q)   //copy inside an array
    {
        b[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;

    while(q)  //copy in LL from an array
    {
        q->data=b[i];
        q=q->next;
        i--;
    }


}
void reverse2(struct node*p)
{
    struct node *q=NULL,*r=NULL;

    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void Rreverse(struct node* p, struct node *q)  //recursion
{
    if(p)
    {
        Rreverse(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}

int main()
{

    int a[]={3,4,5,6,8,89};
    create(a,6);
    reverse2(first);
    display(first);
    return 0;
}