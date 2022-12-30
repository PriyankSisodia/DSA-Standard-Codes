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
#include<tuple>
using namespace std ;
/*
 ----------------------------INDEX-------------------------------------
 - Prims Algo    - for MST
 - Bellman Ford algo  - for shortest path from any source to any vertex
 - Dijhstras    - for shortest path from point a to b
 - Krushals      - for MST
 - Union Find    
 - Graph Colouring * many type of problemse
 - Bipartite Graph * 
 - Floyd Marshal *
 - Bridges * (critical connections)

*/
//======================== PRIMS ALGO ======================================================

//USED TO MAKE MINIMUM SPANNING TREE

/*

we take the minimum cost edge
take the next edge (connected to allready slected vertices )which has smallest cost
while(n-1)
    do the same

//we can not find mst for unconnected graph

*/


int findminvertex(int * weights,bool * visited, int n){
    int minvertex =-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minvertex==-1||weights[i]<weights[minvertex])){
            minvertex=i;
        }
    }
}

void prims(int **edges,int n){
    int * parent  = new int[n];
    int * weights = new int [n];
    bool* visited = new bool[n];
    for(int i =0;i<n;i++){
        visited[i] = false;
        weights[i] =INT_MAX;
    }
    parent[0] = -1;
    weights[0] = 0;
    for(int i =0;i<n;i++){
        int minvertex = findminvertex(weights,visited,n);
        visited[minvertex] = true;
        //explore invisited neighbors
        for(int j=0;j<n;j++){
            if(edges[i][j] !=0 && !visited[i][j]){
                if(edges[minvertex][j] < weights[j]){
                    weights[j] = edges[minvertex][j];
                    parent[j] = minvertex;

                }
            }
        }

    }
    //selected edges are from vertex[i](means i)-parent[i], and thier wight is weight[i]
    for (int i = 0; i < n; ++i)
    {
        if(parent[i]<i){
            cout<<parent[i]<<" "<<i<<weights[i]<<endl;
        }
        else{
            cout<<i<<" "<<parent[i]<<weights[i]<<endl;
        }
    }
}

//=============BELLMAN FORD=======================================================

//BELLMAN FORD ALGORITHM FOR SHORTEST PATH IN GRAPH BTW ALL PAIRS
//-can work if weights are negative
//-can work if there is a cycle in graph with positive weight
//-do not work if there is a cycle in a graph with negative weight
//-can detect if there is a cycle in graph with -ve weight
//NON- directed graph - we use bfs for shortest path
//directed graph(all positive weights) - use dijkhtra algo for shortest path
//directed graph(with -ve weights) - use bellman ford for shortest path (ugrade of dijktra)
//directed graph(with -ve weights and cycle with -ve weights) - SPFA (shortest path faster algo) for shortest path (upgrade of belmanford)
//TC = o(VE), v= number of vertices, e=numbe rof edgse


//get<i>(edges[0]) will return the ith elemnt of tupple 
void bellman_ford(vector<tuple<int,int,int>> edges,int x){
    vector<int> distance(n+1,INT_MAX); //all distances to infinity
    distance[x] =0; //starting node

    //run loop for n-1 times,bevause there can be of maximum n-1 edges of n vertices(beacuse it do not contain a cycle)
    for(int i =1;i<=n-1;i++){
        for(auto e: edges){

            //source, dest, weight
            int a,b,w;
            tie(a,b,w) = e; //new thing i learned , tie will unwrap values of e to a,b,c (e is tupple of starting node,ending node,weight ofe edge)
            //or
            //a = get<0>(i);
            //b = get<1>(i);
            //w = get<2>(i);
            distance[b] = min(distance[b],distance[a] + w);
        }
    }
}


// to detect cycle in directed graph (with -ve weight) (continue code)
    for(auto p: ed){
        int a,b,w;
        tie(a,b,w) = p;
        if(dist[b] > dist[a] +w){
            return 1; //graph contains cycle
        }
       // dist[b] = min(dist[b], dist[a]+w); 
    }
    return 0; //do not contain cycle

//=============== DIJKTRAS ===========================

//DIJKTRAS ALGO FOR SHORTEST PATH BTW 2 GIVEN POINTS




//TC- O(|V|^2) == O(n^2) , we go to each vertex so n, at each vertex
// we are changing others vertex(worst case n-1 vertex) so , n*n
//DRAWBACK - Graph with -ve edge weight value will not work 

int findminvertex(int *distance, bool *visited, int n){
    int minvertex = -1;

    //chech in distance vector , which isnot visited yet
    for (int i = 0; i < n; ++i)
    {
        //in cse of i =0; just save minindx to 0
        if(!visited[i] && (minvertex == -1 ||distance[i] < distance[minvertex])){
            minvertex = i;
        }
    }
    return minvertex;
}

void dijksatra(int **edges, int n){

    int* distance = new int[n];
    bool visited = new bool[n]; //check
    for(int i =0;i<n;i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    //put starting node as 0 distcance
    distance[0] = 0;

    for(int i =0;i<n-1;i++){ //n or n-1 both will give corr ans, 

        //finding vertex with minimum distanece
        int minvertex = findminvertex(distance,visited,n);
        visited[minvertex] = true;

        for(int j =0;j<n;j++){
            if(!visited[j] && edges[minvertex][j] !=0){
                int dist = distance[minvertex] + edges[minvertex][j];
                if(dist < distance[j]){
                    distance[j] = dist;
                }
            }
        }
    }
    for(int i =0;i<n;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete []visited;
    delete []distance;
}


//use this 
// using min heap
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{


    //minheap to get the nodes with min weight always
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;


    //to store distances from source S
    vector<int> dist(V,INT_MAX);
    
    //starting vertex
    dist[S] = 0;
    
    //weight, node
    pq.push({0,S});

    //for all nodes
    while(pq.size()>0){
        pair<int,int> front  =  pq.top();
        pq.pop();

        int dist_x = front.first; //weight to x
        int node_x = front.second; 
        
        for(auto neigh: adj[node_x]){
            int dist_y = neigh[1];
            int node_y = neigh[0];
            
            if(dist_y + dist_x < dist[node_y]){
                pq.push({dist_y+dist_x, node_y});
                dist[node_y] = dist_y+dist_x;
            }
        }
    }

    return dist;
}



//================ KRUSHKALS ===========================
//KRUSHKALS algo for mst
//edge = [source,destinstion, weight]
//edges = array of edge
// kruskals(edges,n,E) use
/*

//we can use min heap to get the min cost edgse - comp- o(logn)
so final comp = n*logn

O(ElogE) or O(ElogV). 
Sorting of edges takes O(ELogE) time. After sorting,
 we iterate through all edges and apply the find-union algorithm. The find and union operations can take at most
  O(LogV) time. So overall complexity is O(ELogE + ELogV) time. The value of E can be at most O(V2), so O(LogV) is O(LogE) the same.
 Therefore, the overall time complexity is O(ElogE) or O(ElogV)

*/
class edge{
public:
    int source;
    int dest;
    int weight;
};
bool comp(edge e1, edge e2){
    return e1.weight<e2.weight;
}
int findParent(int v,int * parent){
    if(parent[v] == v){
        return v;
    }
    return findParent(parent[v],parent);
}

void kruskals(edge * input, int n, int E){
    //sort inout array - asendid order based on wights
    sort(input,input+E,comp);
    edge * output = new edge[n-1];
    int count =0;
    int i =0;
    int * parent = new int[n];
    for(int i =0;i<n;i++){
        parent[i] = i;//parent is slef
    }

    //mst has n-1 edges
    while(count != n-1){

        edge currentEdge = input[i];

        //check if we can add the curredge in mst or not (if it makes cycle, ignore)
        int sourceParent = findParent(currentEdge.source,parent); //topmost parent 
        int destParent = findParent(currentEdge.dest,parent);


        //not making cycle
        if(sourceParent != destParent){
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }

        //making cycle
        i++;
    }
}

//============= UNION FIND (Disjoint set)**============================================


// union find + path compression ---------
 int Find(int x) {
    int temp = x;
    while (temp != parent[temp]) {
        temp = parent[temp];
    }
    // Path compression below
    while (x != temp) {
        int next = parent[x];
        parent[x] = temp;
        x = next;
    }
    return x;
}

void Union(int x, int y) {
    int xx = Find(x);
    int yy = Find(y);
    if (xx != yy) {
        parent[xx] = yy;
    }
}


//union with rank ***imp
void Union(int x, int y) {
    x = Get(x);
    y = Get(y);

    if(x != y) {
        if(sz[x] < sz[y])
            swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
    }
}

//----------------------------------

//to find the root of node p
int find(int p){

    //save the current node
    int root = p;

    //if root == parent[root], means it is parent of itself(initialized)
    while(root != parent[root]){
        root = parent[root];
    }
    //after the loop root will be at the root node of p
    //we can return the value root, because we got what we wanted
    //return root;
    //tc- O(n)(in worst case there will be a tree that look like linked list)

    //improvement == path compression/union by rank

    //we go through every node between p and root node,
    //and will make root as a parent of all nodes 
    while(p != root){
        int next_node = parent[p];
        parent[p] = root; //make root as its parent
        p = next_node; //move up
    }

    //in this case TC- O(logn) also in worst case
    return root;

}

//this do both work using recursion, return parent node + path compression
int find(int p){
    //initia;ize the mapping, parent of p will be p
    if(parent.count(p) == 0){
        parent[p] = p;
    }
    if(parent[p] != p){
        parent[p] = find(parent[p]);
    }
    return parent[p];
}

//union p, q, means merge both the components/groups together
void union(int p, int q){
    int root1 = find(p);
    int root2 = find(q);

    //if both have same root-> both are in a same group
    if(root1 == root2) {
        return;
    }
    //else make one parent of other
    parent[root1] = root2;
 }



// Union find + rank compression 
for (int i = 0; i < n; i++) {
    parent[i] = -1;
    rank[i] = 1;
}
//rank compression
 void unite(int x, int y)
{
    int s1 = find(x);
    int s2 = find(y);

    if (s1 != s2) {
        if (rank[s1] < rank[s2]) {
            parent[s1] = s2;
            rank[s2] += rank[s1];
        }
        else {
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
    }
}




//===========================GRAPH COLOURING============================================================

//GIVEN A GRAPH AND K COLORS, ASSIGN A COLOR TO EACH NODE
//SO ADJECENT NODES GET DIFFERENT COLORS

//THE MINIMUM VALUE OF K FOR WHICH SUCH A COLORING IS POSSIBLE   //remain
//IS CALLED CHROMATIC NUMBER OF GRAPH(represented as CHI(G))


//backtracking
//solution for if we can color the graph in less than m colors or not (yes or no)
bool issafe(int s, int col, vector<vector<int>>& gr,vector<int> &color){
    for(int i =0;i<101;i++){
        if(s == i){
            continue;
        }
        else if(gr[s][i] == 1){
            if(color[i] == col) return false;
        }
    }
    return true;
}

bool helper(int s, int n, vector<vector<int>>& gr,vector<int> &color,int m){
    if(s == n){
        return true;
    }
    
    for(int i =1;i<=m;i++){
        if(issafe(s,i,gr,color)){
            color[s] = i;
            if(helper(s+1,n,gr,color,m)){
                return true;
            }
            color[s] =0;
        }
    }
    
    return false;
}



bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int> color(n,0);
    
    vector<vector<int>> gr(101,vector<int>(101,0));
    for(int i =0;i<101;i++){
        for(int j =0;j<101;j++){
            gr[i][j] = graph[i][j];
        }
    }
    return helper(0,n,gr, color,m);
} 



//========================== BIPARTITE GRAPH ===========================================
//USINF BFS
//A = number of nodesingraph
//b = all edges
//return if graph is biportrite or not

int Solution::solve(int A, vector<vector<int> > &B) {
    int n =A;
    

    //make a graph
    vector<vector<int> > graph(n+1,vector<int>());

    //to take first source to start bfs
    int src = INT_MAX;
    for(auto p: B){
        src = min(src,p[0]);
        graph[p[0]].push_back(p[1]);
        graph[p[1]].push_back(p[0]);
    }

    //to give color to every node 0 or 1
    vector<int> color(n+1,-1);

    //give source as color1
    color[src] = 1;

    //push source to explorerr queue
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int f = q.front();
        q.pop();

        //go to all neighbrs
        for(auto neig:graph[f]){
            if(f == neig){
                continue;
            }

            //if neigboyr is not colored
            if(color[neig] == -1){
                
                //color with oposite color if 0 then 1, if 1 then 0
                color[neig] = 1-color[f]; //color eihter 0 or 1

                //push neihbor into explorere queueu
                q.push(neig);
            }

            //if already colored
            else if(color[neig] !=-1){

                //and color is same as the niehhbr
                if(color[neig] == color[f]){
                    return 0;
                }
            }
        }
    }
    return 1;
}

//Using DFS
//TC/SC = O(V+E)
//Given adjacecncy list
bool isBipartite(int n, vector<vector<int>> &graph){
    vector<int> color (n+1,-1);
    for(int i =0;i<n;i++){
        if(color[i]==-1){
            //source
            color[i]=0;
            if(dfs(i,graph,color) == false){
                return false;
            }
        }
    }
    return true;
}

bool dfs(int src, vector<vector<int>> &graph, vector<int> color){
    for(auto neighbour:graph[src]){
        if(color[neighbour]!=-1){
            color[neighbour] = 1-color[src];
            if(dfs(neighbour,graph,color)==false){
                return false;
            }
        }
        else{
            if(color[neighbour] == color[src]){
                return false;
            }
        }
    }
    return true;
}





//===========================BRIDGES SEARCHING ====================================
void DFS(int u,vector<int>& dist, vector<int>& low,vector<int>& parent,vector<vector<int>>& bridges ){
    static int time = 0; //for first rum
    dist[u] = low[u] = time; //distance and low value to current tiem
    time++;
    
    //for every neighbor of u
    for(auto v: adj[u]){
        
         //if neighbor is not visited yet
        if(dist[v] == -1){

            //parent of v will be u
            parent[v] = u; 

            DFS(v,dist,low,parent,bridges);

            low[u] = min(low[u],low[v]);
            
            if(low[v] > dist[u]){ //if low of v is greater than dist of u , it means there is critical cinnections
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
    
    
unordered_map<int, vector <int> > adj;

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    
    //make adjacencey list
    for(auto i:connections){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    //store edges that are bridges
    vector<vector<int>> bridges;

    vector<int> dist(n,-1); //distance array
    vector<int> low(n,-1); //low distance array
    vector<int> parent(n,-1); //parent arrya to save parent of each node
    
     //go to each node
    for(int i =0;i<n;i++){
         //if not visited
        if(dist[i] == -1){
            DFS(i,dist,low,parent,bridges);
        }
    }
    return bridges;
}

//========================Floyd Warshal==============================================================

// to find shortest distance between every pair in matrix(can be a adjecency list of graph)
// if there is not connection between two node, its distance given is -1(if given INF, remove OR condition)
// Tc(n^3)
void shortest_distance(vector<vector<int>>&matrix){
    int n = matrix.size();

    for(int k =0;k<n;k++){
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){

                // if shortest path contains k as intermediate node
                if(((matrix[i][j] > (matrix[i][k] + matrix[k][j]))||(matrix[i][j] == -1))&&(matrix[i][k]!=-1 && matrix[k][j]!=-1)){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }

            }
        }
    }
}



//==================================Priority queue with comparator===
//not tested yet

class A{
public:
    int a; int b;
};

int main(){
    priority_queue<int> x; //max heap

    //lambda function
    auto compare = [](A &x, A &y){
        return x.a < y.a;
    }; 

    priority_queue<A, vector<A>>, decltype(compare) > pq(compare);
    pq.push({1,5});
    .
    .

    .
    while(!pq.empty()){
        cout<<pq.top().a << pq.top().b<<endl;
        pq.pop();
    }
}

//========================================Hamiltonian cycle detection============

bool helper(int s,int count,int n,vector<vector<int>> &graph, vector<int>& vis){
        
    //if all vertex are visited then true
    // if(count == n){
    //     return true;
    // }
    int sum =1;
    for(auto p:vis){
        sum += p;
    }
    // cout<<sum<<endl;
    if(sum == n){
        return true;
    }
    
    
    //mark s as visited
    vis[s] = 1;
    
    //check all neight
    for(auto neig: graph[s]){
        if(vis[neig]==0){
            if(helper(neig,count+1,n,graph,vis)){
                return true;
            }
            
        }
    }
    
    //backtrack
    vis[s] = 0;
    
    return false;
}


bool check(int N,int M,vector<vector<int>> Edges)
{
    // code here
    vector<vector<int>> graph(N+1,vector<int>());
    vector<int> vis(N+1,0);
    for(auto e: Edges){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    //to count number of visited vertex till eachnode
    int count =1;
    
    //hamiltoniaon cycle can start at any vertex
    for(int i =1;i<=N;i++){
        if(helper(i,count,N,graph,vis)){
            return true;
        }
    }
    return false;
}

//==================================================Sudoku solver(backtracking) ==========================
bool issafe(int x,int y,int c, int grid[N][N]){
        
    //row
    for(int i=0;i<N;i++){
        if(grid[i][y] == c){
            return false;
        }
    }
    
    //column
    for(int i=0;i<N;i++){
        if(grid[x][i] == c){
            return false;
        }
    }
    
    //subgrid 3X3
    int left = x/3;
    left *=3;
    int up = y/3;
    up *=3;
    for(int i = left;i< left+3;i++){
        for(int j = up; j< up+3; j++){
            if(i == x && j== y){
                continue;
            }
            if(grid[i][j] == c){
                return false;
            }
        }
    }
    return true;
}

bool helper(int x,int y, int grid[N][N]){
    
    //if we comleted all the rows
    if(x==N){
        return true;
    }
    
    //if we completed all columns of xth row
    if(y==N){
        
        //move to next row,0th column
        return helper(x+1,0,grid);
    }
    
    
    //if it is already filled 
    if(grid[x][y] !=0){
        
        //go to next column
        return helper(x,y+1,grid);
        // return;
    }
    
    
    //try all numbers from 1 to 9
    for(int c = 1;c<10;c++){
        
        //if safe to add
        if(issafe(x,y,c,grid)){
            
            //fill
            grid[x][y] = c;
            
            //go to next col
            if(helper(x,y+1,grid)){
                return true;
            }
            
            //bcaktrack
            grid[x][y] = 0;
        }
    }
    
    
    return false;
}


//Function to find a solved Sudoku. 
bool SolveSudoku(int grid[N][N])  
{ 
    return helper(0,0,grid);
}

//Function to print grids of the Sudoku.
void printGrid (int grid[N][N]) 
{
    // Your code here 
    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
    }
}

//============================= Find if there is cycle in undirected graph=============
bool dfs(int s, vector<vector<int>>& graph, vector<int>& vis, int parent){
    vis[s] = 1;
    // cout<<s<<"->"<<parent<<endl;
    for(auto neigh: graph[s]){

        //if nighbour is tha parent then this is not a loop (this only contains one edge)
        if(neigh == parent){
            continue;
        }

        //if node is already visited
        if(vis[neigh]==1){

            //there is a cycle
            return 1;
        }
        else{
            if(dfs(neigh,graph,vis,s)){
                return 1;
            }
        }
    }
    // vis[s]=0;
    return 0;
}


int Solution::solve(int A, vector<vector<int> > &B) {
    int n =A;
    vector<vector<int>> graph(n+1,vector<int>());

    //make graph
    for(auto e: B){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    //vis array (nodes starting from 1)
    vector<int> vis(n+1,0);
    
    for(int i =1;i<=n;i++){

        //important
        fill(vis.begin(),vis.end(),0);

        //parent is send
        if(dfs(i,graph,vis,-1)){

            return 1;
        }
    }
    return 0;
    
}
//======================find if there is cycle in directed graph=====================================================

bool dfs(int s, vector<vector<int>>& g, vector<int> &vis){
    vis[s] =1;
    for(auto nb: g[s]){
        if(vis[nb]){
            return true;
        }
        else{
            if(dfs(nb,g,vis)){
                return true;
            }
        }
    }
    vis[s] =0;  //importantt
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    
    int n =A;
    vector<vector<int>> g(n+1,vector<int>());
    for(auto e: B){
        g[e[0]].push_back(e[1]);  //**
    }
    vector<int> vis(n+1,0);
    
    for(int i =1;i<=n;i++){
        fill(vis.begin(),vis.end(),0);
        if(dfs(i,g,vis)){
            return true;
        }
    }
    return false;
}

// -----------------------------method 2 (comonly used to detect cycle in directed graph(as color white, grey, black))------------------------------
int dfs(int src, vector<vector<int>> &g, vector<int> &vis){
    
    //visiting state
    vis[src] =1;
    for(auto n:g[src]){
        
        //not visited yet
        if(vis[n] == 0){
            
            //if loop inside dfs
            if(dfs(n,g,vis)){
                return 1;
            }
        }
        
        //if neighbour is already in visiting state, 
        else if(vis[n]==1){
            
            //there is a loop
            return 1;
        }
    }
    
    //completely visited src,
    vis[src]=2;
    
    //hence no loop
    return 0;
}


int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    //vis = 0 not visited
    //vis = 1 in visited state
    //vis = 2 already visited with no loop
    vector<int> vis(A+1,0);
    vector<vector<int>> g(A+1,vector<int>());
    for(int i =0;i<B.size();i++){
        g[B[i]].push_back(C[i]);
    }
    for(int i =1;i<=A;i++){
        if(vis[i]==0){
            
            //if there is  a loop in dfs
            if(dfs(i,g,vis)){
            
                return 0;
            }
        }
    }
    return 1;
}


//==============================TOPO-SORT (Using DFS)==============================

// It means linear ordering of vertices such that there is an edge u->v, u appears before v in the ordering.
//Toposort(my understanding) - an array where all nieghbours of ith element are ahead of ith position in array
//Topological Sorting for a graph is not possible if the graph is not a DAG(Directed Acyclic Graph)




void dfs(int src, vector<int> adj[], vector<int> &vis, stack<int> &st){
    vis[src] =1;
    for(auto neig:adj[src]){
        if(!vis[neig]){
            dfs(neig,adj,vis,st);
        }
    }

    //Last element in dfs will be pushed first, bcs it can not reach more node ahead of it
    st.push(src);
}

//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    int n = V;
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }
    vector<int> v;
    
    //reverse the stack
    while(st.size()>0){
        v.push_back(st.top());
        st.pop();
    }
    return v;
}
//TC - O(V+E)

//====================Toposort Using BFS(course scheduler)-=======================

//p[0] is dependent on p[1];
//p[0] ----> p[1] in graph

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    int n = numCourses;

    vector<int> indeg(n,0);

    //graph
    map<int,vector<int>> mp;


    //make graph with indegree
    for(auto p:prerequisites){
        indeg[p[1]]++;
        mp[p[0]].push_back(p[1]);
    }


    queue<int> q;

    //result saving
    vector<int> topo;

    //if indegree is 0, start topo there(higest level)
    for(int i =0;i<n;i++){
        if(indeg[i]==0){
            topo.push_back(i);
            q.push(i);
        }
    }

    //count
    int pre =0;

    //(if pre != n, means pre <n , means some nodes do not have 0 indegree, it means that node can't be reached)

    //to every node
    while(q.size()){
        int f = q.front();
        q.pop();
        pre++;
        for(auto e: mp[f]){

            //if that node can be reached
            if(--indeg[e]==0){
                topo.push_back(i);
                q.push(e);
            }
        }    
    }

    //loop in the graph, so no toposort (toposort exist only is pre == n)**imp
    if(pre!=n){
        //all nodes can not be reached
        return {}
    }

    //reverse the topo order
    reverse(topo.begin(),topo.end());
    return topo;
}
