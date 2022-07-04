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

void RemoveDuplicate(struct node *p)
{
    struct node *q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;        //move p to next
            q=q->next;  //q to next(skip the same element)
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}


int main()
{

    int a[]={3,4,5,5,8,8};
    create(a,6);
    RemoveDuplicate(first);
    display(first);
    return 0;
}
