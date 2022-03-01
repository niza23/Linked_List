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

int Rcount(struct node *p)
{
    if(p==0)
    {
        return 0;
    }
    else{
        return Rcount(p->next)+1;
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

    int a[]={3,4,5,6,6,6};
    create(a,6);

    cout<<"number of nodes are "<<Rcount(first)<<endl;
    //display(first);
    return 0;
}