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

class Node
{
	
public:
	T data;
	Node<T>* next;
	Node(T data){
		this->data =data;
		next =NULL;
	}
	
};

template<typename T>
class Queue_usingLL
{
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	Queue_usingLL(){
		head=NULL;
		tail=NULL;
		size=0;
	}

	int getSize(){
		return size;
	}

	bool isEmpty(){
		return size==0;
	}

	void enqueue(T element){
		Node<T> * newNode = new Node<T>(element);
		// newNode->data = element;
		if(size==0){
			head= newNode;
			tail=newNode;
		}
		else{
			tail->next=newNode;
			tail=newNode;
		}
		size++;
	}
	
	T dequeue(){
		if(head==NULL){
			return 0;
		}
		Node<T> *temp = head;
		T ans = temp->data;
		head=temp->next;
		delete temp;
		size--;
		return ans;

	}

	T front(){
		if(head==NULL){
			return 0;
		}
		return head->data;
	}

	void print(){
		Node<T>* temp = head;
		cout<<"Queue is - ";
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;

	}
};

