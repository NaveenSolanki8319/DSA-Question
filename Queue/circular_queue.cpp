#include <iostream>
using namespace std;
class queue
{
	int *arr, front, rear;
	int capacity;

	public:
	queue(int n)
	{
		arr = new int[n];
		front = -1;
		rear = -1;
		capacity = n;
	}

	void enqueue(int x)
	{
		if((rear+1)%capacity==front)
		{
			cout<<"Queue is Full"<<endl;
			return;
		}
		else
		if(rear==-1)
		{
			rear=front=0;
			arr[rear]=x;
		}
		else
		{
			rear=((rear+1)%capacity);
			arr[rear]=x;
		}
	}

	void dequeue()
	{
		if(front==-1  || front>rear)
		{
			cout<<"Queue is Empty"<<endl;
		}
		else
		{
			cout<<"Deleted Element = "<<arr[front]<<endl;
			arr[front]=0;
			front=((front+1)%capacity);
		}
	}

	void Print()
	{
		if(front==-1  || front>rear)
		{
			cout<<"Queue is Empty"<<endl;
		}
		else
		{
			for(int i=front; i<=rear; i++)
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
	queue q = queue(size);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	// q.enqueue(6);
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
    q.dequeue();
	q.Print();
	return 0;
}
