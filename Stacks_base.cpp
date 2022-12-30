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
#include "StackUsingArrays.cpp"
#include "templates.cpp"
#include "StackUsingTemplates.cpp"
#include "StackUsingLL.cpp"
#include <stack>

//balanced parenthesis
bool balancedP(string s){

	stack <char > p;
	//for each char in the string
	for(int i =0;i<s.length();i++){
		if(s[i]=='{'||s[i]=='('||s[i]=='['){
			p.push(s[i]);
			continue;
		}

		else if(s[i]=='}'){
			{
				if(p.top()=='{'){
					p.pop();
					continue;
				}
				else{
					return false;
				}
			}
		}

		else if(s[i]==']'){
			if(p.top()=='['){
					p.pop();
					continue;
				}
				else{
					return false;
				}
		}

		else if(s[i]==')'){
			if(p.top()=='('){
					p.pop();
					continue;
				}
				else{
					return false;
				}
		}
	}
	
	if(p.size()==0){
		return true;
	}
	return false;

}



int main()
{

//==========================================================
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input2.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output3.txt", "w", stdout);
#endif
//==========================================================
	//Testing for classes.cpp
	// StackUsingArray s;
	// s.push(10);
	// s.push(20);
	// s.push(30);
	// s.push(40);
	// s.push(50);
	// s.push(60);
	// s.push(70);
	// s.push(80);
	// s.push(90);
	// cout<<s.size()<<endl;
	// // cout<<s.top()<<endl;
	// cout<<s.pop()<<endl;
	// cout<<s.top()<<endl;
	// cout<<s.isEmpty()<<endl;
	// cout<<s.size()<<endl;
	
	//Testing for templates.cpp
	Pair<int> p1; // here we say the typename is now int , so T is now int
	p1.setX(10);
	p1.setY(20);
	cout<<p1.getX()<<" "<<p1.getY()<<endl;

	Pair<double> p2;
	p2.setX(100.32562345678);
	p2.setY(9876.87);
	cout<<p2.getX()<<" "<<p2.getY()<<endl;

	//Pair<int,double> p3;
	//Pair<Pair<int,int>,int> p2; can be of diff DataType
	/*
	 for this case
	 Pair<int,int> p4;
	 p4.setX(15);
	 p4.setY(16);
	 p2.setY(10);
	 p2.setX(p4);
	 output pair will be - 15,16,10
	 p2.getY() -- 10
	 p2.getX() -- Pair
	 p2.getX().getX() -- 15

	*/

	//Testing StackUSingTemplates
	// /*
	StackUsingTemplates<char> s;
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);
	s.push(105);

	cout<<s.size()<<endl;
	cout<<s.top()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.top()<<endl;
	cout<<s.isEmpty()<<endl;
	// */

	StackUsingLL<int> p;

	p.push(101);
	p.push(102);
	p.push(103);
	p.push(104);
	p.push(105);
	cout<<p.getSize()<<endl;
	p.printStack();
	cout<<p.top()<<endl;
	cout<<p.pop()<<endl;
	cout<<p.top()<<endl;
	cout<<p.isEmpty()<<endl;

	//balanced parenthesus or not
	cout<<"balcned ornot parentheses"<<endl;
	string str;
	cin>>str;
	cout<<"Result - "<<balancedP(str);
/*
my approach for implement 3 stacks in a single array is to make stacks continuous in array
means, s1 starts from 0 , and stack 2 starts from where first stack end ,and third satack strats from seond end
pushing needs every stack to shift one forward and popping also

sort a stack using another stack only--
Create a temporary stack say tmpStack.
While input stack is NOT empty do this:
 Pop an element from input stack call it temp
 while temporary stack is NOT empty and top of temporary stack is greater than temp,
  pop from temporary stack and push it to the input stack
  push temp in temporary stack
The sorted numbers are in tmpStack


*/




}//ctrl+alt+f for auto formating