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

    //first node
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

int length(struct node *p)
{
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=head);

    return len;
}

void insert(struct node *p,int index,int x)
{
    struct node *t;
    int i;
    if(index<0 || index>length(head))   //check the index
    {
        return;
    }

    if(index==0)   //first position
    {
        t= new  node;
        t->data=x;
        if(head==NULL)   //if there is no element
        {
            head=t;
            head->next=head;
        }
        else{
            while(p->next!=head)
            {
                p->next=t;
                t->next=head;
                head=t;
            }
        }
    }
    else{
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }

        t= new  node;
        t->data=x;
        t->next=p->next;
        p->next=t;

    }

}

void display(struct node *h)
{
    
    do{
        cout<<h->data<<endl;
        h=h->next;

    }while(h!=head);

}



int main()
{

    
    int a[]={3,4,5,6,7,8};
    create(a,6);

    insert(head,3,10);
    display(head);
    return 0;
}