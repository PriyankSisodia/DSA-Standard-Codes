#include<iostream>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <utility> 
#include <cmath>
#include <set>
// using namespace std;
using namespace std;
#include "LinkedList.cpp"

void print(Node* head){
	Node *temp = head;
	// cout<<"Inside"<<endl;
	while(head!=NULL){
		// cout<<"PP"<<endl;
		cout<<head->data;
		if(head->next!=NULL){
			cout<<"->";
		}
		head = head -> next;
		// cout<<"kk"<<endl;
	}
	cout<<endl;
	// cout<<"ll"<<endl;
}

//sorting two sorted linked list
Node* sorting(Node *nhead,Node *mhead){
	Node * ft;//final head, final tail, head1, head2
	Node * fh;
	Node * h1;
	Node * h2;
	h1 = nhead;
	h2 = mhead;
	if(h1->data>h2->data){ //checking the head for the final list
		ft =h2;
		fh =h2;
		h2 = h2->next;
	}
	else{
		ft=h1;fh=h1;
		h1 = h1->next;
	}
	while(h1!=NULL&&h2!=NULL){ //till one of the list gets empty
		if(h1->data>h2->data){
			ft->next = h2;
			ft =ft->next;
			h2 = h2->next;
		}
		else
		{
			ft->next= h1;
			ft = ft->next;
			h1 = h1->next;
		}
	}
	if(h1==NULL){
		ft->next = h2;
	}
	else
	{
		ft->next = h1;
	}
	return fh;





}
int main(){

	Node n1(1);
	Node n2(2);
	Node n3(3);
	Node n4(22);
	Node *nhead = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;

	Node m1(4);
	Node m2(5);
	Node m3(23);
	Node m4(33);
	Node *mhead = &m1;
	m1.next = &m2;
	m2.next = &m3;
	m3.next = &m4;
	print(nhead);
	print(mhead);
	Node*final = sorting( nhead, mhead);
	print(final);
}