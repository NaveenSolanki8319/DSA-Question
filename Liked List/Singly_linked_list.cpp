#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void Traversing(node *head)
{
    node *curr=head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

void recurFunTraversing(node *head)
{
    if (head==NULL)
        return;
    else
    {
        cout << head->data << " ";
        recurFunTraversing(head->next);
    }
}

node *insertBegin(node *head, int val)
{
    node *ptr = new node(val);
    if (head == NULL)
        head = ptr;
    else
    {
        ptr->next = head;
        head = ptr;
    }
    return head;
}

node *insertEnd(node *head, int val)
{
    node *ptr = new node(val);
    if (head == NULL)
        head = ptr;
    else
    {
        node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = ptr;
    }
    return head;
}
node *insertSpecific(node *head, int val,int pos)
{
    node *ptr = new node(val);
    if (head == NULL)
    {    
        head = ptr;
        return head;
    }
    else
    if(pos==1)
    {
        node *curr=insertBegin(head,val);
        return curr;
    }
    else
    {
        node *curr = head;
        for(int i=0;i<pos-2 && curr->next!=NULL;i++)
        {
            curr = curr->next;
        }
        ptr->next=curr->next;
        curr->next = ptr;
    }
    return head;
}

node *delBegin(node *head)
{
    if (head == NULL )
        return NULL;
    if (head->next == NULL)
    {
        delete (head);
        return NULL;
    }
    else
    {
        node *curr = head;
        head = head->next;
        delete (curr);
        return head;
    }
}

node *delEnd(node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        node *curr = head;
        while (curr->next->next != NULL)
            curr = curr->next;
        delete (curr->next);
        curr->next = NULL;
        return head;
    }
}

void search(node *head, int search_val)
{
    if (head == NULL)
    {
        cout << "Empty Linked list" << endl;
        return;
    }
    else
    {
        node *curr = head;
        while (curr != NULL) // to travel whole linked list
        {
            if (curr->data == search_val)
            {
                cout << "Value Present" << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Value not Present" << endl;
    }
}

node *reverse(node *head)
{
    // Initialize current, previous and
    // next pointers
    node* current = head;
    node *prev = NULL, *next = NULL;
    while (current != NULL) 
    {
        next = current->next;// Store next
        current->next = prev;// Reverse current node's pointer
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
node *remDup(node *head)
{
    if(head==NULL)
    return NULL;
    else
    if(head->next==NULL)
    return head;
    else
    {
        node *curr1=head, *curr2=head;
        for(curr1=head; curr1->next!=NULL && curr1!=NULL;curr1=curr1->next)
        {
            for(curr2=curr1;curr2->next!=NULL ; curr2=curr2->next)
            {
                if(curr1->data==curr2->next->data)
                {
                    node *delNode=curr2->next;
                    curr2->next=curr2->next->next;
                    delete(delNode);
                }
            }
        }
    }
    return head;
}
int main()
{
    // Traversing
    // node *head=new node(10);
    // head->next=new node(20);
    // head->next->next=new node(30);
    // recurFunTraversing(head);

    // Insert at begin
    // node *head=NULL;
    // head = insertBegin(head,40);
    // head = insertBegin(head,30);
    // head = insertBegin(head,20);
    // head = insertBegin(head,10);
    // Traversing(head);
    
    // Insert at Specific position
    node *head=NULL;
    head = insertBegin(head,6);
    head = insertBegin(head,5);
    head = insertBegin(head,3);
    head = insertBegin(head,1);
    head = insertSpecific(head,2,2);
    head = insertSpecific(head,7,6);
    head = insertSpecific(head,8,7);
    Traversing(head);
    head = reverse(head);
    cout<<endl;
    Traversing(head);

    // Insert at end
    // node *head=NULL;
    // head = insertEnd(head,100);
    // // head = insertEnd(head,200);
    // // head = insertEnd(head,300);
    // // head = insertEnd(head,400);
    // Traversing(head);

    // // Delete Begin node
    // node *head=NULL;
    // head = insertEnd(head,100);
    // head = insertEnd(head,200);
    // head = insertEnd(head,300);
    // head = insertEnd(head,400);
    // head = delBegin(head);
    // head = delBegin(head);
    // head = delBegin(head);
    // // head = delBegin(head);
    // Traversing(head);

    // Delete last node
    // node *head=NULL;
    // head = insertEnd(head,100);
    // head = insertEnd(head,200);
    // head = insertEnd(head,300);
    // head = insertEnd(head,400);
    // head = delEnd(head);
    // head = delEnd(head);
    // Traversing(head);

    // Search node
    // node *head = NULL;
    // head = insertEnd(head, 100);
    // head = insertEnd(head, 200);
    // head = insertEnd(head, 300);
    // head = insertEnd(head, 400);
    // head = delEnd(head);
    // head = delEnd(head);
    // search(head,100);
    // Traversing(head);
    return 0;
}