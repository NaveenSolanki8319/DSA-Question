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

void printlist(node *head)
{
    if (head == NULL)
    return;
    node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}

node *insertBegin(node *head, int val)
{
    node *ptr = new node(val);
    if (head == NULL)
    {
        ptr->next = ptr;
        return ptr;
    }
    else
    {
        node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = ptr;
        ptr->next = head;
        head=ptr;   //InsertAtEnd me ye line nahi aayegi baki program as it is rahega
        return head;
    }

}

node *insertEnd(node *head, int val)
{
    node *ptr = new node(val);
    if (head == NULL)
    {
        ptr->next = ptr;
        return ptr;
    }
    else
    {
        node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = ptr;
        ptr->next = head;
        return head;
    }
}

node *delHead(node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = head->next;
    // head=head->next;
    delete head;
    return (curr->next);
}

node *delend(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == head)
    {
        head = NULL;
        return NULL;
    }
    else
    {
        node *temp = head;
        while (temp->next->next != head)
            temp = temp->next;
        node *lastNode = temp->next;
        temp->next = head;
        delete (lastNode);
        return head;
    }
}

node *deleteKth(node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
        return delHead(head);
    node *curr = head;
    for (int i = 0; i < k - 2; i++) //we traversing till just before the node to delete
        curr = curr->next;
    node *temp = curr->next;  //deleting the next node  
    curr->next = curr->next->next;
    delete temp;
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
        for(curr1=head;curr1->next!=NULL;curr1=curr1->next)
        {
            for(curr2=curr1;curr2->next!=NULL; curr2=curr2->next)
            {
                if(curr1->data==curr2->data)
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
    node *head = NULL;
    head = insertBegin(head, 50);
    head = insertBegin(head, 40);
    head = insertBegin(head, 30);
    head = insertBegin(head, 20);
    head = insertBegin(head, 20);
    head = insertBegin(head, 10);
    printlist(head);
    cout<<endl;
    head=remDup(head);
    printlist(head);
    return 0;
}