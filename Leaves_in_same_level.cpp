Given a binary tree root, return whether all leaves are at the same level.

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root =
3

4

1

2

0

Output
true
Explanation
Leaves 2 and 0 are on the same level.

Example 2
Input
Visualize
root =
1

2

3

4

Output
false
Explanation
Leaves 2 and 4 are on different levels.
  
  //code
  
  /**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

 void solveutil(Tree* root,int h,int &lh,bool &flag)
 {

     if(!flag || root==NULL)
     return ;
     h++;
     if(root->left==NULL && root->right==NULL)
     {
         if(lh==-1)
         {
             lh=h;
         }
         else
         {
             if(lh!=h)
             {
                 flag=false;
             }
         }
         return ;
     }

     solveutil(root->left,h,lh,flag);
     solveutil(root->right,h,lh,flag);
 }
bool solve(Tree* root) {

    int lh=-1,h=0;
    bool flag=1;
    solveutil(root,h,lh,flag);
    
    return flag;
}
