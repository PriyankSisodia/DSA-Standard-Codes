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
#include <map>
// #define int cpp_int
// #include <boost/multiprecision/cpp_int.hpp>
// using boost::multiprecision::cpp_int;

using namespace std;

int function(int input, int input2, int **input3){
    // unordered_map<int,int> vis;
    int vis[10002];
    for(int i =0;i<10002;i++){
        vis[i] =-1;
    }
    for(int i =0;i<input2;i++){
        for(int j =input3[i][0];i<input3[i][0] + input3[i][1];j++){
            vis[j] = i;
        }
    }
    set<int> fin;
    for(auto i: vis){
        fin.insert(i.second);
    }
    return fin.size();
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

	
   int **arr;
   int input2 = 
   arr = new int*[5];
   for(int i =0;i<5;i++){
    arr[i] = new int[2];
   }


}

