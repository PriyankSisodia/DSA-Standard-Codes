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
using namespace std ;
 
#include "ourMap.h"

int main(){
    ourMap<int> map;//ourmap use case
    cout<<"Load factors after each insert "<<endl;
    for (int i = 0; i < 10; ++i)
    {
        char c = '0' +i;
        string key = "abc";
        key = key + c;
        int value = i+1;
        // cout<<key<<" "<<value<<endl;
        map.insert(key,value);
        cout<<map.getLoadfactor()<<endl;
        //LF = count/numBuckets
        //for first insert count = 1;numBucket =5;lf = 0.2
        //for sec insert count = 2;numBucket =5;lf = 0.4
        //for third insert count = 3;numBucket =5;lf = 0.6
        //for fourth insert count = 4;numBucket =5;lf = 0.8 which is > 0.7 ,so rehash(double size , now numBuckets = 2* 5)
        //for fourth insert count = 4;numBucket =10; //rehash
        //for firvth insert count = 5;numBucket =10 //lf = 0.5

    }

    map.remove("abc2");
    map.remove("abc7");
    cout<<map.size()<<endl;
    for (int i = 0; i < 10; ++i)
    {
        char c = '0' +i;
        string key = "abc";
        key = key + c;
        cout<<key<<":"<<map.getValue(key)<<endl;
    }

    cout<<map.size()<<endl;
}