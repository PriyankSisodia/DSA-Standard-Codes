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

#include "Trees.h"
using namespace std;

// template<typename T>


//take tree input level wise
TreeNode<int>* takeInputLevelWise(){

	//make rootnode
	int rootData;
	cout<<"Enter root data : "<<endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	//queue that will contains nodes (not accessed)
	queue<TreeNode<int>*> pendingNodes;

	//push rootnode
	pendingNodes.push(root);

	//for every node in queue
	while(pendingNodes.size()!=0){

		//go to front node
		TreeNode<int> * front = pendingNodes.front();

		//remove from queue
		pendingNodes.pop();

		//take childs of front node 
		int numChild ;
		cout<<"Enter num of children of "<<front->data<<"- ";
		cin>>numChild;

		//take all child nodes
		for(int i =0;i<numChild;i++){
			int childData;
			cout<<"Enter "<<i<<"th child of "<<front->data<<": ";
			cin>>childData;

			//make child node(dynamically,because we want its access aftet the loop too)
			//if TreeNode<int>* child(childData);
			//the location will not be there after the loop 
			TreeNode<int>* child= new TreeNode<int> (childData);

			//connect to parent node(front)
			front->children.push_back(child);

			//push that child into the queue
			pendingNodes.push(child);
		}
	}
	cout<<endl;
	return root;
}

//take input depth wise
TreeNode<int>* takeInput(){

	int rootData;
	cout<<"Enter data : "<<endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	int n;
	cout<<"Enter num of children of "<<rootData<<"- "<<endl;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}




//print tree level wise
void printTree(TreeNode<int>* root){

	if(root==NULL){ //if we accidently pass null as root
		return ;
	}

	//queue that will have unaccesed nodes
	queue<TreeNode<int>*> pendingNodes;

	//push root into the queue
	pendingNodes.push(root);

	//for all elemennt of quueue
	while(pendingNodes.size()!=0){
		//take front node of the queue
		TreeNode<int>* front ;
		front = pendingNodes.front();

		//remove front from queue
		pendingNodes.pop();

		//print all child of front 
		cout<<"Childrens of "<<front->data<<" : ";
		int i=0;
		for(;i<front->children.size();i++){
			cout<<front->children[i]->data<<",";
			pendingNodes.push(front->children[i]);
		}
		cout<<endl;
	}
	
}

//return total number of nodes in the tree
int numNodes(TreeNode<int>* root){
	//when root moves to the end of the tree //base case for recursion
	if(root==NULL){
		return 0;
	}
	int ans =1;

	//recursion
	for(int i = 0;i<root->children.size();i++){
		ans += numNodes(root->children[i]);
	}
	return ans;
}

//height of the tree
int height(TreeNode<int>* root){

	//base case
	if(root==NULL){
		return 0;
	}
	
	//as we enter a node , this means it will contribute 1 into the height
	int h=1;

	int maxi=1;//since last node will not go into the loop so it shold return 1 , as heignt
	
	//for evey child count the height and return the maximum height 
	for(int i =0;i<root->children.size();i++){

		//h will return height belowthe child so add 1 to add current child hight
		h=height(root->children[i])+1;

		//we will return only the miximum heigt
		maxi = max(maxi,h);
	}

	return maxi;
}

//it will print all nodes at depth/level k
//root is at level 0
void printAtLevelK(TreeNode<int>* root,int k){


	if(root==NULL){
		return ;
	}

	//base case
	if(k==0){
		cout<<root->data<<",";
		return ;
	}
	
	else{
		//as we go deep dpeth increases , as we go down whne k becomes zero it wll print 
		for (int i = 0; i < root->children.size(); ++i)
		{
			printAtLevelK(root->children[i],k-1);
		}
	}

}


//count all leafnodes
int countLeafNodes(TreeNode<int>* root){
	
	//if num of childrens is zero
	if(root->children.size()==0){
		return 1; //leaf node
	}
	else{
		int count=0;
		for (int i = 0; i < root->children.size(); ++i)
		{
			
			count+=countLeafNodes(root->children[i]);
		}
		return count;
	}
}



//preorder traversal(first print parent then its child)
void preOrder(TreeNode<int>* root){
	if(root==NULL){
		return ;
	}
	cout<<root->data<<" "; //parent
	for (int i = 0; i < root->children.size(); ++i)
	{
		preOrder(root->children[i]); //child
	}
}

//postorder traversal(first child and then parent)
void postOrder(TreeNode<int>* root){
	if(root==NULL){
		return ;
	}
	for (int i = 0; i < root->children.size(); ++i)
	{
		postOrder(root->children[i]); //child
	}
	cout<<root->data<<" "; //parent
}



//delete a tree(by deleing all node starting from childrens)//similar to postorder methof
void deleteTree(TreeNode<int>* root){
	if(root==NULL){
		return ;
	}
	for (int i = 0; i < root->children.size(); ++i)
	{
		deleteTree(root->children[i]); //first delet all childrens
	}
	delete root;
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
//    --------  |       | |-------- |   /                    
//    |         |       | |         |  /    
//    |         |       | |         | /          
//    |----     |       | |         |/           
//    |         |       | |         | \        
//    |         |       | |         |  \     
//    |         |       | |         |   \     
// 	  |         |-------| |-------- |    \                 

	//make a root node with chikdrens
/*  TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);

	root->children.push_back(node1);
	root->children.push_back(node2);
*/
	//TreeNode<int>* root = takeInput();


	//testing trees = just copy paste it 
	//1 3 2 3 4 2 5 6 0 0 0 0 
	//1 3 2 3 4 2 5 6 0 1 7 0 0 1 8 0

	//take tree input level wise
	TreeNode<int>* root = takeInputLevelWise();

	//print tree
	printTree(root);
	cout<<endl;

	//print number of nodes in a tree
	cout<<"The number of nodes in the tree -"<<numNodes(root)<<endl;
	
	//print height of the tree
	cout<<"Height of the tree -"<<height(root)<<endl;
	
	//we will print all node at each level
	int k = height(root);
	for(int i =0;i<k;i++){
		cout<<"All nodes at level/depth ("<<i<<") = ";
		printAtLevelK(root,i);
		cout<<endl;
		cout<<"---"<<endl;
	}

	//count number of leaf nodes
	cout<<"NUmber of leaf nodes in the tree - "<<countLeafNodes(root)<<endl;

	//print preorder traversal
	cout<<"Print in preorder = ";
	preOrder(root);
	cout<<endl;

	//print postorder traversal
	cout<<"Print in postorder = ";
	postOrder(root);
	cout<<endl;

	//Delete the tree
	cout<<"deleting tree"<<endl;
	deleteTree(root);

	//deleting tree using destructor
	//delete root;

	/*
Trees imp notes:
- types of trees - binary tree, BST,AVL,Red black tree,Expression tree,B tree, B+ trees



	*/
}	
