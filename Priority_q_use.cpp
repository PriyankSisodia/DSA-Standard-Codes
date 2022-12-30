#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include<string.h>
#include<string>
#include <string>
#include <utility> 
#include <cmath>
#include <set>
#include <climits>
using namespace std ;

#include "Priority_queue.h"

int main(){
	PriorityQueue p;
	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);

	cout<<p.getSize()<<endl;
	cout<<p.getMin()<<endl;
	//example of heap sort 
	while(!p.isEmpty()){
		cout<<p.removeMin()<<" ";
	}
	//complexity
	/*
	time to insert one element in heap is logn , inserting n elemnts will be nlogn
	remove n times = nlogn
	time= nlogn(insert) + nlogn(remove) = O(logn)
	space = O(n)
	*/
	cout<<endl;

	//using STL
	/* //syntax for min and max heap
		---priority_queue<int> max_heap;
		---priority_queue<int, vector<int>, greater<int> > min_heap;
		---pop() - remove the topmost element in heap
	*/
}

//======================use custom comparator in priority queue================
struct compare{
  public:
  bool operator()(Node& a,Node& b) // overloading both operators 
  {
      return a.w < b.w: // if you want increasing order;(i.e increasing for minPQ)
      return a.w > b.w // if you want reverse of default order;(i.e decreasing for minPQ)
   }
};

priority_queue<Node,vector<Node>,compare> pq;

//==================method 2==============================================
class Foo
{

};

bool Compare(Foo, Foo)
{
    return true;
}

int main()
{
    priority_queue<Foo, vector<Foo>, function<bool(Foo, Foo)>> pq(Compare);
    return 0;
}

//==========================================================