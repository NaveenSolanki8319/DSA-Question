#include <iostream>
using namespace std;
class DEQueue
{
    int size, capacity;
    int *arr;

    public:
    DEQueue(int n)
    {
        capacity = n;
        size = -1;
        arr = new int[capacity];
    }

    bool isFull()
    {
        return (size == capacity-1);
    }

    bool isEmpty()
    {
        return (size == -1);
    }

    void insertRear(int val)
    {
        if (isFull())
            return;
        else
        {
            size++;
            arr[size] = val;
        }
    }

    void deleteRear()
    {
        if (isEmpty())
            return;
        else
            size--;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return (arr[size]);
    }

    void insertFront(int x)
    {
        if (isFull())
            return;
        else
        {
            size++;
            for(int i=size-1; i >= 0; i--)      //size-1 is because element is present till size-1
            {
                arr[i+1]=arr[i];
            }
            arr[0] = x;
        }
    }

    void deleteFront()
    {
        if (isEmpty())
            return;
        else
        {
            for (int i=1; i<=size; i++)
            {
                arr[i-1]=arr[i];
            }
            size--;
        }
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        else
            return (arr[0]);
    }

    void Print()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty no element to display"<<endl;
        }
        else
        {
            for(int i=0; i<=size; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int size;
    cout << "Enter Size of Queue :- ";
    cin >> size;
    DEQueue q = DEQueue(size);

    q.insertFront(30);
    q.insertFront(20);
    q.insertFront(10);
    q.insertRear(40);
    q.insertRear(50);
    q.insertRear(60);
    q.deleteFront();
    q.deleteFront();
    q.deleteRear();
    q.deleteRear();
    q.deleteRear();
    // q.deleteRear();
    cout << "Front = " << (q.getFront()) << endl;
    cout << "Rear = " << (q.getRear()) << endl;
    q.Print();
    return 0;
}