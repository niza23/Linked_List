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
    while(p!=NULL)
    {
        cout<<"data is "<<p->data<<endl;
        p=p->next;
    }
}

int isloop(struct node *f)
{
    struct node*p,*q;
    p=q=f;

    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);

    if(p==q)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    struct node *t1,*t2;

    int a[]={3,4,5,6,7};
    create(a,5);

    t1=first->next->next;  //at 5
    t2=first->next->next->next->next; //at 7
    t2->next=t1;   //7 is pointing to 5


    if(isloop(first))
    {
        cout<<"it has a loop";
    }
    else{
        cout<<"no loop";
    }
    return 0;
}
