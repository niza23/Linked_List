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

int isSorted(struct node *p)
{
    int x=INT_MIN;
    while(p)
    {
        if(p->data<x)
        {
            return 0;
        }
        else{
            x=p->data;
            p=p->next;
        }
    }
    return 1;
}

int main()
{

    int a[]={3,4,5,6,7,8};
    create(a,6);
    if(isSorted(first))
    {
        cout<<"it is sorted";
    }
    else{
        cout<<"it is not sorted";
    }
    //display(first);
    return 0;
}