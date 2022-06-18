
#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;
int priority(char ch)
{
    if(ch=='^')
    return 5;
    else
    if(ch=='*' || ch=='/')
    return 4;
    else
    if(ch=='+' || ch=='-')
    return 3;
    else
    return 0;
}
int main()
{
    stack <char>st;
    string exp = "(A - B/C) * (A/K-L)",res;
    reverse(exp.begin(),exp.end());
    for(int i=0; i<exp.size(); i++)
    {
        if(exp[i]==')')
        st.push(exp[i]);
        else
        if((exp[i]>='a' && exp[i]<='z')||(exp[i]>='A' && exp[i]<='Z')||(exp[i]>='0' && exp[i]<='9'))
        res=res+exp[i];
        else
        if(exp[i]=='(')
        {
            while(!st.empty() && st.top()!=')')
            {
                res=res+st.top();
                st.pop();
            }
            if (!st.empty())
            st.pop(); // Popping '(' here
        }
        else
        if(exp[i]=='+' ||exp[i]=='-' ||exp[i]=='*' ||exp[i]=='/' ||exp[i]=='^' )
        {
            while(!st.empty() &&(priority(exp[i])<=priority(st.top())))
            {
                res=res+st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
    }
    while(!st.empty())
    {
        res=res+st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
    return 0;
}
// struct stack_arr
// {
//     int *arr,cap,top;
//     stack_arr(int size)
//     {
//         arr=new int[size];
//         cap=size;
//         top=-1;
//     }
//     bool isFull()
//     {
//         return (top==cap-1);
//     }

//     bool isEmpty()
//     {
//         return (top==-1);
//     }

//     void push(int ele)
//     {
//         if(isFull())
//         cout<<"Stack if Full\n";
//         else
//         {
//             top++;
//             arr[top]=ele;
//             cout<<"Element inserted successfully\n";
//         }
//     }

//     int pop()
//     {
//         if(isEmpty())
//         return -1;
//         else
//         {
//             int delEle=arr[top];
//             top--;
//             return delEle;
//         }
//     }

//     int first()
//     {
//         if(isEmpty())
//         return -1;
//         else
//         return arr[top];
//     }

//     void traverse()
//     {
//         if(isEmpty())
//         cout<<"Stack is Empty";
//         else
//         {
//             int tmp=top;
//             while(tmp>=0)
//             {
//                 cout<<arr[tmp]<<" ";
//                 tmp--;
//             }
//         }
//     }
// };
// int main()
// {
//     stack_arr s1(5);
//     s1.push(10);
//     s1.push(20);
//     s1.push(30);
//     s1.push(40);
//     s1.push(50);
//     s1.push(60);
//     s1.traverse();
//     cout<<endl<<s1.first()<<endl;
//     s1.pop();
//     s1.pop();
//     s1.pop();
//     s1.pop();
//     // s1.pop();
//     s1.traverse();
//     return 0;
// }
// struct node
// {
//     int data;
//     node *next;
//     node(int val)
//     {
//         data=val;
//         next=NULL;
//     }
// };

// node *push(node *head,int val)
// {
//     node *curr=new node(val);
//     if(head==NULL)
//     head=curr;
//     else
//     {
//         node *tmp=head;
//         while(tmp->next!=NULL)
//         {
//             tmp=tmp->next;
//         }
//         tmp->next=curr;
//     }
//     return head;
// }

// node *pop(node *head)
// {
//     if(head==NULL)
//     return NULL;
//     else
//     if(head->next==NULL)
//     {
//         delete(head);
//         return NULL;
//     }
//     else
//     {
//         node *tmp=head;
//         while(tmp->next->next!=NULL)
//         {
//             tmp=tmp->next;
//         }
//         node *delNode=tmp->next;
//         tmp->next=NULL;
//         delete(delNode);
//         return head;
//     }
    
// }
// void Traversing(node *head)
// {
//     if(head==NULL)
//     cout<<"Stack is empty"<<endl;

//     node *curr = head;
//     while (curr != NULL)
//     {
//         cout << curr->data << " ";
//         curr = curr->next;
//     }
//     cout << endl;
// }
// int main()
// {
//     node *head=NULL;
//     head=push(head,10);
//     head=push(head,20);
//     head=push(head,30);
//     head=push(head,40);
//     Traversing(head);
//     head=pop(head);
//     head=pop(head);
//     head=pop(head);
//     head=pop(head);
//     Traversing(head);
//     return 0;
// }

