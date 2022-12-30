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

//============================================
int lcs(string s, string t){
	//base //if one of the string gets empty
	if(s.size() == 0 || t.size() == 0){
		return 0;
	}

	//recursion //if first char of both matchse , means that char is in lcs
	if(s[0] == t[0]){
		return 1 + lcs(s.substr(1),t.substr(1)); //now return 1 + lcs of remaining strings
	}
	else{
		//if first char are both diff then 3 cases
		int a = lcs(s.substr(1), t); //discarding first char of s
		int b = lcs(s, t.substr(1)); //disc first char of t
		int c = lcs(s.substr(1), t.substr(1)); //disc first char of both s and t //this can be avaidable

		//small calc
		return max(a,max(b,c));
	}
	//O(3^n)
	//max m*n unique calls (m , n are legths)
}

//memoization
//meaning , ans[i][j] = length of lcs of S(length i) and T(length j)
//matrix will be m+1 * n+1 ,bcs ans[m][n] gives lcs of S(length m) and T(lentgh n)
int lcs_better(string s, string t, int ** ans){ //inti with -1
	//base
	if(s.size() ==0|| t.size() ==0){
		return 0;
	}
	int m = s.size();
	int n = t.size();
	if(ans[m][n] != -1){
		return ans[m][n];
	}
	if(s[0] == t[0]){
		ans[m-1][n-1] = lcs_better(s.substr(1),t.substr(1),ans);
		ans[m][n] = 1 + ans[m-1][n-1];
	}
	else{
		ans[m][n-1]=lcs_better(s, t.substr(1),ans);
		ans[m-1][n] = lcs_better(s.substr(1),t,ans);
		//we skipped the third call //doesnt matter bcs it wil cover in these two cses
		ans[m][n] = max(ans[m][n-1],ans[m-1][n]); 
	}
	return ans[m][n]; 

	//tc = O(m*n)
}
int lcs_better(string s, string t){
	int m = s.size();
	int n = t.size();
	int ** ans = new int*[m+1];
	for (int i = 0; i <= m; ++i)
	{
		ans[i] = new int[n+1];
		for(int j =0 ; j<=n;j++){
			ans[i][j] = -1;
		}
	}
	return lcs_better(s,t,ans);
}


//understand with using taking example of xyz,zxy
int lcs_DP(string s, string t){
	int m = s.size();
	int n = t.size();
	int ** ans = new int*[m+1];
	for (int i = 0; i <= m; ++i)
	{
		ans[i] = new int[n+1];
	}

	//first row to 0 all
	for(int i =0 ;i<n+1;i++){
		ans[0][i] = 0;
	}

	//fisrt colum to all 0
	for(int j =0 ;j<m+1;j++){
		ans[j][0] = 0;
	}

	//dependencies from left to right in each row

	for(int i =1 ;i<=m ;i++){
		for(int j =1;j<=n;j++){

			//at thi point length of s is i, and legth of t is j (lengths are from backside)
			
			//we will compare characters of s and t at position (m-i),(n-j) (try calcualtef from example)
			if(s[m-i] == t[n-j]){ //taking first character fromm last subsstring of s having length i, similaryl j
				ans[i][j] = 1 + ans[i-1][j-1];
			}

			else{
				ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
			}
		}
	}
	return ans[m][n];

	//tc = O(mn)
	//sc = O(mn)
}

//=============================================
//using recursion
int editDistance(string s, string t) {
        // Code here
        if(s.length() == 0||t.length() == 0){
            return s.length() + t.length();
        }
        
        //first char match
        if(s[0] == t[0]){
            return editDistance(s.substr(1),t.substr(1));
        }
        
        //first char donnot match
        else{
            
            //add
            int a = editDistance(s,s[0]+t) +1; //editDistance(s.substr(1),t) +1
            //remove
            int b = editDistance(s,t.substr(1)) +1; //editDistance(s,t.substr(1)) +1
            
            //replace
            int c = editDistance(s,s[0]+t.substr(1)) +1; //editDistance(s.substr(1),t.substr(1)) +1
            return min(a,min(b,c));
        }
        
    }

//Using DP
    int editDistance_DP(string s, string t) {
        // Code here
        int m= s.length();
        int n =t.length();
        int **ans = new int*[m+1];
        for(int i= 0;i<m+1;i++){
            ans[i] = new int[n+1];
        }
        
        //first row
        for(int i =0 ;i <n+1;i++){
            ans[0][i] = i;
        }
        //first coliumn
        for(int i =0 ;i <m+1;i++){
            ans[i][0] = i;
        }
        
        //moving from left to right
        for(int i =1;i<m+1;i++){
            for(int j =1;j<n+1;j++){
                if(s[m-i] == t[n-j]){
                    ans[i][j] = ans[i-1][j-1];
                }
                
                else{
                    ans[i][j] = min(ans[i-1][j],min(ans[i][j-1],ans[i-1][j-1])) +1;
                }
            }
        }
        return ans[m][n];
    }



//===============================================

//need review and comments above this line
    //using rcurso
int knapSack(int **weights, int* values, int n, int maxWeight) 
{ 
   // Your code here
   if(n == 0 || maxWeight ==0){
       return 0;
   }

   //if we can not include it int he bag
   if(weights[0] > maxWeight){
   		return knapSack(weights +1, values +1,  n-1, maxWeight);
   }
   //rexruson 

   //first element included
   int x = knapSack(weights +1, values +1 , n-1, maxWeight -weight[0])  + values[0];
   //first elemtn not included
   int y = knapSack(weights +1, values +1,  n-1, maxWeight);
   
   return max(x,y);
}
 int knapSack_better(){

 }

 int knapSack_DP(int W, int wt[], int val[], int n){

 	//initialize a 2d dp array
 	int ** ans = new int*[n+1];
	for (int i = 0; i <= n; ++i)
	{
		ans[i] = new int[W+1];
		for(int j =0 ; j<=W;j++){
			ans[i][j] = -1;
		}
	}

	//initialization of dp array using some base conditions
	for(int i =0;i<=n;i++){
	    for(int j = 0;j<=W;j++){
	        if(i ==0|| j==0){ //base conditions
	            ans[i][j] = 0;
	        }
	    }
	}

	//traversing all left columns and rows
	for(int i =1;i<=n;i++){
	    for(int j =1 ;j<=W;j++){

	    	//if value is already filled , then return answer
    	    if(ans[n][W] !=-1){ 
    	        return ans[n][W];
    	    }

    	    //if the weight of last elemtn is smaller tham max weight allowed
    	    if(wt[i-1] <= j){

    	    	//we have choice , to select the elment or not
    	    	//so we toook maxi value of both choices
    	        ans[i][j] = max(val[i-1] + ans[i-1][j-wt[i-1]],ans[i-1][j]);
    	    }

    	    //if the weight of last elent is greater than aloowed wight 
    	    else{

    	    	//we will not select this elemnt 
    	    	//so the answer will be same as it is not selected whic is i-1,j
    	    	//i means number of number of element in array
    	        ans[i][j] = ans[i-1][j];
    	    }
	    }
	}
	return ans[n][W];
 }

//=======================min_num_of coins req to get desired ouput==========
//refer aditya verma video
 int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
    if(n==1){ //made mistake heer
        
        if(amount == coins[0]){
            return 1;
        }
        else if(amount==0){
            return 0;
        }
    }
    //init first row
    for(int i=0;i<=amount;i++){
        dp[0][i] = INT_MAX-1;
    }
    //init firsy column
    for(int i =1;i<=n;i++){
        dp[i][0] = 0;
    }
    //init second row
    for(int i =1;i<=amount;i++){
        if(i%coins[0] == 0){
            dp[1][i] = i/coins[0];
        }
        else{
            dp[1][i] = INT_MAX-1;
        }
    }
    //others
    for(int i =2;i<=n;i++){
        for(int j =1;j<=amount;j++){
            if(coins[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
            }
        }
    }
    
    return dp[n][amount] == INT_MAX-1? -1: dp[n][amount];
}



//===============================================
//**DP 

/*
dp is bottom up approach , we ned to find those positions in matrixes thar are dependen on other positions 
we need to fill those dependencises first
*/


int main(){

//==========================================================
		#ifndef ONLINE_JUDGE
			// for getting input from input.txt
			freopen("input2.txt", "r", stdin);
			// for writing output to output.txt
			freopen("output3.txt", "w", stdout);
		#endif
//==========================================================

//Q 6 LCS longest common subsequence
	string s,t;
	cin>>s>>t;
	cout<<"Brute force"<<endl;
	cout<<lcs(s,t)<<endl; //brute forcw , will not work wirh big legths
	cout<<"Memoization"<<endl;
	cout<<lcs_better(s,t)<<endl;
	cout<<"DP"<<endl; 
	cout<<lcs_DP(s,t)<<endl; 

	//ques -edit distance - min number of operstions for making a string s into t 
	//operations - add a char, delete a char, update a char.
}