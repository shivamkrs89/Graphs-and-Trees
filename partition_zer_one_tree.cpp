You are given a binary tree root containing values 0, 1 and 2. The root has at least one 0 node and one 1 node. Consider an operation where we delete an edge in the tree and the tree becomes disjoint with two trees.

Return the number of ways we can delete one edge such that none of the two trees contain both a 0 node and a 1 node.

Constraints

    n ≤ 100,000 where n is the number of nodes in root

Example 1
Input
Visualize

root =

0

0

2

1

1
Output

1

Explanation

We can only delete the 0 to 2 edge.
https://binarysearch.com/problems/Partition-Zero-One-Trees

//code
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void count(Tree* root,int &c0,int &c1)
{
    if(root==NULL)
    return ;
    if(root->val==0)
    c0++;
    if(root->val==1)
    c1++;

    count(root->left,c0,c1);
    count(root->right,c0,c1);
} 
vector<int> partition(Tree* root,int &count,int c0,int c1)
{
   
      if(root==NULL)
      return {0,0} ;
      int val=root->val;
       int n0=0,n1=0;   
     if(root->val==0)
     n0++;
     if(root->val==1)
     n1++;
     if(root->left==NULL && root->right==NULL)
     return {n0,n1};
     vector<int> vl=partition(root->left,count,c0,c1);
   
     vector<int> vr=partition(root->right,count,c0,c1);
        int zero=vl[0],one=vl[1];
        //cout<<zero<<' '<<one<<'\n';
     if((zero==c0 && one==0)||(one==c1 && zero==0))//checking for zer,ones in left
     count++;
     
      zero=vr[0],one=vr[1];
     if((zero==c0 && one==0)||(one==c1 && zero==0)) //checking for zer,ones in right
     count++;

   
     
     
      zero=vl[0]+vr[0]+n0;
      one=vl[1]+vr[1]+n1;
     return {zero,one};//returning total zeros so far from bottom


}

int solve(Tree* root) {
    int n0=0,n1=0,c0=0,c1=0;
    count(root,c0,c1);
    int sets=0;
  
   vector<int> vx=partition(root,sets,c0,c1); 
   return sets;
}

//case
// /[0, [0, null, null], [0, [null, null], [0, null, null]]] 1
// [2, [0, null, null], [2, [2, null, null], [1, null, null]]] 3
// [1, [2, [0, null, null], null], null] 2
//[0, [0, null, null], [2, null, [1, null, null]]] 2
