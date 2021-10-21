Given an undirected graph represented as an adjacency list, return whether the graph is bipartite.

Constraints

    n, m ≤ 250 where n and m are the number of rows and columns in graph

Example 1
Input
Visualize

graph =

0

1
Output

true

Explanation

This is bipartite since the node 1 can belong in set A and node 2 can belong in set B. Then the edges 0 -> 1 and 1 -> 0 has one node in A and one node in B
Example 2
Input
Visualize

graph =

0

1

2

3
Output

true

Explanation

0 and 1 can belong in set A and 2 and 3 can belong in set B.
Example 3
Input
Visualize

graph =

0

1

2

3
Output

false

Explanation

No matter how the nodes are partitioned, an edge will belong to the same set.
//https://binarysearch.com/problems/Bipartite-Graph
  
  //code
  bool solve(vector<vector<int>>& adj) {
    int n=adj.size();
  vector<int> cl(n,0);
  queue<int> q1;
vector<bool> vis(n,0);
   
     for(int k=0;k<int(adj.size());k++){
         if(vis[k]) //checking for disconnect components of graphif its not covered in prev bfs
         continue;
         q1.push(k);
     cl[0]=1;
     while(!q1.empty())//bfs implementation
     {
         int top=q1.front();
         q1.pop();
         if(!vis[top]){
                vis[top]=1;
         for(int i=0;i<adj[top].size();i++)
         {
             int z=adj[top][i];
             if(cl[top]==cl[z])
                return 0;
             if(cl[top]==1)
             cl[z]=2;
             else if(cl[top]==2)
                cl[z]=1;

                q1.push(z);

         }

     }}

     }

  return 1;
    
}
//[[5,4],[2,3],[1,3],[1,2],[5,0],[0,4]]
//[[5],[2,3],[1,3],[1,2],[5],[0,4]]
