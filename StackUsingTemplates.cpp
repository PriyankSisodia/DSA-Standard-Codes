#include <climits>

template <typename T>
class StackUsingTemplates
{
	T *data;
	int nextIndex;
	int capacity;
public:
	StackUsingTemplates() //constructer//
	{
		data = new T[4];
		nextIndex = 0;
		capacity = 4;
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
	void push(T element)
	{
		if(nextIndex == capacity)
		{
			// cout<<"StackFull"<<endl;
			// return;
			T *newData = new T[2*capacity];
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
	}
	T pop()
	{
		if(isEmpty())
		{
			cout<<"StackEmpty Fuckoff"<<endl;
			return 0;
		}
		nextIndex--;
		return data[nextIndex];
	}
	T top()
	{
		if(isEmpty())
		{
			cout<<"StackEmpty Fuckoff"<<endl;
			return 0;
		}
		return data[nextIndex-1];
	}
};