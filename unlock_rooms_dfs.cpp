You are given a two-dimensional list of integers rooms. Each index i in rooms represents a room and rooms[i] represents different keys to unlock other rooms.

You are currently in an unlocked room 0 and every other room is locked. Given you can move freely between unlocked rooms, return whether you can unlock every room.

Constraints

    n, m ≤ 250 where n and m are the number of rows and columns in rooms.

Example 1
Input

rooms = [
    [1, 3],
    [2],
    [0],
    []
]

Output

true

Explanation

We start off at room 0 and can go to room 1 with its key. From room 1 we can go to room 2. Then, we can go back to room 0 and go to room 3.

//code
void dfsutil(vector<vector<int>>& rooms,vector<int> &vis,int u)
{
if(vis[u])
return ;
vis[u]=1;

for(int i=0;i<rooms[u].size();i++)
{
    int unew=rooms[u][i];
    if(!vis[unew]){
    dfsutil(rooms,vis,unew);
    }
}
}



bool solve(vector<vector<int>>& rooms) {
    
 
 int n=rooms.size();

 int i,j;
vector<int> vis(n,0);
vis[0]=1;
 for(i=0;i<rooms[0].size();i++)
 {
     int u=rooms[0][i];
     dfsutil(rooms,vis,u);
 }


for(i=0;i<n;i++)
{
    if(!vis[i])
    return false;
}

return true;
}
