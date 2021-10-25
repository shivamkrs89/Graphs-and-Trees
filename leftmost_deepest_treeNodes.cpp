Given a binary tree root, find the value of the deepest node. If there's more than one deepest node, then return the leftmost one.

Constraints

    n ≤ 100,000 where n is the number of nodes in root

Example 1
Input
Visualize

root =

0

5

9

1

3

4

2
Output

4

Explanation

The nodes with values 4 and 2 are tied as deepest. Since 4 is more left, 4 should be returned.
Example 2
Input
Visualize

root =

0

5

9

1

3

2
Output

2

Explanation

The node with value 2 is the deepest.
//https://binarysearch.com/problems/Leftmost-Deepest-Tree-Node
  
  //code
  /**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

 void solveutil(Tree* root,int c,int &maxdepth,int &v)
 {

 if(c>maxdepth)
 {
     maxdepth=c;
     v=root->val;
 }
  
  if(root->left!=NULL)
  {
      solveutil(root->left,c+1,maxdepth,v);
  }
   if(root->right!=NULL)
  {
      solveutil(root->right,c+1,maxdepth,v);
  }
 }
int solve(Tree* root) {
    int c=0,md=0;
    int v=root->val;
    solveutil(root,c,md,v);
    return v;
}
