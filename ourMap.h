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
//using separate chaining

//flow
//key -> hashFunction -> index

//****************************************
//insert new ele ->calculate load factor -> if LF >0.7 -> rehash 
using namespace std;

template<typename V>

//linked list node 
class MapNode{ 
public:
	string key; //having a string key
	V value; //and value of datatype V
	MapNode* next; //pointer to next node

	MapNode(string key, V value){
		//assign values in constructor
		this->key =key;
		this->value = value;
		this->next= NULL;
	}
	~MapNode(){
		delete next;
	}
};


template<typename V>
class ourMap
{

	MapNode<V>** buckets; //array that contains address of linked list(MapNode<V>*), we will add one more * as bucket variable will save the adress of that array
	int count;
	int numBuckets;

public:
	
	ourMap(){
		count=0;
		numBuckets=5;//initialize number of buckets in array
		buckets = new MapNode<V>*[numBuckets];//array of size numBuckets that contains address of linked list of each bucket
		for (int i = 0; i < numBuckets; ++i)
		{
			buckets[i] =NULL;
		}

	}

	~ourMap(){
		//to delete our map ,first delete all linked list(means buckets)
		for (int i = 0; i < numBuckets; ++i)
		{
			delete buckets[i];
		}
		delete [] buckets;
	}

	//return size of 
	int size(){
		return count;
	}

	//get value at key 
	V getValue(string key){
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		while(head!=NULL){
			if(head->key==key){
				return head->value;
			}
		}
		return 0;
	}

private:  

	//take key and return the index of array to be added(hashFunction)
	int getBucketIndex(string key){
		int hashCode=0;
		//our hashcode for any key string
		//"abc" -> a*p^2 + b*p^1 + c*p^0; //ascii val of each char
		int currentCoeff =1;
		for (int i = key.length()-1; i >=0 ; i--)
		{
			hashCode += key[i] * currentCoeff;
			hashCode = hashCode % numBuckets;
			currentCoeff *= 37; //p ->generally we take prime number fo hashfunction
			currentCoeff = currentCoeff % numBuckets; //modulo is used to avoid overflow
		}

		return hashCode%numBuckets;
	}

//************************

	void rehash(){
		MapNode<V>** temp = buckets; //pointer to old bucket array
		buckets = new MapNode<V>*[2 * numBuckets]; //double the bucket array (i order to reduce load factor)
		for (int i = 0; i < 2*numBuckets; ++i)
		{//make array elements with null 
			buckets[i] = NULL;
		}
		int oldBucketCount = numBuckets;
		numBuckets *= 2; //new bucket counts
		count=0;

		//rehash all elemntes in oldbucket to new bucket
		for (int i = 0; i < oldBucketCount; ++i)
		{
			MapNode<V>* head = temp[i];//for every LL in old bucket (temp contains address of oldbucket)
			while(head!=NULL){//move throigh the LL
				string key = head->key;
				V value = head->value;
				insert(key, value);//rehash in Bucket ( new bucket with double size)
				head =head->next; //move in LL
			}
		}
		//dekete old bucket
		for (int i = 0; i < oldBucketCount; ++i)
		{
			MapNode<V>* head = temp[i];
			delete head;
		}
		delete [] temp;
	}

//***************************
public:
double getLoadfactor(){
	return (1.0*count)/numBuckets;
}

//*************************
public:
	
	//insert pair 
	void insert(string key , V value){
		int bucketIndex = getBucketIndex(key);

		//check if key is already present or not in the lined kist
		MapNode<V>* head = buckets[bucketIndex];
		while(head!=NULL){
			if(head->key==key){//if key is found 
				//update value
				head->value =value;
				return;//we didnt update count beacuse we are not making new node
			}
			//move forward
			head = head->next;
		}
		//key not found == make a new node and add it 
		head = buckets[bucketIndex];//thispoints to head of linked list of index
		MapNode<V>* node = new MapNode<V>(key , value);
		node->next=head; //linked list is not attched to node (node is first node of LL now)
		buckets[bucketIndex] = node;//now add the updated LL to index
		count++;//count number of entries we made

		//rehashing
		double loadfactor = (1.0*count)/numBuckets; //load factor
		if(loadfactor>0.7){
			rehash();
		}
	}


	//remove pair and return value of deleted pair
	V remove(string key){
		//first try to find key 
		int bucketIndex = getBucketIndex(key);//get index
		MapNode<V>* head = buckets[bucketIndex];//head node
		MapNode<V>* prev = NULL;//prev node
		while(head!=NULL){//check every node of linkde list
			if(head->key==key){//if key found
				if(prev==NULL){ //if the prev node is null(means we want to delet first elemnt of LL)
					buckets[bucketIndex] = head->next;//move head by one
				}else{
					prev->next =head->next;//delet head from LL
				}
				V value = head->value;//save value of deleted node
				head ->next =NULL;//put head->next NULL beacuse it already a LL, if we do not use this tha whole LL will get deleted after head
				delete head;
				count--;//as key decresese
				return value;

			}
			prev =head;//update prev
			head=head->next;//update head
		}

		return 0; //value not found
	}
};