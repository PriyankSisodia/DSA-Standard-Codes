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

//function to reversez the linked list
//using recursion
Node* reverse(Node* head){
	//base case
	if(head==NULL||head->next==NULL){
		return head;
	}

	//recursiion
	Node *smallAns = reverse(head->next); //it will return head of reversed LL after the head 

	Node *temp = smallAns; //go to the end of reversed LL
	while(temp->next!=NULL){
		temp = temp->next;
	}
	//add head node to the LL at end
	temp->next = head;
	head ->next = NULL;  //make head's null 
	return smallAns; //smallans contain head of reversed LL
}

//==============================================================
//reverse using iterative
Node* reverse_iter(Node* head) {
    Node* prev = NULL; //prev node
    if(head==NULL){
        return NULL;
    }
    Node* curr = head; //curr node
    Node* nex =curr->next; //its next node
    
    while(curr!=NULL){
        // cout<<curr->val<<"-";
        
        //reverse
        curr->next = prev;
        prev = curr;
        
        //traverse
        curr=nex;
        if(curr == NULL){
            break;
        }
        nex = curr->next;
    }
    return prev;
}


Node* takeInput(){
	// cout<<"Enter -"<<endl;
	int data;            //data for any node
	// cout<<data;
	cin>>data;

	// cout<<"hel";             
	Node *head = NULL;   //head of LL
	Node *tail = NULL;
	// cout<<"hel";
	while(data!=-1){     //if ==-1, nomore nodes will be made
		Node *newNode = new Node (data); //make a new node with data 
		
		if(head==NULL){
			head = newNode;
			tail = newNode;
			// cout<<"hel";
		} 

		else
		{
			tail->next = newNode;   //in the last node add the next node
			tail = newNode;
		}
		
		// cout<<"hel";
		cin>>data;     //while(data!=-1)   
	}
	return head;
	// cout<<"Done 1";
}
//fun to insert the node in between


Node* insertNode(Node *head, int i, int data){
	Node *newNode = new Node(data);
	if(i==0)
	{
		newNode->next = head;
		head = newNode;
		return head;
	}
	int count=0;
	Node *temp=head;
	while(temp!=NULL && count<i-1){ // case if we pass the index that is biger than size of ll
		temp =temp->next;
		count++;
	}
	//not count = i-1,we have to add that new node kust after this pos
	
	//in case we got i > size of LL
	if(temp!=NULL){
		newNode->next = temp->next;
		temp->next=newNode;
	}
	return head;

}

Node* deleteNode(Node* head, int i )
{
	Node *temp = head;
	int count=0;
	if(i==0)
	{
		head = head->next;
		return head;
	}
	while(temp!=NULL&&count<i-1){
		temp = temp->next;
		count++;
	}
	//now count = i-1,this is temp, we have to delete ith node(temp->next), 
	if(temp!=NULL){
		temp->next = (temp->next)->next;
	}
	return head;
}

//function to print the LL
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


//imp 
int midValueLL(Node* head){//find midval without using size of the LL
	// cout<<"cum/
	Node *slow=head;
	Node *fast = head;
	// cout<<"inside";

//when to stop
	//fast will be NULL if the length of LL is even
	//fast->next will NULL if the length of LL is odd

	while(fast!=NULL && fast->next!= NULL){ 
		//if any of them got null,it means we got the middle node
        slow = slow->next;
        fast = (fast->next)->next;
    }
	//if length comes to be even
	return slow->data;
}

int size(Node* head){
	int count=0;
	Node * temp = head;
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}



//=============function to re order ll in last first alternate manner
Node* fun(Node* head){
	int arr[1000];
	
	for(int i =0;i<1000;i++){
		arr[i] =-1;
	}
	Node* temp = head;
 
    // push all the elements of linked list in to deque
    int j =0;
    while (temp != NULL) {
		arr[j++] = temp->data;        
        temp = temp->next;
    }
    for(int k =0;k<j;k++){
    	cout<<arr[k]<<" ";
    }
    j--;
    int i =0;
    temp = head;
    int p =0;
    while(i<=j){
    	if (p % 2 == 0) {
            temp->data = arr[j];
            // d.pop_front();
            j--;
            p++;
        }
        else {
            temp->data = arr[i];
            // d.pop_back();
            i++;
            p++;
        }
        temp = temp->next;
    }
    return head;
}



//tesung

int main (){

	#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input2.txt", "r", stdin);
		// for writing output to output.txt
		freopen("output3.txt", "w", stdout);
	#endif



	//statically
	/*
	Node n1(6);
	Node *head = &n1;
	Node n2(9);
	Node n3(12);
	Node n4(15);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	*/

	/*
	n1.next = &n2;
	cout<<head->data<<" "<<(head->next)->data<<endl;

	//dynamically
	Node *n3 = new Node(10);
	Node *head = n3;
	Node *n4 = new Node(20);
	n3 ->next = n4;
	*/

	Node *head = takeInput();
	cout<<"Original:"<<endl;
	print(head);
	// int s=size(head);
	cout<<"Size-"<<size(head)<<endl;

	head =insertNode(head,3,69); // insert node in the linked list
	cout<<"After Inserting Node:"<<endl;
	print(head);
	int midValue = midValueLL(head);
	cout<<"Size-"<<size(head)<<endl;
	cout<<"Mid value of linked list- "<<midValue<<endl;

	// cout<<head->data<<endl;
	head = deleteNode(head,0);
	cout<<"After Deleting Node:"<<endl;
	print(head);
	// cout<<"HI1"<<endl;
	cout<<"Size-"<<size(head)<<endl;

	// cout<<head->data<<endl;
	// cout<<"HI"<<endl;

	midValue = midValueLL(head);
	// cout<<"YH";
	cout<<"Mid value of linked list- "<<midValue<<endl;

	head = reverse(head);
	cout<<"Size-"<<size(head)<<endl;
	cout<<"Reversal of LL"<<endl;
	// cout<<head->next<<endl;
	print(head);

	// Node *head = takeInput();
	// print(head);
	// fun(head);
	// print(head);


/*
questions on LL
- Detect loop in LL 3 methods (change values, hashmap, floyd cycle) //check gfg


*/
}