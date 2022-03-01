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

int sum(struct node *p)
{
    int sum=0;
    while(p)
    {
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}

int Rsum(struct node *p)
{
    
    if(p==0)
    {
        return 0;
    }
    else{
        return Rsum(p->next)+p->data;
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
    cout<<"sum of elements without recursion "<<sum(first)<<endl;
    cout<<"sum of elements are "<<Rsum(first);
    //display(first);
    return 0;
}