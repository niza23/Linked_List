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
node *search(node *p, int key)  //Move to forward
{
    node *q=NULL;
    while(p)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;

        }
        q=p;
        p=p->next;
    }
    return NULL;
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
    struct node*temp;
    int a[]={3,4,5,6,8,11};
    create(a,6);

    temp=search(first,5);
    temp=search(first,6);

    if(temp)
    {
        cout<<"key is found "<<temp->data<<endl;
    }
    else
    {
        cout<<"key not found "<<endl;
    }
   
    display(first);
    return 0;
}