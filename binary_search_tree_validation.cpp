Given a binary tree root, return whether it's a binary search tree. A binary tree node is a binary search tree if :

    All nodes on its left subtree are smaller than node.val
    All nodes on its right subtree are bigger than node.val
    All nodes hold the these properties.

Constraint

    n ≤ 100,000 where n is the number of nodes in root

Example 1
Input
Visualize

root =

3

2

9

7

12

4

8
Output

true

Example 2
Input
Visualize

root =

3

1

5

4

6

7
Output

false

Explanation

This is not a binary search tree because the 7 is not smaller than 5.

  
  //code
  /**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

bool validate(Tree* root,long long int low_lim,long long int hi_lim)
{
    if(root->val<=low_lim || root->val>=hi_lim)
    return 0;
    bool b_left=1,b_right=1;
   if(root->left!=NULL)
    b_left= validate(root->left,low_lim,root->val);
    if(root->right!=NULL)
    b_right= validate(root->right,root->val,hi_lim);

    return b_left && b_right;
}


bool solve(Tree* root) {
    long long int low_lim=-5147483648;
    long long int hi_lim=5147483648;
   // cout<<hi_lim<<' '<<low_lim<<'\n';
if(root==NULL)
return 1;
    return validate(root,low_lim,hi_lim);

}
