Given the root of a binary tree, return whether its height is balanced. That is, for every node in the tree, the absolute difference of the height of its left subtree and the height of its right subtree is 0 or 1.

Constraints

    n ≤ 100,000 where n is the number of nodes in root

Example 1
Input
Visualize

root =

1

4

12
Output

false

Explanation

This is false since the root's right subtree has height of 2, and left has height of 0.
Example 2
Input
Visualize

root =

1

0

4

12
Output

true

//code
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

int solveutil(Tree* n1,bool &flag)
{
  if(flag==0)
  return -1;
  if(n1==NULL)
  return 1;

  int lh=1+solveutil(n1->left,flag);
  int rh=1+solveutil(n1->right,flag);

  if(abs(lh-rh)>1)
  {
      flag=0;
  }

return max(lh,rh);

} 
bool solve(Tree* root) {

 bool flag=1;
 solveutil(root,flag);

 return flag;   
}
