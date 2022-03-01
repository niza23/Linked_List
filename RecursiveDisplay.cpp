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

void Rdisplay(struct node *p)
{
    if(p!=NULL)
    {
        cout<<"data is "<<p->data<<endl;
        Rdisplay(p->next);
    }
}

void RRdisplay(struct node *p)
{
    if(p!=NULL)
    {
        RRdisplay(p->next);
        cout<<"data is "<<p->data<<endl;
        
    }
}

int main()
{

    int a[]={3,4,5,6,6,6};
    create(a,6);
    Rdisplay(first);
    cout<<"Reverse "<<endl;
    RRdisplay(first);
    return 0;
}