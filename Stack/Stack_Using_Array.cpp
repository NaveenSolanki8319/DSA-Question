#include <iostream>
using namespace std;

struct Stack_Array
{
    int *arr, cap, top;
    Stack_Array(int c)
    {
        cap=c;
        arr = new int[cap];
        top=-1;
    }

    bool isFull()
    {
        return (top==cap-1);
    }

    bool isEmpty()
    {
        return (top==-1);
    }

    void push(int val)
    {
        if(isFull())
            cout<<"Stack is Full\n";
        else
        {
            top++;
            arr[top]=val;
        }
    }

    int pop()
    {
        if(isEmpty())
            return -1;
        else
        {
            int delVal= arr[top];
            top--;
            return delVal;
        }
    }

    int peek()
    {
        if(isEmpty())
            return -1;
        else
            return arr[top];
    }  
    
    int size()
    {
        return (top+1);
    }

    void Travaverse()
    {
        if(isEmpty())
            cout<<"Stack is Empty\n";
        else
        {
            for(int i=0;i<=top;i++)
            {
                cout<<arr[i]<<" ,";
            }
            cout<<endl;
        }
    }
};


int main()
{
    Stack_Array s(5);
    // s.Travaverse();
    s.push(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.Travaverse();
    cout << s.peek() << endl;
    cout << s.size() << endl;
    cout << s.pop() << endl;
    cout << s.isEmpty()<< endl;
    s.Travaverse();
    return 0;
}