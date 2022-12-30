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

#include<unordered_map>

using namespace std;


vector<int> removeDuplicates(int* a, int size){
	vector<int> output;
	unordered_map<int,bool> seen;
	for (int i = 0; i < size; ++i)
	{
		if(seen.count(a[i])>0){//if key is already present 
			continue; //do not add to the vector
		}
		seen[a[i]] = true;//if key is first time , then add 
		output.push_back(a[i]);
	}
	return output;
	//TC = O(1);
}


int main(){

///////////////////                ////////////
///////////////////BASIC OPERATIONS////////////
/*
	//Umap with key as string and value as int
	unordered_map<string, int> ourMap;

	//insert
	pair<string,int> p("abc",1);
	ourMap.insert(p);
	ourMap["def"] = 2;

	//access
	cout<<ourMap["abc"]<<endl;
	cout<<ourMap.at("abc")<<endl;
	// cout<<ourMap.at("phi")<<endl //this give error
	cout<<ourMap["phi"]<<endl;//no error , it will add a new key "phi with value 0 int map"
	cout<<ourMap.at("phi")<<endl;

	//check presense without adding or withour eroor
	if(ourMap.count("phi")>0){//eihter 0 or 1
		cout<<"phi is present"<<endl;
	}
	cout<<"size-"<<ourMap.size()<<endl;

	//erase
	ourMap.erase("phi");
	if(ourMap.count("phi")>0){//eihter 0 or 1
		cout<<"phi is present"<<endl;
	}
	cout<<"size-"<<ourMap.size()<<endl;
*/
	//iterators in unordered_map
	unordered_map<string,int> ourMap2;
	ourMap2["abc"] =1;
	ourMap2["abc1"] =2;
	ourMap2["abc2"] =3;
	ourMap2["abc3"] =4;
	ourMap2["abc4"] =5;
	ourMap2["abc5"] =6;
	//this will not print sorted or in order
	//make iterator stating at begin
	unordered_map<string,int>::iterator it = ourMap2.begin();
	while(it!= ourMap2.end()){//ourMap2.end() is lccation just next to the last element, not the last elemnt
		cout << "Key: "<<it->first<<" Value: "<<it->second<<endl;
		it++;
	}//similar we have iterators of vectors(value = *it)

	//find
	//find will return iterator of key
	unordered_map<string,int>::iterator it2 = ourMap2.find("abc");
	// ourMap2.erase(it2);//erase a key value pair
	ourMap2.erase(it2,it2+4); //dleet continuous pairs

////////////////////////////////////////////////
///////////////questions/////////////////////////////////
	//remove dubplicates
	int a[] ={1,2,3,3,4,1,7,7,6,8,7,9,3,1,0};
	vector<int> output = removeDuplicates(a,15);
	cout<<"----removeDuplicates------"<<endl;
	for(auto i: output){
		cout<<i<<" ";
	}

}