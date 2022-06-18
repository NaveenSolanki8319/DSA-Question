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
node *front = NULL, *back = NULL;

void enqueue(int x)
{
	node *ptr = new node(x);
	if (front == NULL)
	{
		front = back = ptr;
	}
	else
	{
		back->next = ptr;
		back = ptr;
	}
}

void dequeue()
{
	if (front == NULL || back == NULL)
	{
		cout << "Queue is Empty" << endl;
	}
	else
	{
		node *node_to_delete = front;
		front = front->next;
		delete node_to_delete;
	}
}

void Print()
{
	if (front == NULL || front > back)
	{
		cout << "Queue is Empty" << endl;
	}
	else
	{
		while (front != NULL)
		{
			cout << front->data << " ";
			front = front->next;
		}
		cout << endl;
	}
}

int main()
{

	int size, ele;
	cout<<"Enter size of Queue "<<endl;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter element : "<< endl;
		cin >> ele;
		enqueue(ele);
	}
	dequeue();
	dequeue();
	dequeue();
	// dequeue();
	// dequeue();

	Print();
	return 0;
}