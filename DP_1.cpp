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
int fibbonaci(int n ){
	if(n<=1){
		return n;
	}

	int a = fibbonaci(n-1);
	int b = fibbonaci(n-2);
	return a+b;
	//time complezity = 2^n , this is worst time complexit
	//problem = we are claculation the fibonaci of a number multiple time 
	//	like if n= 6, (make tree on paper) we are cacluating fabinoci of 3 3 times , so wastage
}

//======================
int fibo_better(int n, int *ans){ //array passed
	if(n<=1){
		return n;
	}

	//check if it is already calculated ornot
	if(ans[n-1] == 0){
		ans[n-1] = fibo_better(n-1, ans); //recursion if not calculated and save inarray
	}
	if(ans[n-2] == 0){
		ans[n-2] = fibo_better(n-2, ans);
	}

	ans[n] = ans[n-1] + ans[n-2];
	return ans[n];

	//time complesxity = O(n) total n+1 calls 
	//saving values for further use = memoization technique (top down appraoch)
	//dynamic programming = bottom up approach
}

//helper function because we dont want user to pass array
int fibo_better(int n){
	//array to store fibo of each number
	int *ans = new int[n+1];
	for (int i = 0; i < n; ++i)
	{
		ans[i] = 0;
	}
	return fibo_better(n,ans);
}
//========================
int fibo_DP(int n){

	//bottom up approach O(n) 
	int *ans = new int[n+1];
	ans[0] = 0;
	ans[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		ans[i] = ans[i-1] +ans[i-2];
	}
	return ans[n];
}
//=========================
//using recursion 
int minStepFromNto1(int n){
	if(n==1){
		return 0;
	}

	int x = minStepFromNto1(n-1);

	//we declare it to max beacuse in case the number is not deiv by 2 or 3 , then y and z will have garbage
	int y = INT_MAX, z =INT_MAX; 
	if(n%2 == 0){
		y = minStepFromNto1(n/2);
	}
	if(n%3 == 0){
		z = minStepFromNto1(n/3);
	}

	return min(x,min(y,z)) + 1;

	//time complezity = O(3^n ) worst case cpmpleity
	//problem = overlapping problems(calculations multiple times of single elemnt)
	//total unique calls = n calls , from n to 1;

}

int minStepFromNto1_Better(int n, int *ans){
	//ans array initialized with -1
	//ans[i] = minimum steps from i to 1
	if(n==1){
		ans[n] = 0;
		return 0;
	}

	if(ans[n-1] == -1){
		ans[n-1] = minStepFromNto1_Better(n-1,ans);
	}

	int y=INT_MAX, z= INT_MAX;//in case n is not a multiple of 2 or 3
	if(n%2 == 0){
		if(ans[n/2] == -1){
			ans[n/2] = minStepFromNto1_Better(n/2,ans);
		}
		y = ans[n/2];
	}
	if(n%3 == 0){
		if(ans[n/3] == -1){
			ans[n/3] = minStepFromNto1_Better(n/3,ans);
		}
		z = ans[n/3];
	}

	//we ditnt take min of all thhree, beacuse for n=4 , n/3 is maningless
	ans[n] = min(ans[n-1],min(y,z))+1; //+1 is of one extra step at acurrent level
	// cout<<ans[n]<<" ";
	return ans[n];

	//space ans time comp = O(n);
}

int minStepFromNto1_Better(int n ){
	int * ans = new int[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		ans[i] =-1;
	}
	return minStepFromNto1_Better(n,ans);
}

//=========================
int minStepFromNto1_DP(int n){

	int * ans  = new int[n+1];
	for (int i = 0; i <= n; ++i)
	{
		ans[i] = -1;
	}
	
	if(n==1){
		return 0;
	}
	ans[0] =0;
	ans[1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		int a = ans[i-1];
		int y = INT_MAX;
		int z = INT_MAX;

		if(i%2 == 0){
			y = ans[i/2];
		}

		if(i%3 == 0){
			z = ans[i/3];
		}

		ans[i] = min(a,min(y,z)) + 1;
	}
	return ans[n];
}

//=========================
//question 2 
//using recursion(brute force)
int minNumber(int n){

	//means n is perfect square
	if(sqrt(n) - floor(sqrt(n)) == 0){
		return 1;
	}
	if(n <= 3){
		return n;
	}

	//maximum answer = 1^2 + 1^2 ....
	int res  = n;
	for (int i = 1; i <= n; ++i)
	{
		int temp = i*i;
		if(temp > n){
			break;
		}
		else{ 
			res = min(res, 1+ minNumber(n - temp));
		}
	}
	return res;
}

//using memoization
int minNumber_better(int n, int *arr){

	//means n is perfect square
	arr[0]=0;
	if(sqrt(n) - floor(sqrt(n)) == 0){
		arr[n] = 1;
		return 1;
	}
	for(int i =0;i<=3;i++){
		arr[i] = i;
	}
	if(n<=3){
		return arr[n];
	}
	//maximum answer = 1^2 + 1^2 ....
	int res  = n;

	//if the andwer is already there ,just return it
	if(arr[n] != -1){
		return arr[n];
	}

	for (int i = 1; i < n; ++i)
	{
		
		int temp = i*i;
		if(temp > n){
			break;
		}
		else{
			res = min(res, 1+ minNumber_better(n-temp,arr));
			arr[n] = res;
			// cout<<"-"<<res<<"-";
		}
	}
	return arr[n];

}
int minNumber_better(int n){
	int * arr = new int[n+1];
	for(int i =0 ;i<=n;i++){
		arr[i] =-1;
	}
	return minNumber_better(n,arr);
}

//https://www.geeksforgeeks.org/minimum-number-of-squares-whose-sum-equals-to-given-number-n/
//using dp
int minNumber_DP(int n){
	int * dp = new int[n+1];

	//setting 0 to 3 dp 
	for(int i =0 ;i<=3;i++){
		dp[i] = i;
	}

	//if squar root then 1
	if(sqrt(n) - floor(sqrt(n)) == 0){
		dp[n] = 1;
		return dp[n];
	}

	//else
	for(int i =4 ;i<=n;i++){
		dp[i] = i; //maximum possible for i is i
		if(sqrt(i) - floor(sqrt(i)) == 0){
			dp[i] =1;
			continue;
		}

		//if not the suqreroot
		for(int j =1; i-(j*j) >= 0 ;j++){

			//iterate of all possible values of differnce
			dp[i] = min(dp[i],1 + dp[i - (j*j)]);
		}
	}
	return dp[n];	
}
//=====================================================
//q 3
int max_balanced(int h){
	if(h <= 1){
		return 1;
	}
	int mod = (int)(pow(10,9)) + 7;
	int x = max_balanced(h-1);
	int y = max_balanced(h-2);
	//for height h, max height of left and right can be ((h-1,h-1)) or (h-1,h-2) or (h-2,h-1)
	//because diff between left and rightshould be <=1

	//adding all 3 cases , ex - for (h-1,h-1) mmax subtree will be = x*x
	// int ans = x*x + x*y + x*y;
	int temp1 = (int)(((long)(x)*x) % mod);
	int temp2 = (int)((2* (long)(x)*y) % mod);
	int ans = (temp1 + temp2) % mod;
	
	return ans;
}




//====================================
//questoin 4
//helper
int minCostPath(int **input, int m, int n, int i , int j){
	//base case
	if(i == m-1 && j == n-1){  //if we reached at the end(bottom right)
		return input[i][j];
	}
	if(i >= m || j >= n){//if goes out of range
		return INT_MAX;
	}
	//recursion 
	int x = minCostPath(input, m, n, i, j+1); //right
	int y = minCostPath(input, m, n, i+1, j+1);//diagonal
	int z = minCostPath(input, m, n, i+1, j);//down

	//small calculitpn
	int ans =min(x,min(y,z)) + input[i][j];
	return   ans;//input[i][j] is cost of current position
	//time = O(3^n)
	//total unique calls = m*n //so we need 2d array for memoization
}

int minCostPath(int **input, int m, int n){
	return minCostPath(input, m, n, 0, 0) ; //starting index i,j
}
//------------------------------------------------------------------------------

//memoization
int minCostPath_better(int **input, int m, int n, int i , int j, int **ans)//intitalize with -1
{ 
	//base case
	if(i == m-1 && j == n-1){  //if we reached at the end(bottom right)
		return input[i][j];
	}
	if(i >= m || j >= n){//if goes out of range
		return INT_MAX;
	}

	//first part of memoisz , is to check if its value is alreadyr present or not
	if(ans[i][j] != -1){
		return ans[i][j];
	}

	//recursion ,wheneever there is recurion in memoization save values 
	int x = minCostPath_better(input, m, n, i+1, j, ans);
	//i+1 can be out of range so in case of out of range we do not save it
	if(x < INT_MAX){
		ans[i+1][j] = x;
	}

	//if i or j goes out of range then we dont ned tp save anything
	int y = minCostPath_better(input, m, n, i+1, j+1, ans);
	if(y < INT_MAX){
		ans[i+1][j+1] = y;
	}
	int z = minCostPath_better(input, m, n, i, j+1, ans);
	if(z < INT_MAX){
		ans[i][j+1] = z;
	}

	ans[i][j] = min(x,min(y,z)) + input[i][j];
	return ans[i][j];

	//time compleit = O(m*n)
}

int minCostPath_better(int **input, int m , int n){
	int **ans = new int*[m];
 	for (int i = 0; i < m; ++i)
 	{
 		ans[i] = new int[n];
 		for (int j = 0; j < n; ++j)
 		{
 			ans[i][j] = -1;
 		}
 	}
 	return minCostPath_better(input, m, n, 0, 0, ans);
}
//using do
//watch the DP2 video of coding nija for explain properly
int minCostPath_DP(int **input, int m , int n){
	int **ans = new int*[m]; //just make a 2d array withpout initializ
 	for (int i = 0; i < m; ++i)
 	{
 		ans[i] = new int[n];
 	}

 	//down top approcah
 	ans[m-1][n-1] = input[m-1][n-1]; //fill last,cost of last bix will be same

 	//last row //check how it is using example 
 	for(int j = n-2; j>=0; j--){
 		ans[m-1][j] = ans[m-1][j+1] + input[m-1][j];
 	}

 	//last column //check using example of 2d input arrya
 	for(int i = m-2;i>=0;i--){
 		ans[i][n-1] = input[i][n-1] + ans[i+1][n-1];
 	}

 	//nested for loop
 	for(int i = m-2;i>=0;i--){
 		for(int j = n-2;j>=0;j--){
 			ans[i][j] = input[i][j] + min(ans[i][j+1],min(ans[i+1][j+1],ans[i+1][j]));

 		}
 	}

 	//time = O(m*n)
 	//space = O(m*n)
 	return ans[0][0];
}
//=========================================================
//check if there is a subset in arr, whose sum in sum
bool isSubsetSum(int N, int arr[], int sum){
    // code here 
    int **dp = new int*[N+1];
    for(int i =0;i<=N;i++){
        dp[i] = new int[sum+1];
    }
    
    //first row
    for(int i =0;i<=sum;i++){
        dp[0][i] = 0;
    }
    
    //first column
    for(int j =0;j<=N;j++){
        dp[j][0] = 1;
    }
    
    //others all
    for(int i =1;i<=N;i++){
        for(int j =1;j<=sum;j++){
        	//if the elemtn is greater than required sum
            if(arr[i-1] > j){
            	//dont take it
                dp[i][j] = dp[i-1][j];
            }
            else{
            	//two casese -> dont take tthat member,->take that member
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i-1]]);
            }
        }
    }
    return dp[N][sum];
}

//=====================================================
int main(){


//==========================================================
		#ifndef ONLINE_JUDGE
			// for getting input from input.txt
			freopen("input2.txt", "r", stdin);
			// for writing output to output.txt
			freopen("output3.txt", "w", stdout);
		#endif
//==========================================================
	int a = 6;
	// cin>>a;
	cout<<fibbonaci(a)<<endl;
	cout<<fibo_better(a)<<endl;

	//===================
	//question one 
	//min operations to make n to 1 (allowed = n/3,n/2,n-1)
 	int b  = 3;
 	// cin>>b;
 	cout<<"Min path from n to 1 = "<<minStepFromNto1(b)<<endl;
 	cout<<"Min path from n to 1(menotization) = "<<minStepFromNto1_Better(b)<<endl;
 	cout<<"Min path from n to 1(DP) = "<<minStepFromNto1_DP(b)<<endl;

	//===============
	//question two
	//min numbers so that sum of squares of numbers is n
 	// cout<<"Min number  = "<<minNumber(b)<<endl; //will take more time to eval on >100 
 	cout<<"Min number (menotization) = "<<minNumber_better(b)<<endl;
 	cout<<"Min number (DP) = "<<minNumber_DP(b)<<endl;
 	//================================================
 	//question 3 
 	//max number of differnet balaced biinary tree of height h
 	// int h = 3
 	cout<<"Max Balxnced BTs of height h "<<max_balanced(b)<<endl;

 	//==============================================
 	//question 4
 	//path with minimum cost (move right, down, diagonal)
 	//testing 
 	int m =3;
 	int n= 3;
 	int **input = new int*[m];
 	for (int i = 0; i < m; ++i)
 	{
 		input[i] = new int[n];
 		for (int j = 0; j < n; ++j)
 		{
 			cin>> input[i][j];
 		}
 	}
 	cout<<"Min cost path in array-"<<minCostPath(input,m,n)<<endl;
 	cout<<"Min cost path in array(memoi)-"<<minCostPath_better(input,m,n)<<endl;
 	cout<<"Min cost path in array(dp)-"<<minCostPath_DP(input,m,n)<<endl;

 	//===============================================	
 	//Q 5 LCS Longest common sub sequence

}