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

node *push(node *head, int val)
{
    node *ptr = new node(val);
    if (head == NULL)
    {
        head = ptr;
        return head;
    }
    else
    {
        node *tmp = head;
        while (tmp->next != NULL)
        {
            tmp=tmp->next;
        }
        tmp->next = ptr;
        return head;
    }
}

node *pop(node *head)
{
    if (head == NULL)
        return NULL;
    else 
    if (head->next == NULL)
    {
        delete (head);
        return NULL;
    }
    else
    {
        node *curr=head;
        while(curr->next->next!=NULL)
            curr=curr->next;
        
        node *lastNode = curr->next;
        curr->next = NULL;
        delete (lastNode);
        return head;
    }
}

int peek(node *head)
{
    if (head == NULL)
        return -1;
    else
    {
        node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        return (curr->data);
    }
}

void Traversing(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    head = push(head, 10);
    head = push(head, 20);
    head = push(head, 30);
    head = push(head, 40);
    Traversing(head);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    Traversing(head);
    cout << "Top = " << peek(head) << endl;
    return 0;
}