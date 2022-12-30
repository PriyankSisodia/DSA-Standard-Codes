#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <utility> 
#include <cmath>
#include <set>

#define PI 3.14

using namespace std;

//global variables
int a;


//this inline will put just (a>b)?a:b in place of maxfun(x,y);
inline int maxfun(int a, int b){
	return (a>b)?a:b;
}

int main(){
	int i =65;
	char c = i;
	cout<<c<<endl; //ASCII value of 65

	//address typecasting
	cout<<"----Typecasting----"<<endl;
	int * p = &i;
	char * pc = (char*)p;

	cout<<"p - "<<p<<endl; //integer pointer prints adress
	cout<<"pc - "<<pc<<endl;//char pointer prints the valiue till it gets the /0 (end of string)
	cout<<"(*p) - "<<(*p)<<endl;//65
	cout<<"(*pc) - "<<(*pc)<<endl;//A
	cout<<"*(pc+1) - "<<*(pc+1)<<endl;//none
	cout<<"*(pc+2) - "<<*(pc+2)<<endl;//none
	cout<<"*(pc+3) - "<<*(pc+3)<<endl;//none
	//A is at *(pc) and not at *(pc+3) - (mostly)little endian(last byte is placed at 0th postion),big endian(last position)
	
	//dynamic memory allocation
	cout<<"----Dynamic Memory Allocation----"<<endl;

	int * k = new int; //memory allocated in heap(not in stack), it return the pointer
	int *arr = new int[40];
	/*
	arr[0]=99;
	arr[1]=100;
	cout<<arr[0]<<" "<<arr[1]<<endl;
	/* //we can take the size of array as input
	int n;
	cin>>n>>endl;
	int *arr2 = new int [n];
	*/
	*k = 79;
	cout<<"(*k) - "<<*k<<endl;
	cout<<"static Memory are auto release on the basis of scope of variable,while dynamic Memory needs manual release"<<endl;
	delete k; //delet the dynamic mem allocation in the heap not the pointer int stack 
	//memory at address k is deleted ,pointer k is not deletec
	delete [] arr;//deleting array

	//to allocate a 2d array in head memory
	/*
	int m,n
	cin>>m>>n;
	//array of m*n;
	//we can have array of different sizes of rows
	int** r = new int*[m];
	for(int i =0;i<m;i++){
		r[i] = new int[n];
		for(int j=0;j<n;j++){
			cin>>r[i][j];
		}
	}
	delete memory

	for(int i =0;i<m;i++){
	delete []r[i];
	}

	delete []r;
	*/
	cout<<"-------------Macros n global var--------"<<endl;
	cout<<"PI-"<<PI<<endl;
	// PI=PI*5; //non changeable
	cout<<"-------Inline------"<<endl;
	 int x=12;
	 int y=14;
	 int z = maxfun(x,y);
	 cout<<z<<endl;

}