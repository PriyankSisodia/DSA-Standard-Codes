#include<iostream>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <utility> 
#include <cmath>
#include <set>

using namespace std;
// void findAmicable(int first, int second)
// {
//     int sum1=0,sum2=0;
//     for(int i=1; i<=first/2 ; i++)
//     {
//         //finding and adding divisors of first number
//         if(first%i==0)
//             sum1=sum1+i;
//     }
//     for(int i=1; i<=second/2 ; i++)
//     {
//         //finding and adding divisors of second number
//         if(second%i==0)
//             sum2=sum2+i;
//     }
//     //ckecking for friendly pair
//     if(first==sum2 && second==sum1)
//         cout<<"Armicables";
//     else
//         cout<<"Not a Fiendly Pair";
// }


// void printWords(int h, int m)
// {
//     char nums[][64] = { "zero", "one", "two", "three", "four",
//                         "five", "six", "seven", "eight", "nine",
//                         "ten", "eleven", "twelve", "thirteen",
//                         "fourteen", "fifteen", "sixteen", "seventeen",
//                         "eighteen", "nineteen", "twenty", "twenty one",
//                         "twenty two", "twenty three", "twenty four",
//                         "twenty five", "twenty six", "twenty seven",
//                         "twenty eight", "twenty nine",
//                       };
 
//     if (m == 0)
//         printf("%s o' clock\n", nums[h]);
 
//     else if (m == 1)
//         printf("one minute past %s\n", nums[h]);
 
//     else if (m == 59)
//         printf("one minute to %s\n", nums[(h % 12) + 1]);
 
//     else if (m == 15)
//         printf("quarter past %s\n", nums[h]);
 
//     else if (m == 30)
//     	s = "half past " + string(nums[h]);
//         // printf("half past %s\n", nums[h]);
//     	return s;
 
//     else if (m == 45)
//         printf("quarter to %s\n", nums[(h % 12) + 1]);
 
//     else if (m <= 30)
//     {
//     	string s = (string)nums[m] + " minutes past " + string(nums[h]);
//     	// cout<<s;
//     }
    	

//         // printf("%s minutes past %s\n", nums[m], nums[h]);
 
//     else if (m > 30)
//         printf("%s minutes to %s\n", nums[60 - m],
//                                      nums[(h % 12) + 1]);
// }


int main(){
	//==========================================================
		#ifndef ONLINE_JUDGE
			// for getting input from input.txt
			freopen("input2.txt", "r", stdin);
			// for writing output to output.txt
			freopen("output3.txt", "w", stdout);
		#endif
//==========================================================
	// findAmicable(2620,2924);
	// cout<<atoi("23");
	// printWords(2,23);
    int r,h,c;
    cin>>r>>h>>c;
    double pi =3.1416;

    int d1 = 2*c;

    int n = floor(h/d1);
    int m = floor((2*(double)(pi)*r)/(double)d1);
    int co = m*n;
    double p = (double)(((double)(pi)*(double)c*(double)c)*(double)co);
    double k = (double)(2*(double)(pi)*(double)r*(double)h);
    double ans = floor(k)-floor(p);
    cout<<co;



}