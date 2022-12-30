#include <bits/stdc++.h>

using namespace std;

// 17 

//===================longest increasing subsequence(LIS)===
//meaning - dp[i] = length of LIS upto arr[i] that ends with a[i] in LIS
int LIS(int arr[], int n) {
	if(n==0)
		return ;
	vector<int> dp(n, 0);

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int maxi = 0;
		for (int j = 0; j < i; j++) {

			if (arr[j] < arr[i]) {

				maxi = max(dp[j],maxi);
				// if (dp[j] > maxi) {
				// 	maxi = dp[j];
				// }
			}
		}
		dp[i] = maxi + 1;
	}
	return *max_element(dp.begin(), dp.end());
}


//==========================Print LIS=======================
int printLis(int arr[],int n){
	if(n==0)
		return;
	vector<vector<int>> lis(n);

	lis[0].push_back(arr[0]);
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i] && lis[j].size() > lis[i].size()){
				lis[i] = lis[j];
			}
		}
		lis[i].push_back(arr[i]);
	}
	int j=-1;
	for(int i =0;i<n;i++){
		if(lis[j].size() < lis[i].size()){
			j=i;
		}
	}
	return lis[j];
}

//====================Longest Common Subsequence====================
//meaning - dp[i][j] - LCS of string a(upto index i) and b(upto index j)
int lcs(string a, string b){
	int m = a.size();
	int n = b.size();
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	for(int i =0;i<m+1;i++){
		for(int j =0;j<n+1;j++){
			if(i ==0 || j == 0){
				dp[i][j] = 0;
			}
			else if(a[i-1] == b[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
}

//===================Longest Common Substring=======================
//meaning - dp[i][j] - LCS of string a(upto index i) and b(upto index j)
int lcss(string a, string b){
	int m = a.size();
	int n = b.size();
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	for(int i =0;i<m+1;i++){
		for(int j =0;j<n+1;j++){
			if(i ==0 || j == 0){
				dp[i][j] = 0;
			}
			if(a[i-1] == b[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = 0;
			}
		}
	}
	// returb mx value in dp
	return dp[m][n];
}

//================Print longest common substring =================

//ques - find longest palindromic substring in a string
// ans - //lcs of S and rev of S
bool ispal(string s){
    string p = s;
    reverse(s.begin(),s.end());
    return p == s;
}

string lcs(string a, string b){
    int n = a.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    int maxi = 0;
    int mi =0;
    int mj =0;
    for(int i =0;i<=n;i++){
        for(int j =0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] =0;
            }
            else{
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                    if(dp[i][j] > maxi){
                        maxi = dp[i][j];
                        mi =i;
                        mj=j;
                    }
                    
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
    }
    
    string sub = "";
    

    //cordinate at maximum value
    int i =mi;
    int j = mj;

    //it will be continuous
    while(i>0 && j>0 && dp[i][j] !=0){
        if(a[i-1] == b[j-1]){
            sub += a[i-1];
            i--;
            j--;
        }
    }

    //edge cases 
    if(maxi == 1){
        string p = "";
        p += a[0];
        return p;
    }


    if(ispal(sub)){
        return sub;
    }

    //if it is not palindrome , return first character
    else{
        string p = "";
        p += a[0];
        return p;
    }
    return sub;
}


string longestPalindrome(string S){
    
    //lcs of S and rev of S
    string rS = "";
    for(int i=S.size()-1;i>=0;i--){
        rS+= S[i];
    }
    string ans = lcs(S,rS);
    
    return ans;
}
//=================Print Longest Common Subsequence=================

void(string a, string b){

	//make dp of LCS
	int m = a.size();
	int n = b.size();
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	for(int i =0;i<m+1;i++){
		for(int j =0;j<n+1;j++){
			if(i ==0 || j == 0){
				dp[i][j] = 0;
			}
			if(a[i-1] == b[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	//travel reverse in dp
	int i = m;int j= n;
	string ans="";
	while(i>0 && j>0){
		if(a[i-1] == b[i-1]){
			ans += a[i];
			i--;
			j--;
		}
		else{
			if(dp[i-1][j] > dp[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}
	return reverse(ans);
}

//==================Shortest Common Supersequence===========aditya verma ntoe
//Length of a shortest sequence that have both the strings
int SCS(string x, string y, int m , int n){

	//find lcs
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	for(int i =0;i<=m;i++){
	    for(int j=0;j<=n;j++){
	        if(i==0 || j==0){
	            dp[i][j]=0;
	        }
	        else if(x[i-1] == y[j-1]){
	            dp[i][j] = dp[i-1][j-1] +1;
	        }
	        else{
	            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	}
	int lcs = dp[m][n];
	return (m+n) - lcs; //length of SCS
}
//============================Kadanes algirithm ==================
vector<int> dp(n,0);
dp[0] = arr[0];
for(int i =1;i<n;i++){
    dp[i] = max(arr[i], dp[i-1]+arr[i]);
}
return *max_element(dp.begin(),dp.end());



//================================Print SCS===========================================
// we traverse reverse in dp to collect the lcs one time and other elements one time (disacrded earliear)
void printSCS(string x, string y, int m , int n){

	//make LCS dp
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	for(int i =0;i<=m;i++){
	    for(int j=0;j<=n;j++){
	        if(i==0 || j==0){
	            dp[i][j]=0;
	        }
	        else if(x[i-1] == y[j-1]){
	            dp[i][j] = dp[i-1][j-1] +1;
	        }
	        else{
	            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	}

	//travel reverse in dp
	int i = m;int j= n;
	string ans="";
	while(i>0 && j>0){
		if(a[i-1] == b[i-1]){
			ans += a[i];
			i--;
			j--;
		}
		else{
			if(dp[i-1][j] > dp[i][j-1]){
				ans += a[i-1]; //we add the discarded member
				i--;
			}
			else{
				ans += b[j-1]; // wee add the discarded member
				j--;
			}
		}
	}
	return ans;
//image to understand - https://www.techiedelight.com/wp-content/uploads/LCS-Backtrack-Wiki.png
}

//=====================================Edit Distance===============================
//make a string A into B , with min number of steps - remove one elemnt, add a elemnt, replace a elemnt
int EditDistace(string a, string b, int m, int n){
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));

	//first row
    for(int i =0 ;i <n+1;i++){
        dp[0][i] = i;
    }
    //first column
    for(int i =0 ;i <m+1;i++){
        dp[i][0] = i;
    }
	for(int i =1; i <=m;i++){
		for(int j =1;j<=n;j++){
			if(a[i-1] == b[i-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1 ;
			}
		}
	}
	return dp[m][n];
}


//================================Maximum costs path in 2D matrix=======
// go down, (down+left), (down+right) = get max reward in matrrix

int maximumPath(int N, vector<vector<int>> Matrix)
{
    vector<vector<int>> dp(N,vector<int>(N,0));
    
    //last row intitilaize
    for(int j =0 ;j<N;j++){
         dp[N-1][j] =  Matrix[N-1][j];
    }
    
    //down to up
    for(int i =N-2 ;i>=0;i--){
        for(int j =N-1;j>=0;j--){
        	//leftmost column
          if(j==0){
              dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + Matrix[i][j];
          }
          //rightmost column
          else if(j==(N-1)){
              dp[i][j] =  max(dp[i+1][j],dp[i+1][j-1])+ Matrix[i][j];
          }
          //middle block
          else{
              dp[i][j] = max(dp[i+1][j],max(dp[i+1][j-1], dp[i+1][j+1])) + Matrix[i][j];
          }
        }
    }
    int ans = 0;
    for(int i =0;i<N;i++){
        ans = max(ans,dp[0][i]);
    }
    return ans;
}

// ============================Coin change (maximum number of ways)========

//meaniig dp[i][j] = max nymber of ways to get amount j, with given i types of coins
int maxNumOfWays(int coins[], int amount){
	int n = coins.size();
	vector<vector<int>> dp(n+1, vector<int>(amount+1,0));

	// first col *
	for(int i =0;i<m;i++){
        dp[i][0] = 1;
    }

	for(int i =0 ;i<=n;i++){
		for(int j=0;j<=amount;j++){
			if(i == 0){
				dp[i][j] = 0;
			}
			// already inintalize
			else if(j==0) continue;
			else if(coins[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]]; //coins can repeat (if not repeat dp[i-1][j-coins[i-1]])
			}
		}
	}
}



// ============================Coin change(minimum number of coins) ======
//given array of availbl type of coins, want amount
int minCoins(int coins[], int amount){
	int n = coins.size();
	vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
	//edge case may be improved
	if(n == 1){
		if(amount == coins[0]){
			return 1;
		}
		if(amount == 0){
			return 0;
		}
	}
	//first row
	for(int i =0 ;i<=amount;i++){
		dp[0][i] = INT_MAX-1;
	}

	//first col
	for(int i= 1;i<=n;i++){
		dp[i][0] = 0;
	}

	//second row init
	for(int i = 1;i<=amount;i++){
		if(i%coins[0] ==0){
			dp[1][i] = i/(coins[0]);
		}
		else{
			dp[1][i] = INT_MAX-1;
		}
	}

	//block
	for(int i = 2;i<=n;i++){
		for(int j =1;j<=amount;i++){
			if(coins[i-1]>j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = min(dp[i-1][j],dp[i][j-cost[i-1]]+1);
			}
		}
	}

	return dp[n][amount] == INT_MAX-1? -1: dp[n][amount];

}

//=============================Matrix Chain Multiplication(min multiply)====================

//example ABCD == A*(result of (BCD))
int dp[1001][1001];

//helper func
int solve(int arr[], int i, int j){
    //edge case
    if(i>=j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int mx = INT_MAX;
    
    //break the array into two parts
    for(int k = i;k<=j-1;k++){
        //         part 1           part 2            result after multiplying both parts
        int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        
        //take the minium
        if(temp <mx){
            mx = temp;
        }
    }
    
    //memosize
    return dp[i][j] = mx;
    
}

//main func
int matrixMultiplication(int N, int arr[])
{
    int n = N;
    
    memset(dp,-1,sizeof(dp));
    
    //start from index 1 to all
    return solve(arr,1,n-1);
}

// =========================== Palindrome Partioning (min partition)===============






// =========================   0-1 KnapSack (get max value)  ======================

// n = weight_capacity, W = size of weight array
int knapSack_0_1(int W, int weight[], int value[], int n){
	vector<vector<int>> dp(n+1,vector<int>(W+1,-1));

	for(int i =0;i<n+1;i++){
		for(int j =0;j<W+1;j++){
			if(i == 0|| j==0){
				dp[i][j] = 0;
				continue;
			}
			else if(weight[i-1] > j ){
				dp[i][j] = dp[i-1][j];
			}
			else if(weight[i-1] <= j){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]] + value[i-1]);
				// d[i][j] = max(dp[i-1][j], dp[i][j-weight[i-1]] + value[i-1]);  if repetition allowed
			}
		}
	}
	return dp[n][W];
}

//========================= Egg drop (pep coding )=================
// find minimum number of attempts to drop egg to be able to find the threshold floor
// or - the minimum number of moves that you need to determine with certainty what the value of f is.
// n = number of eggs available, k = number of floors
int eggDrop(int n, int k) 
{
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    // when eggs are 0, we canot do anything,= so ignore
    for(int e=1; e<=n; e++){
        for(int f=1; f<=k; f++){

        	// when there is only one egg, we just go to each floor
        	// worst case is f number of attempts
            if(e == 1){
                dp[e][f] = f;
            }

            // if only one floor, we need only one attmpt 
            else if(f == 1){
                dp[e][f] = 1;
            }
            else{
                int mini = INT_MAX;
                // left varirable starts from f-1, to 0
                // right variable starts from 0 to f-1, upper row
                for(int left=f-1, right=0; left>=0; left--,right++){
                    int v1 = dp[e][left]; //egg safe
                    int v2 = dp[e-1][right]; //egg breaks
                    int val = max(v1,v2);
                    mini = min(val,mini);
                }
                dp[e][f] = mini+1; //made mistake
            }
        }
    }
    return dp[n][k];
}


//=========== Longest Palindromic Subsequence =========

// answer = length of LCS(A, reveres(A));
int longestPalinSubseq(string A) {
    //code here
    string a = A;
    string b = "";
    for(int i =A.size()-1;i>=0;i--){
        b += A[i];
    }
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    for(int i =0;i<=n;i++){
        for(int j =0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] =0;
            }
            else if(b[i-1] == a[j-1]){
                dp[i][j] = dp[i-1][j-1] +1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}


//=================== Rod Cutting ================

int cutRod(int price[], int n) {
  vector<vector<int>> dp(n+1,vector<int>(n+1,0));
  for(int i =0;i<=n;i++){
      for(int j =0;j<=n;j++){
          if(i==0 || j==0){
              dp[i][j] =0;
          }

          // when we can not cut the rod(if peice size is > rod size)
          else if(i > j){
        //   else if((i)<price[j-1]){ wrong
              dp[i][j] = dp[i-1][j];
          }
          else{

          	//               not cuting it ,  cuting a peice of length i with value price[i-1]
              dp[i][j] = max(dp[i-1][j], dp[i][j-i] + price[i-1]);
          }
      }
  }
  return dp[n][n];
}

// ====================== Bitonic Longest Subsequence========

void lcs(vector<int>nums,vector<int>&dp){
    int n = nums.size();
    dp[0] = 1;
    for(int i =1;i<n;i++){
        int maxi =0;
        for(int j = 0;j<i;j++){
            if(nums[i] > nums[j]){
                maxi = max(maxi,dp[j]);
            }
        }
        dp[i] = maxi+1;
    }
}


int LongestBitonicSequence(vector<int>nums)
{
    int n = nums.size();
    vector<int> dp_l(n,0);  //to store lcs of nums
    vector<int> dp_r(n,0);  //to store lcs of rev(nums)
    lcs(nums,dp_l);       

    // rev the given array
    reverse(nums.begin(),nums.end());
    lcs(nums,dp_r);

    // rev the dp array
    reverse(dp_r.begin(),dp_r.end());
    

    // add both arrays
    for(int i =0;i<n;i++){
        dp_l[i] += dp_r[i];
    }
    
    // return (max_elemnt -1) (-1 for because elemt is counted two timess)
    return *max_element(dp_l.begin(),dp_l.end())-1;
    
    
    
   // find lcs of each in given order
   
   //find lcs of each in rverese order 
   
   //add both array
   
   //(max elemnt -1) is answer 
}

// =====================Floyd Warshal ==================
void shortest_distance(vector<vector<int>>&matrix){
    int n = matrix.size();
   
    for(int k =0;k<n;k++){
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(((matrix[i][j] > (matrix[i][k] + matrix[k][j]))||(matrix[i][j] == -1))&&(matrix[i][k]!=-1 && matrix[k][j]!=-1)){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
}

// =====================Palindrome Partitioning =======

int dp[505][505];
    
bool isPalindrome(string s, int i, int j){
    
    // size of string to check
    int n = (j-i)+1;
    
    // i made mistake here l<(i+(n/2))*****
    for(int l =i,r=j;l<(i+n/2);l++,r--){
        if(s[l]!=s[r]){
            return false;
        }
    }
    return true;
}
int solve(string s, int i, int j){
    // base case
    if(i>=j){
        return 0;
    }
    
    // if string from i to j is palindrom
    // we dont need any partition in that part of string
    if(isPalindrome(s,i,j)){
        return 0;
    }
    
    // if already caluclated
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int mini = INT_MAX;
    
    // like matrix multiplication
    // we partition the string from i to j one by one
    for(int k = i;k<j;k++){
        
        // min no of partition req in left part
        int left = dp[i][k];
        
        // min no of partition req in right part
        int right = dp[k+1][j];
        
        // if it is not evaluated
        if(left==-1){
            left = solve(s,i,k);
        }
        if(right==-1){
            right = solve(s,k+1,j);
        }
        
        // +1 partition inlude the current partiticion
        int temp = 1 + left+right;
        
        // take alls min
        mini = min(mini,temp);
    }
    
    // save in dp
    return dp[i][j] = mini;
}

int palindromicPartition(string str)
{
    // code here 
    memset(dp,-1,sizeof(dp));
    return solve(str,0,str.length()-1);
}
//==========================Target Subset Sum============
bool isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(sum+1,0));
    for(int i =0;i<=n;i++){
        for(int j =0;j<=sum;j++){

        	//these base condition are imp //arr[0][0] has to be 1
            if(j==0){
                dp[i][j] = 1;
            }
            else if(i==0){
                dp[i][j] = 0;
            }


            else{
                if(arr[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i-1]]);
                }
            }
        }
    }
    return dp[n][sum];
}










// ========================== Box stacking ============
/*
You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, 
width w and length l. You task is to create a stack of boxes which is as tall as possible,
 but you can only stack a box on top of another box if the dimensions of the 2-D base
  of the lower box are each strictly larger than those of the 2-D base of the higher box
  We can rotate the boxes to get max height(infinite availibiilty)
*/

static bool comp(vector<int> a, vector<int> b){
    return a[0]*a[1]> b[0]*b[1];
    // return a[0]<b[0];
}

int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    vector<vector<int>> boxes;
    for(int i =0;i<n;i++){
        //first
        vector<int> t1;

        // to make an vector easily sortable and lookup
        t1.push_back(max(length[i], width[i]));
        t1.push_back(min(length[i], width[i]));
        t1.push_back(height[i]);
        boxes.push_back(t1);
        
        
        //sec
        vector<int> t2;
        t2.push_back(max(height[i], width[i]));
        t2.push_back(min(height[i], width[i]));
        t2.push_back(length[i]);
        boxes.push_back(t2);
        
        //third
        vector<int> t3;
        t3.push_back(max(length[i], height[i]));
        t3.push_back(min(length[i], height[i]));
        t3.push_back(width[i]);
        boxes.push_back(t3);
    }
    
    n = 3*n;

    //sort in decreasing order
    sort(boxes.begin(),boxes.end(),comp);
    vector<int> dp(n,0);
    //0 - width
    //1 - length
    //2 - height
    
    for(int i=0;i<n;i++){
        dp[i] = boxes[i][2];
    }
    

    // applying LIS
    for(int i =1;i<n;i++){
        for(int j = 0;j<i;j++){
            // if area of i(strictly) < area of j add 
            if(boxes[i][0] < boxes[j][0] && boxes[i][1] < boxes[j][1]){
                dp[i] = max(dp[i], dp[j] + boxes[i][2]);
            }
        }
    }
    
    return *max_element(dp.begin(),dp.end());