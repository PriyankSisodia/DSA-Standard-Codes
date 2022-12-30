#include <climits>
class StackUsingArray
{
	int *data; //data pointer
	int nextIndex; 
	int capacity; 
public:
	StackUsingArray() //constructer//
	{
		data = new int[4]; //make array of 4 size and return address of array to data
		nextIndex = 0;
		capacity = 4; //maximum size of array 
	}
	//return number of elemnets un the stack
	int size()
	{
		return nextIndex;
	}
	bool isEmpty()
	{
		return nextIndex==0;
	}
	void push(int element)
	{
		if(nextIndex == capacity)
		{
			// cout<<"StackFull"<<endl;
			// return;

			//double the size of array every time it gets completed
			int *newData = new int[2*capacity];
			for(int i=0;i<capacity;i++)
			{
				newData[i] = data[i];
			}
			capacity = 2*capacity;
			delete [] data;
			data = newData;
		}
		data[nextIndex++] = element;
		cout<<"Pushed-"<<element<<endl;
		//time complexity =O(n);
	}
	int pop()
	{
		if(isEmpty())
		{
			cout<<"StackEmpty Fuckoff"<<endl;
			return INT_MIN;
		}
		nextIndex--;
		return data[nextIndex];
	}
	int top()
	{
		if(isEmpty())
		{
			cout<<"StackEmpty Fuckoff"<<endl;
			return INT_MIN;
		}
		return data[nextIndex-1];
	}
};