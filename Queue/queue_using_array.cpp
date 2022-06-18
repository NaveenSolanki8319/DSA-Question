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

	bool isFull()
	{
		return (rear == capacity-1);
	}

	bool isEmpty()
	{
		return (front == -1 || front > rear);
	}

	void enqueue(int x)
	{
		if (isFull())
		{
			cout << "Queue is Full no element is insert" << endl;
		}
		else if (rear == -1)
		{
			rear = front = 0;
			arr[rear] = x;
		}
		else
		{
			rear++;
			arr[rear] = x;
		}
	}

	void dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty No element for delete" << endl;
		}
		else
		{
			cout << "Deleted Element = " << arr[front] << endl;
			front++;
		}
	}

	int frontEle()
	{
		if (isEmpty())
			return -1;
		else
			return arr[front];
	}

	int rearEle()
	{
		if (isEmpty())
			return -1;
		else
			return arr[rear];
	}

	void Print()
	{
		if (isEmpty())
			cout << "Queue is Empty no element to display" << endl;
		else
		{
			for (int i=front; i<=rear; i++)
				cout<<arr[i]<<" ";
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

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	// q.dequeue();
	// q.dequeue();
	q.dequeue();
	q.dequeue();
	cout << "Front = " << (q.frontEle()) << endl;
	cout << "Rear = " << (q.rearEle()) << endl;

	// q.dequeue();
	q.Print();
	return 0;
}