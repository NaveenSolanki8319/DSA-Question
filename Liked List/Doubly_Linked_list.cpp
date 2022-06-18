#include<iostream>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next; 
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

node *insertBegin(node *head,int val)
{
    node *ptr=new node(val);
    if(head==NULL)
        head=ptr;
    else
    {
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
    }
    return head;
}

node *insertEnd(node *head,int val)
{
    node *ptr=new node(val);
    if(head==NULL)
        head=ptr;
    else
    {
        node *curr=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;    
        }
        curr->next=ptr;
        ptr->prev=curr;
    }
    return head;
}

node *delBegin(node *head)
{
    if(head==NULL)
        return NULL;
    else
    {
        node *curr=head;
        head=head->next;
        head->prev=NULL;
        delete(curr);
    }
    return head;
}

node *delEnd(node *head)
{
    if(head==NULL)
        return NULL;
    else
    {
        node *curr=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;    
        }
        curr->prev->next=NULL;
        delete(curr);
        return head;
    }
}

void Traversing_from_first(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}

node *reverse_dll(node *head)
{
    if(head==NULL || head->next==NULL)
    return head;
    node *tmp=NULL;
    node *curr=head;
    while(curr != NULL)
    {
        tmp = curr->prev;
        curr->prev = curr->next;
        curr->next = tmp;
        curr = curr->prev;
    }
    return tmp->prev;
}
int main()
{
    // // Insert at Begin
    // node *head=NULL;
    // head = insertBegin(head,10);
    // head = insertBegin(head,20);
    // head = insertBegin(head,30);
    // Traversing_from_first(head);
   
    // // Insert at End
    // node *head=NULL;
    // head = insertEnd(head,10);
    // head = insertEnd(head,20);
    // head = insertEnd(head,30);
    // Traversing_from_first(head);
    
    // Delete at first
    // node *head=NULL;
    // head = insertEnd(head,10);
    // head = insertEnd(head,20);
    // head = insertEnd(head,30);
    // head = delBegin(head);
    // head = delBegin(head);
    // head = delBegin(head);
    // Traversing_from_first(head);
    
    // // Delete at last
    // node *head=NULL;
    // head = insertEnd(head,10);
    // head = insertEnd(head,20);
    // head = insertEnd(head,30);
    // head = delEnd(head);
    // head = delEnd(head);
    // head = delEnd(head);
    // Traversing_from_first(head);
    
    // reverse dll
    node *head=NULL;
    head = insertEnd(head,10);
    head = insertEnd(head,20);
    head = insertEnd(head,30);
    Traversing_from_first(head);
    head = reverse_dll(head);
    cout<<endl;
    Traversing_from_first(head);
    return 0;
}