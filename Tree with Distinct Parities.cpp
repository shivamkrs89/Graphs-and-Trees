Given a binary tree root, return the number of perfect nodes. A perfect node has two properties:

    Has both children
    The sum of one subtree is even and the sum of the other subtree is odd

Constraints

    0 ≤ n ≤ 100,000 where n is the number of nodes in root

Example 1
Input
Visualize

root =

1

5

3

4

7
Output

2

Explanation

Nodes 1 and 3 meet the criteria.
Example 2
Input
Visualize

root =

1

2

3
Output

0

Explanation

No node has both a left and a right child.
   // https://binarysearch.com/problems/Tree-with-Distinct-Parities
      
      /**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

 int solveutil(Tree* root,int &count)
 {
     if(root==NULL)
     {
      return 0;
     }
     int lsum=0,rsum=0;
       lsum=solveutil(root->left,count);
       rsum=solveutil(root->right,count);
     if(root->left!=NULL && root->right!=NULL){
         if(lsum%2==0 ^ rsum%2==0)
         count++;
     }

     return lsum+rsum+root->val;
     

 }
int solve(Tree* root) {
    int count=0;
    solveutil(root,count);
    return count;
}
