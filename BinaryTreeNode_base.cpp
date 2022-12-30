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

#include "BinaryTreeNode.h"

using namespace std;

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

//take input like DFS
BinaryTreeNode<int>* takeInput(){
	//sample input 1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 8 -1 -1 -1
	int rootData;
	cout<<"Enter data"<<endl;
	cin>>rootData;
	if(rootData==-1){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();

	root->left =leftChild;
	root->right = rightChild;
	return root;
}

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





//return number of nodes
int numNodes(BinaryTreeNode<int>* root){

	//base case
	if(root==NULL){
		return 0;
	}

	//recursion case
	//1 is for current node
	int ans =1;

	//add nodes in left
	ans += numNodes(root->left);

	//add nodes in right
	ans += numNodes(root->right);

	return ans;

	//return 1+numNodes(root->left)+numNodes(root->right);
}


//inorder traversal == first left child, parent, right child
void inOrder(BinaryTreeNode<int>* root){
	if(root==NULL){
		return ;
	}

	//first left
	inOrder(root->left);

	//then parent
	cout<< root->data<<"-";

	//then right child
	inOrder(root->right);
}

//store in order in a vector
// void inOrderVector(Node* root,vector<int>& v) //address of vector is passed as we will update into it
// {
//     if(root==NULL)
//         return ;
//     inOrderVector(root->left,v);
//     v.push_back(root->data);
//     inOrderVector(root->right,v);
// }


//need to remember (try to visualize this) we cam also try this with preorder and postorder
vector<int> inOrderWithoutRecursion(BinaryTreeNode<int> * root){

	stack<BinaryTreeNode<int>*> s;  //make stack to store all the nodes
	
	//set current pointer to root
	BinaryTreeNode<int>* current = root;

	//save the in order of tree
	vector<int> ans;
	

	while(current!=NULL || s.empty()==false){

		//go to the nodes 
		while(current!=NULL){
			s.push(current);
			current = current->left;
		}

		current = s.top();
		s.pop();

		ans.push_back(current->data);

		current = current->right;
	}

	return ans;

	//similar approach for preorder withour recc= https://practice.geeksforgeeks.org/problems/preorder-traversal/1#
}



//===============================================================

//build a tree using in order and pre order 
BinaryTreeNode<int>* buildTreeHelper(int* in,int* pre,int inS,int inE, int preS, int preE){
	if(inS>inE){
		return NULL;
	}

	//root value is first value of preorder
	int rootData = pre[preS];

	int rootIndex = -1;

	//find the index of root in the inorder
	for (int i = inS; i <=inE; ++i)
	{
		if(in[i]==rootData){
			rootIndex = i;
			break;
		}
	}

	//left in start, left in end, left pre start, left pre end; indexes
	int linS = inS;
	int linE = rootIndex-1;
	int lpreS = preS+1;
	int lpreE = linE-linS +lpreS;

	//right pre start , right pre end, right in start, right in end; index
	int rpreS = lpreE+1;
	int rpreE =preE;
	int rinS = rootIndex+1;
	int rinE = inE;

	//make a root node with the root data we found out
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	//recursion in left
	root->left =buildTreeHelper(in,pre,linS,linE,lpreS,lpreE);
	//recursion in right
	root->right =buildTreeHelper(in,pre,rinS,rinE,rpreS,rpreE);
	//return the root node
	return root;
}


BinaryTreeNode<int>* BuildTreeUsingPreOrderAndInOrder(int* in,int* pre, int size){

	return buildTreeHelper(in,pre,0,size-1,0,size-1);


}
//==============================================================



//heaight of binary tree
int height(BinaryTreeNode<int>* root){
	if(root==NULL){
		return 0;
	}

	//retrun maximu of left and riht value witb 1+
	return 1+ max(height(root->left),height(root->right));
}

//diameter of binary tree
int diameter(BinaryTreeNode <int>* root){
	//base case 
	if(root == NULL){
		return 0;
	}

	//there are three possible vaslue of the diameter of the bianry tree

	//the sum of height of left tree and right tree + current node(so +1)
	int option1 = height(root->left) + height(root->right)+1;
	
	//if the right node do not have childrens , this means left child have diamter
	int option2 = diameter(root->left);

	//if the left node do not have childrens , this means right child have diamter
	int option3 = diameter(root->right);

	//will return the maximum of the three
	return max(option3,max(option2,option1));

}




//better approach for diameter
pair <int,int> heightDiameter(BinaryTreeNode<int>* root){
	//diamtee is the heighest number of nodes between two nodes ,not the edges between two nodes
	
	//base case
	if(root==NULL){//means we are at the end of bt
		//if null ,return pair of zeroes
		pair<int,int> p;
		p.first =0;
		p.second =0;
		return p;
	}

	//recursion
	//left ans will contain left height and diameter in left side
	pair<int,int> leftAns = heightDiameter(root->left);

	//similaryly right side
	pair<int,int> rightAns = heightDiameter(root->right);

	int ld = leftAns.second;//left diamter
	int lh = leftAns.first;//left height
	int rd = rightAns.second;//right diameter
	int rh = rightAns.first;//right height

	//hypothesis for recursion(work on small problem)
	int height = 1+ max(lh,rh);//height passed to upper node is max(lh,rh)+1
	int diameter = max(lh+rh+1,max(ld,rd)); //diamter is maximum of all(leftheight+right height+1,left dia,right dia)

	pair<int,int> p; //return pair contains hieght and diamter upto current node
	p.second = diameter;
	p.first = height;
	return p;

	//time compleixity =O(n);
	//this function is very important because it have a new concept of passing 2 value for the prevview node
	//example - =https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/

}


//===========================right view of BT
//print rieght view of binary tree
void printRightView(BinaryTreeNode<int>* root){
	//make queue to store pending nodes//we will traverse level wise in this ques
	queue<BinaryTreeNode<int>*> pendingNodes;
   if(root==NULL){
       return ;
   }

   //push root to the quueueu
   pendingNodes.push(root);
   vector<int> ans;

   //while queue is not empty
   while(pendingNodes.size()!=0){
        
        //size = means the number of nodes at a working level
   		//last node of each level is included in the right view of the tree
        int size = pendingNodes.size();
        int i =0;
        //count till we get i = size ,means we get the last node
        while((i++)<size){
            BinaryTreeNode<int>* front = pendingNodes.front();
            pendingNodes.pop();
            if(i==size){
            	//if the last nodeis there ,print it or save it ina vectore
            	 cout<<front->data<<"-";
            	 //save all last node of thelevel ib the vector 
                ans.push_back(front->data);
            }
           	//if the left node is not null ,push it into the pedning node
            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
            //if right node is not null push iot ninto the pending node;
            if(front->right!=NULL){
                pendingNodes.push(front->right);
            }
        }
    //similarly print left view of bt
        
   }
}

//========================================================================================
//get root to node path
vector<int>* getRootToNodePath(BinaryTreeNode<int>* root,int data){
	// cout<<"in"<<root->data;

	//base case if root goes to the end point
	if(root==NULL){
		return NULL;
	}

	//base case if the data is found
	if(root->data == data){

		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}

	//recursion in left subtree
	vector<int>* leftOutput = getRootToNodePath(root->left,data);

	//if left output is NULL(empty vector) means element not found in that subbtree
	//if left output is not NULL,then we found the path 
	if(leftOutput!=NULL){
		leftOutput->push_back(root->data);
		return leftOutput;
	}

	//recursion in right subtree
	vector<int>* rightOutput = getRootToNodePath(root->right,data);

	if(rightOutput!=NULL){
		rightOutput->push_back(root->data);
		return rightOutput;
		// cout<<"rr";
	}
	else return NULL;

}
//=========================================================
//Lowest common ancestor of two nodes (n1,n2)
Node* lca(Node* root ,int n1 ,int n2 )
    {
    	//if root is null return NULL
       if(root ==NULL){
           return NULL;
       }
       
       //if root data matches to n1 or n2
       if(root->data == n1 || root->data == n2){

       	//then root node will be the lca
           return root;
       }
       
       Node* left_node = NULL;
       Node* right_node = NULL;
       
       //check for its left and right node
       left_node = lca(root->left, n1, n2);
       right_node = lca(root->right, n1, n2);
       
       //if both left node and right node are not null
       //means both have adress of two nodes n1 , n2
       if(left_node && right_node){
           
           //then root will be lca
           return root;
       }
       
       //if left node is null, lca will be rightnode
       //if right node is null , lca will be leftnode
       //also if both are null, return NULL as lca 
       return (left_node == NULL)? right_node : left_node;
    }





//===========================================================
int main(){

	//==========================================================
	#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input2.txt", "r", stdin);
		// for writing output to output.txt
		freopen("output3.txt", "w", stdout);
	#endif
	//==========================================================

	//sample - 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    //sample - 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1






	 // sample input
	// BinaryTreeNode<int>* root =new BinaryTreeNode<int> (1);
	// BinaryTreeNode<int>* node1 =new BinaryTreeNode<int> (2);
	// BinaryTreeNode<int>* node2 =new BinaryTreeNode<int> (3);
	// root->left = node1;
	// root->right = node2;


	//take input way 1
	// BinaryTreeNode<int>* root = takeInput();


	//take input level wise
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printTree(root); //level wise print


	//finde number of nodes
	 cout<<"Number of nodes - "<<numNodes(root)<<endl;


	 //printing methods(node = parent=root)
	 //Level order = print nodes level wise
	 //pre order = node - left - right
	 //post order = left -right - node
	 //in order = left - node - right
	 inOrder(root);
 
	 //build the tree using inorder and pre order 
	 int in[] = {4,2,5,1,8,6,9,3,7};
	 int pre[] = {1,2,4,5,3,6,8,9,7};
	 cout<<endl;
	 cout<<"Building BuildTreeUsingPreOrderAndInOrder"<<endl;
	 BinaryTreeNode<int> *root2 = BuildTreeUsingPreOrderAndInOrder(in,pre,9);
	 printTree(root2);
	 cout<<endl;
	 inOrder(root2);
	 cout<<endl;

	 //diameter of binary tree(maximum distance between two nodes ina BT)
	 // cout<<"Diameter of the tree-"<<diameter(root)<<endl;//not working

	 cout<<"height ="<<height(root)<<endl;
	 //print right view of the tree
	 cout<<"Print right view of binary tree"<<endl;
	 printRightView(root);
	 cout<<endl;


	 cout<<"------Root------"<<endl;
	 printTree(root);
	 cout<<endl;
	 cout<<"Diameter of the tree-"<<heightDiameter(root).second<<endl;
	 cout<<"Height of the tree-"<<heightDiameter(root).first<<endl;

	// delete root;
	delete root2;


	//points
	/*
	two trees are identical if inorder and (postorder or preorder) are same for both trees
	*/

	//testing get root to node path
	// BinaryTreeNode<int>* root = takeInputLevelWise();

	cout<<"get path from- "<<root->data<<endl;

	vector<int>* output = getRootToNodePath(root,8);
	// cout<<output->size();
	for (int i = 0; i < output->size(); ++i)
	{
		cout<<output->at(i)<<endl;
	}
	delete output;
	//


	//questions
	//print vertical order of tree (try all variants of this question)
	//       method one - O(n^2) using min max horizontal distance
	//       method 2  -O(nlogn) using queue + map (horiznotal + vetical order)  https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1#
	//       method 3 - O(n) 
	//print top view of BT
	// using queue and maps - https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#
	//spiral traversal - https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

}	