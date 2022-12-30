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

// #include "BinaryTreeNode.h"
#include "BST.h"
using namespace std;

 
//===============================================================
//print level wise
void printTree(BinaryTreeNode<int> * root){
	//base case
	if(root==NULL){
		return;
	}

	//make queue add root
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size()!=0){

		//take front and pop
		BinaryTreeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();

		//print front 
		cout<<front->data<<" : ";

		//if left is there print it then push
		if(front->left!=NULL){
			cout<<"L"<<front->left->data;
			pendingNodes.push(front->left);
		}

		//if right is there print it thn oush
		if(front->right!=NULL){
			cout<<"R"<<front->right->data;
			pendingNodes.push(front->right);
		}
		cout<<endl;
	}
}


//================================================================
//take input level wise
BinaryTreeNode<int>* takeInputLevelWise(){
	//sample - 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1

	//take rootdata
	int rootData;
	cout<<"Enter root data: ";
	cin>>rootData;
	cout<<endl;

	//-1 means stop taking inputs
	if(rootData==-1){
		return NULL;
	}
	//make root node
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	//make queuue
	queue<BinaryTreeNode<int>*> pendingNodes;

	//push root into it
	pendingNodes.push(root);

	//to every pending node
	while(pendingNodes.size()!=0){
		//take front and remove from quueu
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		//take left data 
		int leftData;
		cout<<"Enter left node of "<<front->data<<"-";
		cin>>leftData;
		//if -1 then stop
		if(leftData!=-1){
			BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftData);
			front->left = leftChild;
			pendingNodes.push(leftChild);

		}
		
		//same wiht right
		int rightData;
		cout<<"Enter right node of "<<front->data<<"-";
		cin>>rightData;
		if(rightData!=-1){
			BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightData);
			front->right = rightChild;
			pendingNodes.push(rightChild);
		}
		cout<<endl;
		

	}
	return root; 

}

//================================================================
//print betweeb range k1 and k2
void printBetweenK1K2(BinaryTreeNode<int>* root,int k1,int k2 ){
	//base case
	if(root==NULL){
		return ;
	}
	//if root data lie in range , print it
	if(root->data >= k1 && root->data <=k2){
		cout<<root->data<<" ";
	}
	//if root data is greater than k1 than we need to go to left side
	if(root->data > k1){
		printBetweenK1K2(root->left,k1,k2);
	}
	if(root->data <= k2){
		printBetweenK1K2(root->right,k1,k2);
	}
}

//==================================================================
//these fucntions are used in a question to see if the tree is BST or not
//minimun of subtree we knoe is left left left..

//getting minimum data in a tree (we dont know it is aBST or not)
int minimum(BinaryTreeNode<int>* root){
	if(root==NULL){
		return INT_MAX;
	}

	int mini = root->data;
	if(root->left){
		mini = min(mini,minimum(root->left));
	}
	if(root->right){
		mini = min(mini,minimum(root->right));
	}
	return mini;
}

//getting maximum data in a tree
int maximum(BinaryTreeNode<int>* root){
	if(root==NULL){
		return INT_MIN;
	}

	int maxi = root->data;
	if(root->left){
		maxi = max(maxi,maximum(root->left));
	}
	if(root->right){
		maxi = max(maxi,maximum(root->right));
	}
	return maxi;
}

//return if given tree is bst or not
bool isBST(BinaryTreeNode<int>* root){
	if(root==NULL){
		return true;
	}

	//to be a BST=============
	//root data should be greater than maximum value in left subtree
	//root data should be small or eqyal to right minimum(subtree)
	//left subtree should be bst 
	//right subtree should be bst
	//==========================
	int leftMax = maximum(root->left);
	int rightMin = minimum(root->right);
	bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
	return output; 
	//this method is O(nh) time complexity , h= height
	//problem is similar to diamter , we first traverse for minimum in left subtree and then
	//traverse to check bst of left subtree , thus increasing time complexity
}


//================================================================
//improved version of isBST
//class that will contain , minimum value in a tree, maximum value in tree, isBST
class IsBSTReturn {
public:
	bool isBST;
	int minimum;
	int maximum;
};

//improved version of checking bst 
IsBSTReturn isBST2(BinaryTreeNode<int>* root){
	if (root==NULL){
		//make a object
		IsBSTReturn output;
		//set is bst to true
		output.isBST = true;
		//minimum value to INT_MAX
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}

	IsBSTReturn left = isBST2(root->left);
	IsBSTReturn right = isBST2(root->right);
	
	//minimum value in the full sub tree
	int minimum = min(left.minimum,min(right.minimum,root->data));

	//maximum value in the fulll sub tree
	int maximum = max(right.maximum,max(left.maximum,root->data));

	//check is bst with same 4 condition as previus part
	bool bstFinal = (root->data > left.maximum) && (root->data <= right.minimum) && left.isBST && right.isBST;
	IsBSTReturn output;
	//now return maximum value as the maximum value in the whole tree below that node thats why we took masimum of all
	output.maximum = maximum;
	output.minimum = minimum;
	output.isBST = bstFinal;
	return output;
	//time complexity = O(n)

}

//================================================================
//method 3 for isBST
bool isBST3(BinaryTreeNode<int>* root,int min = INT_MIN,int max = INT_MAX){
	if(root==NULL){
		return true;
	}
	if(root->data < min || root->data > max){
		return false;
	}
	bool isLeftOk = isBST3(root->left,min,root->data-1);
	bool isRightOk = isBST3(root->right,root->data,max);
	return isLeftOk&&isRightOk;
}


int main(){

	//==========================================================
		#ifndef ONLINE_JUDGE
			// for getting input from input.txt
			freopen("input2.txt", "r", stdin);
			// for writing output to output.txt
			freopen("output3.txt", "w", stdout);
		#endif
	//==========================================================
	//sample - 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
	//non bst - 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printTree(root);

	//print elements between range k1 and k2
	cout<<"Print elements between range(given) - ";
	printBetweenK1K2(root,2,6);
	cout<<endl;

	//check that given tree is bst or not
	cout<<"BST -T or F = "<<isBST(root)<<endl;

	//improved version of checking bst
	IsBSTReturn output = isBST2(root);
	cout<<"BST2 -T or F = "<<output.isBST<<endl;

	//method 3
	cout<<"BST3 -T or F = "<<isBST3(root)<<endl;



	///////BST.h testing
	cout<<"=========BST.h file testing area============"<<endl;
	BST b;
	b.insert(10);
	b.insert(5);
	b.insert(20);
	b.insert(7);
	b.insert(3);
	b.insert(15);
	b.printTree();

	b.deleteData(10);
	b.deleteData(100);//not working this time
	cout<<"--After deletion--"<<endl;
	b.printTree();

	//time complexities;
	/*
for searching element in bst , it is O(h), h is height of tree = since for each level we have to move either left or right so it do things for h times
for inserting in bst , it is O(h), same reason as for each level we eihter go to right or left
for deletion in bst, it ie O(h)

	*/

	/*
	points
balanced tree = for every node 
   |height(node's left side) - height(node's right side)| <= 1
balanced bst have height O(logn)
==O(logn) height means that height can be smaller or multiples of logn but can never be greater than logn(n,n^2,.....)
in balanced tree time comlexity for search insertion deletion is O(logn)
	
	//read about AVL trees

	*/
}  