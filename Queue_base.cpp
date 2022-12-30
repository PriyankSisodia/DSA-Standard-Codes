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
using namespace std;

#include "Queue_usingArray.cpp"
#include "Queue_usingLL.cpp"

int main(){


//==========================================================
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input2.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output3.txt", "w", stdout);
#endif
//==========================================================
	QueueUsingArray<int> q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.print();
	cout<<q.getSize()<<endl;
	cout<<q.front()<<endl;
	q.dequeue();
	q.print();
	cout<<q.getSize()<<endl;
	cout<<q.front()<<endl;
	cout<<q.isEmpty()<<endl;


//opertaions on queue using linkd list
	Queue_usingLL<int> h;
	h.enqueue(10);
	h.enqueue(20);
	h.enqueue(30);
	h.enqueue(40);
	h.enqueue(50);
	h.print();
	cout<<h.getSize()<<endl;
	cout<<h.front()<<endl;
	h.dequeue();
	h.print();
	cout<<h.getSize()<<endl;
	cout<<h.front()<<endl;
	cout<<h.isEmpty()<<endl;




}