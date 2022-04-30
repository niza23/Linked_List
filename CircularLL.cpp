#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
}*head;

void create(int a[],int n)
{
    int i;
    struct node *t, *last;

    //First Node
    head=new struct node;
    head->data=a[0];
    head->next=head;

    last=head; 

    for(i=1;i<n;i++)
    {
        t= new struct node;
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }


}



void display(struct node *h)
{
    
    do{
        cout<<h->data<<endl;
        h=h->next;

    }while(h!=head);

}

void Rdisplay(struct node *h)
{
    static int flag=0;
    if(h!=head || flag==0)
    {
        flag=1;
        cout<<h->data<<endl;
        Rdisplay(h->next);

    }
    flag=0;
}

int main()
{

    
    int a[]={3,4,5,6,7,8};
    create(a,6);
    
    Rdisplay(head);
    return 0;
}
