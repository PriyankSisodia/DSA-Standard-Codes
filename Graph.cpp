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
#include <map>
using namespace std ;

//TC for DFS/BFS = O(n+m) n=vertices,m = edges

/*  :NOTES:
- Detect cycle in directed graph we use vis array (0,1,2 value) in DFS
- in Undirected graph we use vis array (0,1 value ) in dfs or we can use union find

*/

/*
TC of BFS/DFS - O(V+E)
SC of BFS/DFS - O(V+E)


*/




//printgraph also called in DFS
void printDFS(int** edges, int n, int sv, bool* visited){//sv = starting vertex

	cout<<sv<<"-";

	//&&&&&&&
	visited[sv] = true; // set the starting vertex to visited //we are asuming graph have values from 0 to n
	//go through the array at sv
	for (int i = 0; i < n; ++i)
	{
		//if same vertex
		if(i==sv){
			continue;
		}
		//if theres is edge
		if(edges[sv][i]==1){
			//if visited already
			if(visited[i]){ //if vertex is already visited then continue
				continue;
			}

			//if not visited yet, 
			printDFS(edges,n,i,visited); //recursion
		}
	}
}


//print in BFS order
void printBFS(int** edges, int n, int sv, bool* visited){
	queue<int> pendingVertex; //use queue for pending vertexes
	
	//commented beacuse it was passed by other function
	// bool* visited = new bool[n]; //array that will store visited vertes
	
	//set all values of visited index to false
	// for (int i = 0; i < n; ++i)
	// {
	// 	visited[i] = false;
	// }

	//push the starting vertex
	pendingVertex.push(sv);

	//untill the queue gets empty==no vertex left to print
	while(!pendingVertex.empty()){

		//take out first in queue
		int currentVertex = pendingVertex.front();
		pendingVertex.pop();

		//print the cv
		cout<<currentVertex<<"-";

		//check all links /edges with its connected or not
		for (int i = 0; i < n; ++i)
		{
			//it connected to itself, dont puch it
			if(i==sv){
				continue;
			}

			//is there is edge between curentvertex and its neighbor , and it is not visited
			if (edges[currentVertex][i]==1 && !visited[i]){
				pendingVertex.push(i); //push in queue

				//&&&&&&&
				visited[i] =true; //set visited 
			}
		}
	}
}


//bfs upgraded(for the case of disconnected graph) ** learn this 
void BFS(int** edges, int n){
	//make visited array
	bool * visited = new bool[n];
	
	//mark all unvisited
	for (int i = 0; i < n; ++i)
	{
		visited[i] =false;
	}

	//check all graphs vertex
	for (int i = 0; i < n; ++i)
	{
		//if it is unvisited then print in BFS from that point
		if(!visited[i]){
			printBFS(edges,n,i,visited);
		}
	}
	delete [] visited;
}

//dfs upgraded(for the case of disconnected graph)  ** learn this
void DFS(int** edges, int n){

	//make visited array
	bool * visited = new bool[n];

	//mark all unvisited
	for (int i = 0; i < n; ++i)
	{
		visited[i] =false;
	}

	//check all graphs vertex
	for (int i = 0; i < n; ++i)
	{
		//if it is unvisited then print in DFS from that point
		if(!visited[i]){
			printDFS(edges,n,i,visited);
		}
	}
	delete [] visited;

}
//================================================================
//path using bfs
vector<int> pathUsingBFS(int **edges, int sv, int ev,int n ,bool * visited){

	//path vec to returnn
	vector<int> path;
	queue<int> pendingVertex; //pending nodes
	//map to save a vertex, and its previus vertex connected
	map<int,int> m;
	pendingVertex.push(sv);
	bool flag = false;

	while(pendingVertex.size() != 0){

		int front = pendingVertex.front();
		pendingVertex.pop();

		//if we got the path already
		if(flag){
			path.push_back(ev); //push the last node
			while(path.back() != sv){
				path.push_back(m[path.back()]); //push parent of each subsequnt node usign map
			}
			// path.push_back(sv);
			break;
		}

		//go to all connected nodes
		for(int i =0;i<n;i++){

			//if connected and not visited yet
			if(edges[front][i] == 1 && !visited[i]){

				//set visited
				visited[i] = true;

				//store this node with its parent node(front)
				m[i] = front;

				//push node inot quueu
				pendingVertex.push(i);
				if(i == ev){
					//end node found , now return path using map
					flag = true;
					break;
				}
			}
		}
	}
	return path; //return path
}

vector<int> pathUsingDFS(int **edges, int sv, int ev, int n, bool * visited){

	//set sv to visited
	visited[sv] = true;

	//for 0 to n 
	for(int i =0 ;i< n;i++){
		// cout<<sv<<" - "<<i<<endl;
		if(i == sv){
			continue;
		}

		//if there is connecttion and not visited yet
		if(edges[sv][i] == 1 && !visited[i]){
			// cout<<"get"<<endl;

			//if ending vertex is cinnected to sv directly
			if(i == ev ){
				// cout<<"found"<<endl;
				vector<int> path;
				visited[i] = true;
				path.push_back(ev);
				// path.push_back(i);
				return path;
			}

			//go to vertex with connecttion
			else{

				//get the path from next iteration
				vector<int> p = pathUsingDFS(edges, i, ev, n, visited);

				// cout<<"add"<<endl;
				if(p.size() == 0){ //if returned vector is empty means no path
					// return p;
					continue; //continue the process
				}

				//if vector is not empty then add current vertex to path
				visited[i] = true;
				p.push_back(i);

				return p;
			}
		}
	}
	//is case there is no further movement allowed(means everynode connected is visited already)
	//means there is no path fro this node
	vector<int> temp;
	return temp;
}

//================================================================
//need check and comments afterhtis line
//Cloning a graph
class Node
{
public:
	int val;
	 Node(int v){
	 	val = v;
	 }
	
};
void dfs(Node* copy, Node* orig, vector<Node*> &visited){ //helper function
        
    //put visited
    visited[copy->val] =copy;
    //for every node in neigbir
    for(auto i:orig->neighbors){
        
        //if not visited yet
        if(visited[i->val] == NULL){
            Node* newnode = new Node(i->val);
            (copy->neighbors).push_back(newnode);
            dfs(newnode,i,visited);
        }
        //if visited already
        else{
        	//push the node into the neighbor
            (copy->neighbors).push_back(visited[i->val]);
        }
    }
}

Node* cloneGraph(Node* node) { //given a graph node
    
    //if null graph
    if(node == NULL){

        return NULL;
    }
    //make visited array storing the node ( not boolean value)
    vector<Node*> visited(1000, NULL);
    
    //make new node
    Node* copy = new Node(node->val);
    
    //put visited
    visited[node->val] = copy;
        
    //for every neighbor
    for(auto i:node->neighbors){
        
        //if not visited yet
        if(visited[i->val] == NULL){
            Node* newnode = new Node(i->val);
            
            (copy->neighbors).push_back(newnode);
            dfs(newnode,i,visited);
        }

        //if visited already
        else{
            (copy->neighbors).push_back(visited[i->val]);
        }
    }
    return copy;
}

//==============================================================

//==============================================================\
//all critical connections in graph

void DFS(int u,vector<int>& dist, vector<int>& low,vector<int>& parent,vector<vector<int>>& bridges ){
    static int time = 0; //for first rum
    dist[u] = low[u] = time; //distance and low value to current tiem
    time++;
    
    //for every neighbor of u
    for(auto v: adj[u]){
        
        if(dist[v] == -1){ //if neighbor is not visited yet
            parent[v] = u; //parent of v will be u
            DFS(v,dist,low,parent,bridges);
            low[u] = min(low[u],low[v]);
            
            if(low[v] > dist[u]){ //if low of v is greater than dist of u , it means there is cricitcak cinnections
                vector<int> t;
                t.push_back(u);
                t.push_back(v);
                bridges.push_back(t);
            }
            
            
        }
        //if visited already
        else if( v!= parent[u]){ //ignore child to parent edge
            low[u] = min(low[u],dist[v]);
        }
    }
}
    
    
unordered_map<int, vector <int> > adj; //global
//https://leetcode.com/problems/critical-connections-in-a-network/submissions/
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    
    //convert edges into adjecency list (important fro all type of question)
    for(auto i:connections){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<vector<int>> bridges;
    vector<int> dist(n,-1); //distance array
    vector<int> low(n,-1); //low diatcne array
    vector<int> parent(n,-1); //parent arrya to save parent of each node
    
    for(int i =0;i<n;i++){ //go to each node
        if(dist[i] == -1){ //if not visited
            DFS(i,dist,low,parent,bridges);
        }
    }
    return bridges;
}
//==================Graph biportrite============================================

//- every Acyclic(non cyclic) graph is bipotrite
//- graph having cycle with odd length -> not a biportrite
//- graph havig cycle with even lentgh -> biportrite
//- for all vertices if we can get 2 sets(mutuall exhaustive and exclusive)
// such that all edges are across sets
//we will add nodes of each level in different sets
//-like all nodes on even levels will be in one set
//-all nodes on odd levels will be in other set
//for disconnected graph->every component wshould be biportrite to called a whole graph biportrite

//class used
class Pair{
  public:
    //class storing the current index
    int vertex;
    
    //storing path upto current node
    string path;
    
    //level of current node in graph (node 0 is at 0 level)
    int level;
    Pair(int a, string b, int c){
        vertex = a;
        path = b;
        level = c;
    }
};

//bfs function
bool checkBipartite(vector<vector<int>>& graph, vector<int>& visited,int start){
    
    queue<Pair> pendingNodes;
    
    //push start node in queue
    pendingNodes.push(Pair(start,"",0)); //vertex = start, path ="", level =0;
    
    while(pendingNodes.size()>0){
        
        Pair front = pendingNodes.front();
        pendingNodes.pop();
        //============check visited or not==========================
        
        //if front is already visited(the case of cyclic graph)
        if(visited[front.vertex] != -1){
            
            //if the level of front is diffrent from the level it is written on visited
            if(visited[front.vertex] != front.level){
                
                //means cycle with odd number of nodes
                return false;
            }
        }
        
        //front is not yet visited
        else{
            //visited that node (put level of that node in vsited array)
            visited[front.vertex] = front.level;
        }
        //========================================
        
        //now go to all nieghbours of front vertex
        for(auto neighbour : graph[front.vertex]){
            
            //if nieghbour is not yet visited
            if(visited[neighbour] == -1){
                //push node with vertex = neighbour,path = front path + str(nieghbour),level = level of front +1
                pendingNodes.push(Pair(neighbour,front.path+to_string(neighbour),front.level+1));
            }
        }
    }
    return true;
    
}

//main function
bool isBipartite(vector<vector<int>>& graph) {
    //visited array will contains the level of index i in graph
    vector<int> visited(graph.size(),-1);
    
    //disconnected graph inlucded
    for(int i =0;i<graph.size();i++){
        
        //if not visited
        if(visited[i] == -1){
            bool current = checkBipartite(graph,visited,i);
            
            //if that component of graph is not bipartite
            if(current == false){
                return false;
            }
        }
    }
    //if all the component of grpah are biportite
    return true;
}



//===============================================================
//IMP topics
/*
Degree - The degree of a node is the number of its neighbors
       - The sum of degrees in a graph is always 2m, where m is the number of edges
Regular - A graph is regular if the degree of every node is a constant d.
Complete - A graph is complete if the degree of every node is n−1, i.e., the graph contains all possible
			edges between the nodes.
Indegree - In a directed graph, the indegree of a node is the number of edges that end
			at the node,
Outdegree - The outdegree of a node is the number of edges that start at the node
*/

//==============================================================
int main(){

	//==========================================================
	#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input2.txt", "r", stdin);
		// for writing output to output.txt
		freopen("output3.txt", "w", stdout);
	#endif
	//==========================================================
//================= sample graphs
/* //connected graohs
 4
 3
 0 2
 2 1
 1 3
----------
5
5
0 1
0 2
0 4
1 2
2 3
----------
8
9
0 5
0 4
4 3
5 6
3 6
3 2
3 1
6 7
1 2
------------disconnected graphs
7
5
0 2
0 3
1 4
5 6
2 3

*/		



//===================
	int n; //number of vertices
	int e; //number of edges

	cin>>n>>e;

	//allocate memory for edges (** as edges arrya will store addres of another array) this is  a 2d array
	int **edges = new int*[n];

	
	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			edges[i][j]=0;
		}
	}

	for (int i = 0; i < e; ++i)
	{
		int f,s;   //first vertex and second vertex
		cin>>f>>s;
		edges[f][s] =1; //put 1 to the connection of f to s
		edges[s][f] =1; //put 1 to the connections of s to f
	}

	// bool* visited = new bool[n];
	// for (int i = 0; i < n; ++i)
	// {
	// 	visited[i] =0;
	// }

	//to run these two functions(older versions) make like this printBFS(int** edges, int n, int sv) in both
	//and uncomment the visited array in both
	//print graph also we cn say it DFS
	//works only for connected graph
	// cout<<"DFS order : "<<endl;
	// printDFS(edges,n,0,visited);
	// cout<<endl;

	//print BFS graph
	//works only for connected graph
	// cout<<"BFS order : "<<endl;
	// printBFS(edges,n,0);

	//DFS print for both connected and disconnected graphs
	cout<<"DFS (Upgraded) - "<<endl;
	DFS(edges,n);
	cout<<endl;

	//BFS print for both connected and disconnected graphs
	cout<<"BFS (Upgraded) - "<<endl;
	BFS(edges,n);



	
	//questions 
	//path using BFS
	cout<<endl;
	cout<<"Path using BFS - "<<endl;
	bool * visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
	vector<int> path = pathUsingBFS(edges,3,7,n,visited);
	for(auto i:path){
		cout<<i<<"-";
	}

	cout<<endl;
	//path between 2 given vertex using DFS
	cout<<"Path using DFS - "<<endl;

	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
	vector<int> path2 = pathUsingDFS(edges,3,7,n,visited);
	for(int i =path2.size()-1 ;i>=0 ;i--){
		cout<<path2[i]<<"-";
	}
	//delete memory
	delete [] visited;
	for (int i = 0; i < n; ++i)
	{
		delete [] edges[i];
	}
	delete [] edges;


	//if graph is connected or not
	//return all connected components

	//testing dijktras

	int n; //number of vertices
	int e; //number of edges

	cin>>n>>e;
	//allocate memory for edges (** as edges arrya will store addres of another array) this is  a 2d array
	int **edges = new int*[n];

	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			edges[i][j]=0;
		}
	}
	
	for (int i = 0; i < e; ++i)
	{
		int f,s;   //first vertex and second vertex
		cin>>f>>s;
		edges[f][s] =1; //put 1 to the connection of f to s
		edges[s][f] =1; //put 1 to the connections of s to f
	}
}