#include "BinaryTreeNode.h"
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
#include <queue>

using namespace std;

class BST{
	//make root node
	BinaryTreeNode<int> * root;


public:
	BST(){//constructor
		root=NULL;
	}
	~BST(){//destructor for deleting tree
		delete root;
	}

private:
	BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node){
		if(root==NULL){
			return NULL;
		}
		if(data>node->data){
			//updated rigfht node
			node->right =deleteData(data,node->right);
			return node;
		}
		else if(data< node->data){
			//updated left node
			node->left = deleteData(data,node->left);
			return node;
		}
		else{
			//first case - both left and right are null
			if(node->left==NULL && node->right==NULL){
				
				delete node; //delete the leave and return null
				return NULL;
			}
			//sec case - left is null == means return rights subtree root
			else if(node->left==NULL){
				BinaryTreeNode<int>* temp = node->right;//save node's right to temp 
				node->right =NULL; //nodes right should be null , because if we delete the node the full right tree will get deleted as it contains all addresse
				delete node; //delete node
				return temp; //return temp

			}

			//third case - right is null ==means we need to return left sub tree's root
			else if(node->right==NULL){
				BinaryTreeNode<int>* temp = node->left;//save node's right to temp 
				node->left =NULL;
				delete node; //delete node
				return temp; //return temp

			}

			//fourth case - both are non-null== take minimum value of right subtree in the root 
			else
			{
				BinaryTreeNode<int>* minNode = node->right;
				while(minNode->left!=NULL){//move left till we get the minimum of the right subtree
					minNode=minNode->left;
				}
				int rightMin = minNode->data; //min value in right subtree
				node->data = rightMin; //put value of rightmin in the root node of right subtree
				node->right = deleteData(rightMin,node->right); //delete min node
				return node;
			}
		}

	}
private:
	//print level wise
	void printTree(BinaryTreeNode<int> * root){
		//base case
		if(root==NULL){
			return;
		}
		cout<<root->data<<": ";
		if(root->left){
			cout<<"L"<<root->left->data;
		}
		if(root->right){
			cout<<"R"<<root->right->data;
		}
		cout<<endl;
		printTree(root->left);
		printTree(root->right);
	}
public:
	//delete data from BST
	void deleteData(int data){
		root = deleteData(data,root);
	}

void printTree(){
	printTree(root);
}

private:
	BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node){
		if(node==NULL){
			BinaryTreeNode<int>* newNode = new BinaryTreeNode<int> (data);
			return newNode;
		}
		if(data<node->data){
			node->left = insert(data,node->left);
		}
		else{
			node->right = insert(data,node->right);
		}
		return node;
	}

public:
	//insert data into BST
	void insert(int data){
		this->root = insert(data,this->root);
	}

private:
	//helper fun to search elemtn in tree
	bool hasData(int data,BinaryTreeNode<int>* node)
	{
		if(node==NULL){
				return false;
			}
			if(node->data==data){
				return true;
			}
			else if(data<node->data){
				return hasData(data,node->left);
			}
			else {
				return hasData(data,node->right);
			}
	}

public: 
	bool hasData(int data){ //as we can not ask root from user so need to make another private fun
		return hasData(data,root);
	}
};