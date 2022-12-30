#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <utility> 
#include <cmath>
#include <set>
#include <climits>

using namespace std;
template <typename T>
class TreeNode
{
public:
	T data;
	vector<TreeNode<T>*> children; //vector contains all adrees of child (i.e add of next treenode with datatype T)

	TreeNode(T data){
		this->data = data;
	}
	~TreeNode(){ //destructor
		for(int i =0;i<children.size();i++){
			delete children[i];
		}
	}
	
};