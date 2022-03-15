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
int del(struct node *p,int index)
{
    struct node *q;
    int x;

    if(index<0 || index>length(head))   //check the index
    {
        return  -1;
    }
    if(index==1)
    {
        while(p->next!=head)
        {
            p=p->next;
        }
        x=head->data;

        if(head==p)
        {
            free(head);
            head=NULL;
        }
        else{
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else{
        for(int i=0;i<index-2;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);

    }
    return x;

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

    del(head,3);
    display(head);
    return 0;
}