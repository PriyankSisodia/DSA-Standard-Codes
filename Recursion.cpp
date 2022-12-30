#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int factorial(int n){
	//base case
	if(n==0){
		return 1;
	}

	//assume it is true for next small problem(for n-1)
	int smallOutput = factorial(n-1); 


	//do the rest work by using prev assumptiom
	int output = n* smallOutput;

	return output;
}
int fibbonaci(int n){
	//base case
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}

	//assumptions
	int smallOutput1 = fibbonaci(n-1);
	int smallOutput2 = fibbonaci(n-2);

	//return
	return smallOutput1+smallOutput2;
}


bool is_sorted(int arr[],int size){
	if(size=0||size==1){
		return true;
	}

	if(arr[0]>arr[1]){
		return false;
	}

	bool is_smallerSorted = is_sorted(arr+1,size-1);
	return is_smallerSorted;
	/*if(is_smallerSorted){
		return true;
	}
	else{
		return false;
	}*/
}

bool is_sorted2(int arr[],int size){
	if(size=0||size==1){
		return true;
	}
	bool is_smallerSorted = is_sorted2(arr+1,size-1);
	if(!is_smallerSorted){
		return false;
	}
	if(arr[0]>arr[1]){
		return false;
	}
	else{
		return true;
	}
}


int length(char str[]){
	if(str[0]=='\0'){
		return 0;
	}

	int smallStrLen = length(str+1);
	return 1+smallStrLen;
}

void removeAll(char s[],char x){
	if(s[0]=='\0'){
		return ;
	}

	if(s[0]!=x){
		removeAll(s+1,x);
	}
	else{
		int i =1;
		for(;s[i]!='\0';i++){
			s[i-1] = s[i];
		}
		s[i-1] =s[i];
		removeAll(s,x);
	}
	
}
int main(){

	#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input2.txt", "r", stdin);
		// for writing output to output.txt
		freopen("output3.txt", "w", stdout);
	#endif




	cout<<"To solve any recursion problem :"<<endl;
	cout<<"1- Provide the base case"<<endl;
	cout<<"2- Assume it is true for next small problem"<<endl;
	cout<<"3- Return value by previous asumption"<<endl;
	cout<<"we can intercgange step 2 and 3 on the basis of problem"<<endl;
	int n =6;
	cout<<"factorial of 6 = "<<factorial(n)<<endl;
	cout<<"fibbonaci at 6 = "<<fibbonaci(n)<<endl;
	cout<<"check if aarrray is sorted or not"<<endl;

	//getting length of a char array using recursiom
	char str[100];
	cin>>str;
	cout<<str<<endl;
	int l = length(str);
	cout<<"length -"<<l<<endl;


	//remove all occurance of char x in the input string
	char s[100];
	cin>>s;
	cout<<s<<endl;
	l = length(s);
	cout<<"length -"<<l<<endl;
	char c ='x'; //example
	removeAll(s,c);
	cout<<s<<endl;
	l = length(s);
	cout<<"length -"<<l<<endl;

}