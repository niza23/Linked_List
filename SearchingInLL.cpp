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

node *search(node *p, int key)
{
    while(p)
    {
        if(key==p->data)
        {
            return(p);
        }
        p=p->next;
    }
    return NULL;
}

node *Rsearch(node *p, int key)
{
    if(p==NULL)
    {
        return NULL;
    }
    else{
        if(key==p->data)
        {
            return p;
        }
        else{
            return Rsearch(p->next,key);
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

    int a[]={3,4,5,6,6,6};
    create(a,6);
    cout<<"location of key is  "<<Rsearch(first,6);
    //display(first);
    return 0;
}