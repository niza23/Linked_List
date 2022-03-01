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

int m(struct node *p)
{
    int m=INT_MAX;
    while(p){
        if(p->data < m)
        {
            m=p->data;
        }
        p=p->next;
    }
    return m;
}
int Rm(struct node *p)   //using recursion
{
    int x;
    if(p==0)
    {
        return INT_MAX;
    }
    else{
        x=Rm(p->next);
        if(x>p->data)
        {
            return p->data;
        }
        else{
            return x;
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

    int a[]={3,4,5,6,7,9};
    create(a,6);
    cout<<"minimum element is "<<Rm(first);
    //display(first);
    return 0;
}