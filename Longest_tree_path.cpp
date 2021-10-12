Given a binary tree root, return the longest path between any two nodes in the tree.

Constraints

    n ≤ 100,000 where n is the number of nodes in root

Example 1
Input
Visualize

root =

0

1

2

3

0

4
Output

5

Explanation

A longest path is [1, 0, 2, 3, 4]
Example 2
Input
Visualize

root =

0

2

3

0

4

6

7
Output

6

Explanation

A longest path is [4, 3, 2, 0, 6, 7]
//code
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int solveutil(Tree* root,int &mx)
{
if(root==NULL)
return 0;

int lpath=solveutil(root->left,mx); 
int rpath=solveutil(root->right,mx);


mx=max(mx,lpath+rpath+1);

return 1+max(lpath,rpath);
}


int solve(Tree* root) {
    int mx=0;
    int x=solveutil(root,mx);   
    return mx;
}
