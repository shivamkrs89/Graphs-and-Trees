You are given a two-dimensional integer matrix representing a forest where a cell is:

    0 if it's empty
    1 if it's a tree
    2 if it's a tree on fire

Every day, a tree catches fire if there is an adjacent (top, down, left, right) tree that's also on fire. Return the number of days it would take for every tree to be on fire. If it's not possible, return -1.

Constraints

    0 ≤ n * m ≤ 200,000 where n and m are the number of rows and columns in matrix

Example 1
Input

matrix = [
    [1, 1, 1],
    [1, 2, 1],
    [1, 1, 1]
]

Output

2

Explanation

On the first day fire will spread to everywhere except the corner trees and then the next day they will spread to the corner trees.
Example 2
Input

matrix = [
    [1, 1, 1],
    [0, 0, 0],
    [1, 2, 1]
]

Output

-1

Explanation

Fire on bottom row can't move across the middle row because it's empty.
//case
  //[[2,2],[1,1],[1,1],[2,2]]
  
  void bfs(int i, int j, vector<vector<int>>& matrix, queue<pair<int, int>>& q1) {
    int n = matrix.size();
    int m = matrix[0].size();
 //    cout<<i<<' '<<j<<'\n'; //<<h<<' '<<mh<<'

    if (i - 1 >= 0 && matrix[i - 1][j] == 1) {
        matrix[i - 1][j] = 2;
        q1.push({i - 1, j});
        // bfs(i-1,j,matrix,h+1,mh);
    }
    if (j - 1 >= 0 && matrix[i][j - 1] == 1) {
        matrix[i][j - 1] = 2;
        q1.push({i, j - 1});
        // bfs(i,j-1,matrix,h+1,mh);
    }
    if (i + 1 < n && matrix[i + 1][j] == 1) {
        matrix[i + 1][j] = 2;
        q1.push({i + 1, j});
        // bfs(i+1,j,matrix,h+1,mh);
    }
    if (j + 1 < m && matrix[i][j + 1] == 1) {
        matrix[i][j + 1] = 2;
        q1.push({i, j + 1});
        // bfs(i,j+1,matrix,h+1,mh);
    }
}
//myltisource bfs 

int solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if(n==0)
    return 0;
    int m = matrix[0].size();
    
    queue<pair<int, int>> fires;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (matrix[i][j] == 2) {
                fires.push({i, j});
            }
        }
    }
    int count = 0;
    queue<pair<int, int>> q1;
   
    while (!fires.empty()) {
        pair<int, int> p1;
       
        while (!fires.empty()) {//emptying current queue of vertices and pushing next queue by another name
            p1 = fires.front();
            fires.pop();
            i = p1.first, j = p1.second;
            bfs(i, j, matrix, q1);
        }
         if(!q1.empty())//if another queue exist it means other level exist
         count++;
        while (!q1.empty()) {//making fires=q1 again for next iteration
            fires.push(q1.front());
            q1.pop();
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                return -1;
            }
        }
    }

    return count;
}
