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


//implementing min-heap
class PriorityQueue
{
    vector<int> pq;
public:
    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size()==0;
    }

    //return size of priority queus ,no of elements present
    int getSize(){
        return pq.size();
    }

    //return min elemnt of pq
    int getMin(){
        if(isEmpty()){
            return 0; //pririty queue is empty
        }
        return pq[0]; //min is at the root node
    }

    //insert elemnt in priority queu
    void insert(int element){
        pq.push_back(element); //first push in the vector, property of heap
        
        int childIndex = pq.size() -1;

        //untill we get to root node 
        while(childIndex > 0){
            
            //take parent index of childs index (creative bruh!)
            int parentIndex = (childIndex-1) /2;

            //swap the parent and child to have the property of heap
            if(pq[childIndex]< pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }

            //if we dont need to swap (as it already a minheap)
            else{
                break;
            }

            //now parents index will be childindex ans we move upwards
            childIndex = parentIndex;
        }
    }

    //if confused always try DRY run of the code
    //remove the min elemnt of the priority queue
    int removeMin(){
         int ans = pq[0]; //first elment to be retruned
         pq[0] = pq[pq.size()-1];  //put the last element on the top
         pq.pop_back(); //remove from last 

         //down heapify
         int parentIndex =0;
         int leftChildIndex = 2* parentIndex +1; //left child index  in pq array
         int rightChildIndex = 2* parentIndex +2; //right

         while(leftChildIndex < pq.size()){

            //replace the parent elenment with min(leftchild,rightchild)
            
            int minIndex = parentIndex;
            if(pq[minIndex]>pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }

            //right child shoukd be in the range 
            if(rightChildIndex < pq.size() && pq[minIndex]>pq[rightChildIndex]){
                minIndex = rightChildIndex;
            }

            //if the parent is smaller than both the childs
            if(minIndex == parentIndex){
                break;
            }
            
            //swap the elemnts
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            //now that chlid will be parent
            //continue till it gets the correct postion inheap;
            parentIndex = minIndex;
            leftChildIndex = 2* parentIndex +1;
            rightChildIndex = 2*parentIndex +2;

         }
         return ans;
    }
    
};