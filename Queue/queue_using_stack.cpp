#include <iostream>
#include <stack>
using namespace std;
class queue
{
	stack<int>s1;
 	stack<int>s2;
	public: 
	
    void enqueue(int x)
	{
		s1.push(x);
	}

	void dequeue()
	{
		if(s1.empty() && s2.empty())
		{
			cout<<"Queue is Empty"<<endl;
		}
		else
		{
            if(s2.empty())
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
		}
        int topval=s2.top();
        s2.pop();
        cout<<"Value Deleted= "<<topval<<"  ";
	}
};
 
int main()
{
	//Write code here
	queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    // q.enqueue(5);
    // q.enqueue(6);
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	return 0;
}