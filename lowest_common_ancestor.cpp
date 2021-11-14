Given a Binary Tree with all unique values and two nodes value n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them is present. 

Example 1:

Input:
n1 = 2 , n2 =  3
     1
   /  \
  2    3
Output: 1
Explanation:
LCA of 2 and 3 is 1.
Example 2:

Input:
n1 = 3 , n2 = 4
         5
        /
       2
     /  \
    3    4
Output: 2
Explanation: 
LCA of 3 and 4 is 2. 
  //code
  /**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void solveutil(Tree* root,int a,int b,bool &fa,bool &fb,bool &flag,int &anc)
{
    if(root==NULL)
    return ;
   if(flag ||(fa && fb ))
   return ;
    if(root->val==a)
    {fa=1;return;}

    if(root->val==b)
    {
        fb=1;return ;
    }

    solveutil(root->left,a,b,fa,fb,flag,anc);
    solveutil(root->right,a,b,fa,fb,flag,anc);
if(!fa && fb==1 && root->val==a)
{
    fa=1;
    return ;
}
if(!fb && fa && root->val==b)
{
    fb=1;
    return ;
}

if(fa && fb & !flag)
{
  flag=1;  
  anc=root->val;
}


}

int solve(Tree* root, int a, int b) {
    bool fa=0,fb=0,flag=0;
    int anc;
    if(root->val==a)
    {
        return a;
    }
     if(root->val==b)
    {
        return b;
    }

    solveutil(root->left,a,b,fa,fb,flag,anc);
    solveutil(root->right,a,b,fa,fb,flag,anc);
    
    if(fa && fb & !flag)
{
  flag=1;  
  anc=root->val;
}
    if(!flag)
    {
        if(fa==1)
        return a;
        else
        return b;
    }
    return anc;
}
