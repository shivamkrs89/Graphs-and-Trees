Given a two-dimensional integer matrix of 1s and 0s, return the number of distinct "islands" in the matrix. A 1 represents land and 0 represents water, so an island is a group of 1s that are neighboring whose perimeter is surrounded by water. Two islands are distinct if their shapes are different.

Constraints

    n, m ≤ 100 where n and m are the number of rows and columns in matrix

Example 1
Input

matrix = [
    [1, 0, 0, 0, 0],
    [0, 0, 1, 1, 0],
    [0, 1, 1, 0, 0],
    [0, 0, 0, 0, 0],
    [1, 1, 0, 1, 1],
    [1, 1, 0, 1, 1]
]

Output

3

Explanation

This matrix has 4 islands, but only 3 distinct islands since the islands at the bottom are identical.
//code
  bool check(int i,int j,int n,int m)
{
    return i<n && j<m && i>=0 && j>=0?1:0;
}



string dfs(int i,int j,vector<vector<int>>& matrix, vector<vector<bool>> &vis)
{
    vis[i][j]=1;
    int n=matrix.size();
    int m=matrix[0].size();
    string s1="";
if(check(i+1,j,n,m) && matrix[i+1][j]==1 && !vis[i+1][j])
{
    s1+=("D");
}
if(check(i,j+1,n,m) && matrix[i][j+1]==1 && !vis[i][j+1])
{
    s1+=("R");
}
if(check(i-1,j,n,m) && matrix[i-1][j]==1  && !vis[i-1][j])
{
     s1+=("U");
}
 if(check(i,j-1,n,m) && matrix[i][j-1]==1 && !vis[i][j-1])
{
   
    s1+=("L");
}
if(check(i+1,j,n,m) && matrix[i+1][j]==1 && !vis[i+1][j])
{
    s1+=(dfs(i+1,j,matrix,vis));
}
else
s1+="nd";
if(check(i,j+1,n,m) && matrix[i][j+1]==1 && !vis[i][j+1])
{
    s1+=(dfs(i,j+1,matrix,vis));
}
else
s1+="nr";
if(check(i-1,j,n,m) && matrix[i-1][j]==1  && !vis[i-1][j])
{
     s1+=(dfs(i-1,j,matrix,vis));
}
else
s1+="nu";

 if(check(i,j-1,n,m) && matrix[i][j-1]==1 && !vis[i][j-1])
{
   
    s1+=(dfs(i,j-1,matrix,vis));
}
else
s1+="nl";
return s1;
}



int solve(vector<vector<int>>& matrix) {
    int n=matrix.size();
    if(n==0)
    return 0;
    int m=matrix[0].size();
    int i,j;
   vector<vector<bool>> vis(n,vector<bool>(m,0));
  unordered_set<string> islands;
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           if(matrix[i][j]==1 && vis[i][j]==0)
           {
               
               string s1=dfs(i,j,matrix,vis);
               cout<<s1<<'\n';
               islands.insert(s1);
           }

       }
   }

   return islands.size();
}

//[[0,1,0,1,1],[1,0,0,1,0],[1,1,0,0,0]] 3
