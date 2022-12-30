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

template<typename T>
class QueueUsingArray{

	T * data; //will store address of array
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;
public:
	QueueUsingArray(int s){
		data = new T[s]; //make array of T datatye size s
		nextIndex=0;
		firstIndex=-1;
		size=0;
		capacity =s;
	}
	int getSize(){
		return size;
	}
	bool isEmpty(){
		return size==0;
	}
	//insert elemnet
	void enqueue(T element){
		if(size==capacity){
			cout<<"Queue full"<<endl;
			return;
		}
		data[nextIndex]=element;
		nextIndex = (nextIndex + 1) % capacity;//new elemnts ar added in starting of the array 
		size++;
		if(firstIndex==-1){
			firstIndex=0;
		}

	}
	T front(){
		if(isEmpty()){
			cout<<"Empty"<<endl;
			return 0;
		}
		T temp = data[firstIndex];
		return temp;

	}
	T dequeue(){
		if(isEmpty()){
			cout<<"Empty"<<endl;
			return 0;
		}
		T ans = data[firstIndex];
		firstIndex = (firstIndex+1)%capacity;
		size--;
		if(size==0){
			firstIndex=-1;
			nextIndex=0;
		}
		return ans;
	}
	//add function that will print all queue
	void print(){

		cout<<"Queue is - "<<endl;
		int k = firstIndex;
		for(int i =0;i<size;i++){
			cout<<data[k]<<" ";
			k++;
			k = k%capacity;
		}
		cout<<endl;

	}

};